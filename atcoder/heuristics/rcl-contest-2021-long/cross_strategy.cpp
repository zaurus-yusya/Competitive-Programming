#include <bits/stdc++.h>

using namespace std;

//これ以降の日にちでは買わない
#define X_DAY 815
//十字架完成する想定の日にち
#define Y_DAY 750
//隣接する際のコストの閾値
#define Z_COST 75

const int DR[4] = {1, 0, -1, 0};
const int DC[4] = {0, 1, 0, -1};

//建てる場所に優先順位をつけてみた
int tugi = 0;
vector<pair<int, int>> junban;
vector<int> junbanm = {7, 8, 6, 9, 5, 10, 4, 11, 3, 12, 2, 13, 1, 14, 0, 15}; //横に行を作る際の添え字

//移動するノードを最初に買ったノードに固定してみる
int R = 0, C = 0;

//node classを作成
struct Node {
    int r;
    int c;
};

struct Vegetable {
    int r, c, s, e, v;
    Vegetable(int r_, int c_, int s_, int e_, int v_)
     : r(r_), c(c_), s(s_), e(e_), v(v_) {
    }
};

struct Action {
    vector<int> vs;

private:
    explicit Action(const vector<int>& vs_) : vs(vs_) {}

public:
    static Action pass() {
        return Action({-1});
    }

    static Action purchase(int r, int c) {
        return Action({r, c});
    }

    static Action move(int r1, int c1, int r2, int c2) {
        return Action({r1, c1, r2, c2});
    }
};

int N, M, T;
vector<vector<Vegetable>> veges_start; // veges_start[i] : vegetables appear on day i
vector<vector<Vegetable>> veges_end;   // veges_end[i] : vegetables disappear on day i

queue<int> que; //何日か後の計画を建てた時に飛ばす用のque

struct Game {
    vector<vector<int>> has_machine;
    vector<vector<int>> vege_values;
    int num_machine;
    int next_price;
    int money;

    //action5以降どの行と列で十字架作るか
    int cross_r = -1, cross_c = -1, cross_rv = 0, cross_cv = 0;

    Game() : num_machine(0), next_price(1), money(1) {
        has_machine.assign(N, vector<int>(N, 0));
        vege_values.assign(N, vector<int>(N, 0));
    }

    void purchase(int r, int c) {
        assert(!has_machine[r][c]);
        assert(next_price <= money);
        has_machine[r][c] = 1;
        money -= next_price;
        num_machine++;
        next_price = (num_machine + 1) * (num_machine + 1) * (num_machine + 1);
    }

    void move(int r1, int c1, int r2, int c2) {
        assert(has_machine[r1][c1]);
        has_machine[r1][c1] = 0;
        assert(!has_machine[r2][c2]);
        has_machine[r2][c2] = 1;
    }

    void appear(int day){
        for (const Vegetable& vege : veges_start[day]) {
            vege_values[vege.r][vege.c] = vege.v;
        }
    }

    void simulate(int day, const Action& action) {
        // apply
        if (action.vs.size() == 2) {
            purchase(action.vs[0], action.vs[1]);
        } else if (action.vs.size() == 4) {
            move(action.vs[0], action.vs[1], action.vs[2], action.vs[3]);
        }
        // harvest
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (has_machine[i][j] && vege_values[i][j] > 0) {
                    money += vege_values[i][j] * count_connected_machines(i, j);
                    vege_values[i][j] = 0;
                }
            }
        }
        // disappear
        for (const Vegetable& vege : veges_end[day]) {
            vege_values[vege.r][vege.c] = 0;
        }
    }

    int count_connected_machines(int r, int c) {
        vector<pair<int, int>> queue = {{r, c}};
        vector<vector<int>> visited(N, vector<int>(N, 0));
        visited[r][c] = 1;
        int i = 0;
        while (i < queue.size()) {
            int cr = queue[i].first;
            int cc = queue[i].second;
            for (int dir = 0; dir < 4; dir++) {
                int nr = cr + DR[dir];
                int nc = cc + DC[dir];
                if (0 <= nr && nr < N && 0 <= nc && nc < N && has_machine[nr][nc] && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    queue.push_back({nr, nc});
                }
            }
            i++;
        }
        return i;
    }
    //sampleここまで//

    //action5以降 今の金額でいくつmachineが買えるかを返す
    int calc_number_of_machine_to_buy(int day){
        int x_money = money, x_num_machine = num_machine, x_next_price = next_price;
        int cnt = 0;
        while(x_next_price <= x_money){
            x_money -= x_next_price;
            x_num_machine++; cnt++;
            x_next_price = (x_num_machine + 1) * (x_num_machine + 1) * (x_num_machine + 1);
        }
        cerr << "day = " << day << ": " << cnt << " machines can buy." << endl;
        return cnt;
    }

    //action4以降 どの行と列で十字架作るか計算
    void calc_cross_rc(){
        vector<vector<int>> sum_future_veges(N, vector<int>(N, 0));
        //Y_DAY以降に出てくるコストの合計をマスごとに計算
        for (int i = Y_DAY; i < T; i++) {
            for (const Vegetable& vege : veges_end[i]) { //終了日がY_DAY以降に出てくるもの(Y_DAY以降に存在するもの)
                sum_future_veges[vege.r][vege.c] += vege.v;
            }
        }

        //todo rとcが重なる部分がダブルカウントされている
        //行の計算
        //両隣も計算する
        for(int r = 0; r < N; r++){
            int tmp = 0;
            
            for(int c = 0; c < N; c++){
                tmp += sum_future_veges[r][c];
            }
            
            //上
            if(r > 0){
                for(int c = 0; c < N; c++){
                    tmp += sum_future_veges[r-1][c];
                }
            }
            //下
            if(r < N-1){
                for(int c = 0; c < N; c++){
                    tmp += sum_future_veges[r+1][c];
                }
            }

            if(tmp > cross_rv){
                cross_r = r; cross_rv = tmp;
            }
        }

        //列の計算
        //両隣も計算する
        for(int c = 0; c < N; c++){
            int tmp = 0;
            
            for(int r = 0; r < N; r++){
                tmp += sum_future_veges[r][c];
            }
            
            //左
            if(c > 0){
                for(int r = 0; r < N; r++){
                    tmp += sum_future_veges[r][c-1];
                }
            }
            //右
            if(c < N-1){
                for(int r = 0; r < N; r++){
                    tmp += sum_future_veges[r][c+1];
                }
            }

            if(tmp > cross_cv){
                cross_c = c; cross_cv = tmp;
            }
        }

        //junbanm配列の生成
        for(int i = cross_r - 1; i >= 0; i--){
            junbanm.push_back(i);
        }
        for(int i = cross_r + 1; i < N; i++){
            junbanm.push_back(i);
        }

        //junban配列の生成
        for(int i = 0; i < junbanm.size(); i++){
            if(i < 16){
                junban.push_back({cross_r, junbanm[i]});
            }else{
                junban.push_back({junbanm[i], cross_c});
            }
        }
    }


    //action4以降 最も稼げる、マシンが置かれていないnodeの位置を返す関数
    Node calc_most_earn_place(){
        int ok_r = -1, ok_c = -1, ok_v = 0;
        for(int r = 0; r < N; r++){
            for(int c = 0; c < N; c++){
                if(vege_values[r][c] == 0) continue;
                if(has_machine[r][c]) continue;
                int cost = vege_values[r][c] * count_connected_machines(r, c);
                if(cost > ok_v){
                    ok_r = r; ok_c = c; ok_v = cost;
                }
            }
        }
        return {ok_r, ok_c};
    }

    //最も稼げる、マシンが置かれていないマスのうち、隣接しているノードを返す
    Node calc_most_earn_place2(){
        int ok_r = -1, ok_c = -1, ok_v = 0, ok_vege_v = 0;
        for(int r = 0; r < N; r++){
            for(int c = 0; c < N; c++){
                if(vege_values[r][c] == 0) continue;
                if(has_machine[r][c]) continue;
                //隣接チェック
                bool f = false;
                for (int dir = 0; dir < 4; dir++) {
                    int nr = r + DR[dir];
                    int nc = c + DC[dir];
                    if (0 <= nr && nr < N && 0 <= nc && nc < N && has_machine[nr][nc]) {
                        f = true;
                    }
                }
                if(!f) continue; //隣接してなかったらcontinue

                int cost = vege_values[r][c] * count_connected_machines(r, c);
                if(cost > ok_v){
                    ok_r = r; ok_c = c; ok_v = cost; ok_vege_v = vege_values[r][c];
                }
            }
        }

        if(ok_vege_v < Z_COST){
            ok_r = -1; ok_c = -1;
        }

        return {ok_r, ok_c};
    }


    
    Action select_next_action4(int day){
        if(money < next_price || day >= X_DAY){
            //金がない時、X_DAY日以降の時は買わない

            //最もコストの高いマスを返す
            bool f = false;
            if(has_machine[R][C]) {has_machine[R][C] = 0; f = true;} //移動予定のマスは一時的に未購入状態に
            Node most_earn_place = calc_most_earn_place();
            if(f) {has_machine[R][C] = 1;} //移動予定のマスを元に戻す

            if(most_earn_place.r == -1 && most_earn_place.c == -1){
                return Action::pass(); //そもそも稼げるマスが無かった場合パス
            }

            int BEF_R = R, BEF_C = C; //移動前の位置を記憶
            R = most_earn_place.r; C = most_earn_place.c; //移動後の位置を記憶
            return Action::move(BEF_R, BEF_C, R, C);

        }else{
            //マシンを買う金がある

            //最初の1台目だけ最も稼げる場所に買う
            if(num_machine == 0){
                //最もコストの高いマスを返す
                Node most_earn_place = calc_most_earn_place();
                if(most_earn_place.r == -1 && most_earn_place.c == -1){
                    return Action::pass(); //そもそも稼げるマスが無かった場合パス
                }
                R = most_earn_place.r; C = most_earn_place.c; //購入後の位置を記憶
                return Action::purchase(R, C);
            }

            //十字架が完成している時、最も稼げる位置に買う (todo どこか隣接しているマスを買った方が良い？？)
            if(tugi >= junban.size()){
                //隣接しているマスでコストが最も高いマスを購入
                Node most_earn_place = calc_most_earn_place2();
                
                if(most_earn_place.r == -1 && most_earn_place.c == -1){
                    //最も稼げるマスへ移動

                    //最もコストの高いマスを返す
                    bool f = false;
                    if(has_machine[R][C]) {has_machine[R][C] = 0; f = true;} //移動予定のマスは一時的に未購入状態に
                    Node most_earn_place = calc_most_earn_place();
                    if(f) {has_machine[R][C] = 1;} //移動予定のマスを元に戻す

                    if(most_earn_place.r == -1 && most_earn_place.c == -1){
                        return Action::pass(); //そもそも稼げるマスが無かった場合パス
                    }

                    int BEF_R = R, BEF_C = C; //移動前の位置を記憶
                    R = most_earn_place.r; C = most_earn_place.c; //移動後の位置を記憶
                    return Action::move(BEF_R, BEF_C, R, C);
                
                }

                return Action::purchase(most_earn_place.r, most_earn_place.c);

                //R = most_earn_place.r; C = most_earn_place.c; //購入後の位置を記憶
                //return Action::purchase(R, C);
                
            }

            if(has_machine[junban[tugi].first][junban[tugi].second]){
                //置きたかった場所に既にマシンがある時、最もコストが高いマスを購入。以後そのマスのマシンを移動するマシンとする。
                
                //最もコストの高いマスを返す
                Node most_earn_place = calc_most_earn_place();

                if(most_earn_place.r == -1 && most_earn_place.c == -1){
                    return Action::pass(); //そもそも稼げるマスが無かった場合パス
                }

                //int BEF_R = R, BEF_C = C; //移動前の位置を記憶
                R = most_earn_place.r; C = most_earn_place.c; //購入後の位置を記憶
                //return Action::move(BEF_R, BEF_C, R, C);
                tugi++;
                return Action::purchase(R, C);
                
            }else{
                //置きたい場所にマシンが無い場合、置きたい場所を買う
                tugi++;
                return Action::purchase(junban[tugi-1].first, junban[tugi-1].second);
            }

            
        }
    }
    

};

//買うんじゃなくて移動？
//複数買ってる場合、複数個移動することでイケる？

int main() {
    cin >> N >> M >> T;
    veges_start.resize(T);
    veges_end.resize(T);
    for (int i = 0; i < M; i++) {
        int r, c, s, e, v;
        cin >> r >> c >> s >> e >> v;
        Vegetable vege(r, c, s, e, v);
        veges_start[s].push_back(vege);
        veges_end[e].push_back(vege);
    }
    Game game;
    vector<Action> actions;

    //action4 どの列と行を選ぶか計算する
    game.calc_cross_rc();

    for (int day = 0; day < T; day++) {
        game.appear(day); //野菜出現
        //game.calc_number_of_machine_to_buy(day); //購入できるマシンの数
        Action action = game.select_next_action4(day);
        actions.push_back(action);
        game.simulate(day, action);
    }
    for (const Action& action : actions) {
        for (int i = 0; i < action.vs.size(); i++) {
            cout << action.vs[i] << (i == action.vs.size() - 1 ? "\n" : " ");
        }
    }
}

