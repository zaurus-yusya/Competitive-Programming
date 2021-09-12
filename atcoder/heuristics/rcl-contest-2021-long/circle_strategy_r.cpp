#include <bits/stdc++.h>

using namespace std;

//144304164

//これ以降の日にちでは買わない
int x_day = 860;

//下右上左
const int DR[4] = {1, 0, -1, 0}; 
const int DC[4] = {0, 1, 0, -1};

//渦巻き戦略
int now_r = 6, now_c = 8; //1マス上を初期位置としておく（番兵的な）
int dir = 0; //次に進む向き
int dir_now = 0; //次に進むマスがdir_masu[dir_now]マス
int dir_cnt = 0; //今何マス進んだ

//const vector<int> dir_masu = {3, 3, 5, 6, 8, 9, 11, 12, 14, 15}; //進むマス
//const vector<int> dir_masu = {3, 3, 5, 6, 8, 9, 8}; //進むマス
vector<int> dir_masu = {9, 9, 8, 6, 5, 3, 2}; //進むマス

//移動するノードを最初に買ったノードに固定する。そのマスは下記変数で管理
int R = 0, C = 0;

//node classを作成
struct Node {
    int r;
    int c;
};

struct Vegetable {
    int r, c, s, e, v, id;
    Vegetable(int r_, int c_, int s_, int e_, int v_, int id_)
     : r(r_), c(c_), s(s_), e(e_), v(v_), id(id_) {
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
    vector<vector<int>> vege_id; //野菜のIDを管理
    int num_machine;
    int next_price;
    int money;

    //収穫された野菜のID
    set<int> st;

    //渦巻き戦略
    int circle_r = 7, circle_c = 8; //渦巻きの初期位置
    

    Game() : num_machine(0), next_price(1), money(1) {
        has_machine.assign(N, vector<int>(N, 0));
        vege_values.assign(N, vector<int>(N, 0));
        vege_id.assign(N, vector<int>(N, 0));
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
            vege_id[vege.r][vege.c] = vege.id;
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
                    st.insert(vege_id[i][j]); vege_id[i][j] = 0; //野菜のIDを管理
                }
            }
        }
        // disappear
        for (const Vegetable& vege : veges_end[day]) {
            vege_values[vege.r][vege.c] = 0;
            vege_id[vege.r][vege.c] = 0;
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

    //今の金額でいくつmachineが買えるかを返す
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

    //最も稼げる、マシンが置かれていないnodeの位置を返す関数
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

        return {ok_r, ok_c};
    }

    //距離2の点でその日以降最も稼げる点のマス
    Node calc_most_earn_place3(int day){

        //day以降に出てくるコストの合計をマスごとに計算
        vector<vector<int>> sum_future_veges(N, vector<int>(N, 0));
        for (int i = day; i < T; i++) {
            for (const Vegetable& vege : veges_end[i]) { //終了日がday以降に出てくるもの(day以降に存在するもの)
                if(st.count(vege.id)) continue;
                sum_future_veges[vege.r][vege.c] += vege.v;
            }
        }

        int ok_r = -1, ok_c = -1, ok_v = -1;

        for(int r = 0; r < N; r++){
            for(int c = 0; c < N; c++){
                if(sum_future_veges[r][c] == 0) continue;
                if(has_machine[r][c]) continue;

                bool f = true;
                //距離1の点にマシンがあったらダメ
                for (int dir = 0; dir < 4; dir++) {
                    int nr = r + DR[dir];
                    int nc = c + DC[dir];
                    if (0 <= nr && nr < N && 0 <= nc && nc < N && has_machine[nr][nc]) {
                        f = false;
                    }
                }

                if(!f) continue;

                //距離2の地点にマシンがある個数
                int cnt = 0, res_dir = -1, res_r = -1, res_c = -1;
                for (int dir = 0; dir < 4; dir++) {
                    int nr = r + 2*DR[dir];
                    int nc = c + 2*DC[dir];
                    if (0 <= nr && nr < N && 0 <= nc && nc < N && has_machine[nr][nc]) {
                        cnt++; res_dir = dir; res_r = r; res_c = c;
                    }
                }

                //距離2の地点がある場合、距離1の部分のマスをreturn
                if(cnt > 0 && sum_future_veges[r][c] > ok_v){
                    ok_v = sum_future_veges[r][c];
                    ok_r = r + DR[res_dir]; ok_c = c + DC[res_dir];
                }
            }
        }

        return {ok_r, ok_c};
    }

    Action select_next_action5(int day){
        if(money < next_price || day >= x_day){
            //金がない時、x_day日以降の時は買わない

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

            //渦巻き完成の時、隣接しているマスで最もコストが高いマスを購入
            //todo 渦巻きの角っこ埋めた方がよさそう
            if(dir_now >= dir_masu.size()){
                
                //隣接しているマスでコストが最も高いマスを購入
                //Node most_earn_place = calc_most_earn_place2();
                //距離2の点で最もコスト合計が高いマスを購入
                Node most_earn_place = calc_most_earn_place3(day);
                
                if(most_earn_place.r == -1 && most_earn_place.c == -1){
                    //そのようなマスがない場合最も稼げるマスへ移動

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

            }

            //次に買うマスを調べる
            int next_r = now_r + DR[dir], next_c = now_c + DC[dir];

            if(has_machine[next_r][next_c]){
                //置きたかった場所に既にマシンがある時、最もコストが高いマスを購入。以後そのマスのマシンを移動するマシンとする。
                
                //最もコストの高いマスを返す
                Node most_earn_place = calc_most_earn_place();

                if(most_earn_place.r == -1 && most_earn_place.c == -1){
                    return Action::pass(); //そもそも稼げるマスが無かった場合パス
                }

                //int BEF_R = R, BEF_C = C; //移動前の位置を記憶
                R = most_earn_place.r; C = most_earn_place.c; //購入後の位置を記憶
                
                //マス情報の更新
                now_r = next_r; now_c = next_c;
                dir_cnt += 1;//カウントを進める
                if(dir_cnt == dir_masu[dir_now]){
                    dir_cnt = 0;//カウント0に戻す
                    dir_now += 1;//dir_masuの見る位置変える
                    dir = (dir + 1) % 4;//向き変える
                }
                
                return Action::purchase(R, C);
            }else{
                //マス情報の更新
                now_r = next_r; now_c = next_c;
                dir_cnt += 1;//カウントを進める
                if(dir_cnt == dir_masu[dir_now]){
                    dir_cnt = 0;//カウント0に戻す
                    dir_now += 1;//dir_masuの見る位置変える
                    dir = (dir + 1) % 4;//向き変える
                }

                return Action::purchase(next_r, next_c);
            }

        }
    }

};

int main() {
    cin >> N >> M >> T;
    veges_start.resize(T);
    veges_end.resize(T);
    int id = 1;//野菜にIDをつける 1-indexed
    for (int i = 0; i < M; i++) {
        int r, c, s, e, v;
        cin >> r >> c >> s >> e >> v;
        Vegetable vege(r, c, s, e, v, id); id++;
        veges_start[s].push_back(vege);
        veges_end[e].push_back(vege);
    }

    //出力情報
    int ans_money = -1; //金額が条件良かったら更新する
    vector<Action> ans; //出力する配列

    //複数回条件を変えて実行

    for(int rr = 0; rr <= 5; rr++){
        for(int cc = 1; cc <= 5; cc++){
            //cerr << rr << " " << cc << endl;
            //渦巻きの初期のマスを設定
            now_r = rr; now_c = cc;
            dir = 0; dir_now = 0; dir_cnt = 0;

            Game game;
            vector<Action> actions;
            
            for (int day = 0; day < T; day++) {
                game.appear(day); //野菜出現
                //game.calc_number_of_machine_to_buy(day); //購入できるマシンの数
                Action action = game.select_next_action5(day);
                actions.push_back(action);
                game.simulate(day, action);
            }
            /*
            if(dir_now == dir_masu.size()){
                cerr << rr << " " << cc << " " << game.money << endl;
            }
            */
            
            

            if(game.money > ans_money){
                ans = actions; ans_money = game.money;
            }
        }
    }

    //大きい渦
    dir_masu = {14, 13, 13, 10};
    now_r = 0; now_c = 1;
    dir = 0; dir_now = 0; dir_cnt = 0;
    Game game;
    vector<Action> actions;
    for (int day = 0; day < T; day++) {
        game.appear(day); //野菜出現
        //game.calc_number_of_machine_to_buy(day); //購入できるマシンの数
        Action action = game.select_next_action5(day);
        actions.push_back(action);
        game.simulate(day, action);
    }
    if(game.money > ans_money){
        ans = actions; ans_money = game.money;
    }



    for (const Action& ans : ans) {
        for (int i = 0; i < ans.vs.size(); i++) {
            cout << ans.vs[i] << (i == ans.vs.size() - 1 ? "\n" : " ");
        }
    }
}

