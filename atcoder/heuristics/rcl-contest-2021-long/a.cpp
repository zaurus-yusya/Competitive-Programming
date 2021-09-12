#include <bits/stdc++.h>

using namespace std;

//144304164

//これ以降の日にちでは買わない
int x_day = 870;

//下左上右に変更（元は下右上左）
const int DR[4] = {1, 0, -1, 0}; 
const int DC[4] = {0, -1, 0, 1};

//距離2の点
const int DDR[8] = {2, 1, 0, -1, -2, -1, 0, 1};
const int DDC[8] = {0, -1, -2, -1, 0, 1, 2, 1};

//渦巻き戦略
int now_r = 6, now_c = 8; //1マス上を初期位置としておく（番兵的な）
int dir = 0; //次に進む向き
int dir_now = 0; //次に進むマスがdir_masu[dir_now]マス
int dir_cnt = 0; //今何マス進んだ

//数日後予測
int predict_day = 50;

//const vector<int> dir_masu = {3, 3, 5, 6, 8, 9, 11, 12, 14, 15}; //進むマス
const vector<int> dir_masu = {3, 3, 5, 6, 8, 9, 8}; //進むマス

//移動するノードを最初に買ったノードに固定する。そのマスは下記変数で管理
int R = 0, C = 0;

//node classを作成
struct Node {
    int r;
    int c;
};

//乱数を返す関数
int random_num(int l, int r){
    // l <= x <= r の乱数を返す
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> distr(l, r);
    return distr(eng);
}

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
    vector<vector<int>> machine_status; //固定マシンと隣接マスのステータス管理
    vector<vector<int>> simu_vege_values; //シミュレーション用
    vector<vector<int>> simu_vege_id; //シミュレーション用

    int num_machine;
    int next_price;
    int money;

    //収穫された野菜のID
    set<int> st;
    set<int> simu_st; //シミュレーション用

    Game() : num_machine(0), next_price(1), money(1) {
        has_machine.assign(N, vector<int>(N, 0));
        vege_values.assign(N, vector<int>(N, 0));
        vege_id.assign(N, vector<int>(N, 0));
        machine_status.assign(N, vector<int>(N, 0)); //買った場所: 2, 隣接マス: 1, 買ってないマス: 0
        simu_vege_values.assign(N, vector<int>(N, 0));
        simu_vege_id.assign(N, vector<int>(N, 0));
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

    //購入時、自身のマスとその上下左右マスのステータスを更新
    void update_machine_status(int p_r, int p_c){
        //自分自身のマスの更新
        machine_status[p_r][p_c] = 2;
        //上下左右マスの更新
        for(int dir = 0; dir < 4; dir++){
            int nr = p_r + DR[dir];
            int nc = p_c + DC[dir];
            if (0 <= nr && nr < N && 0 <= nc && nc < N) {
                machine_status[nr][nc] = max(machine_status[nr][nc], 1); //既に購入済みのマスだったら何もしない。購入されてないマスだったら隣接マスになる。
            }
        }
    }

    Node first_machine_place(){
        
        Node most_earn_place = calc_most_earn_place();
        if(most_earn_place.r == -1 && most_earn_place.c == -1){
            return {-1, -1}; //そもそも稼げるマスが無かった場合パス
        }
        R = most_earn_place.r; C = most_earn_place.c; //購入後の位置を記憶
        return {R, C};
        
    }

    Node second_machine_place(int day){
        vector<vector<int>> sum_future_veges(N, vector<int>(N, 0));
        for (int i = day; i < T; i++) {
            for (const Vegetable& vege : veges_start[i]) {
                sum_future_veges[vege.r][vege.c] += vege.v;
            }
        }

        int ok_r = -1, ok_c = -1, ok_v = 0;
        for(int r = 0; r < N; r++){
            for(int c = 0; c < N; c++){
                int cost = 0;
                //自分自身
                cost += sum_future_veges[r][c];
                //上下左右
                for (int dir = 0; dir < 4; dir++) {
                    int nr = r + DR[dir];
                    int nc = c + DC[dir];
                    if (0 <= nr && nr < N && 0 <= nc && nc < N) {
                        cost += sum_future_veges[nr][nc];
                    }
                }

                if(cost > ok_v){
                    ok_r = r; ok_c = c; ok_v = cost;
                }
            }
        }
        return {ok_r, ok_c};

        /*
        //シミュレーション開始
        simu_vege_values = vege_values;
        //今の日からpredict_dayまでで稼げるマスのコストの合計
        vector<vector<int>> sum_future_veges(N, vector<int>(N, 0));
        //predict_day = (day / 20) + 10;
        for(int i = day; i < (day + predict_day) && i < T; i++){
            //APPEAR
            for (const Vegetable& vege : veges_start[i]) {
                simu_vege_values[vege.r][vege.c] = vege.v;
            }
            //COUNT
            for(int r = 0; r < N; r++){
                for(int c = 0; c < N; c++){
                    if(simu_vege_values[r][c] == 0) continue;
                    sum_future_veges[r][c] += simu_vege_values[r][c];
                    simu_vege_values[r][c] = 0;
                }
            }
            //DISAPPEAR
            for (const Vegetable& vege : veges_end[i]) {
                simu_vege_values[vege.r][vege.c] = 0;
            }
        }

        //マスの評価
        int ok_r = -1, ok_c = -1, ok_v = -1;
        vector<Node> res;
        for(int r = 0; r < N; r++){
            for(int c = 0; c < N; c++){
                int cost = 0;
                if(r == R && c == C) continue;
                //自分自身
                cost += sum_future_veges[r][c];
                //上下左右
                for (int dir = 0; dir < 4; dir++) {
                    int nr = r + DR[dir];
                    int nc = c + DC[dir];
                    if (0 <= nr && nr < N && 0 <= nc && nc < N) {
                        cost += 2 * sum_future_veges[nr][nc];
                    }
                }
                //距離2
                for (int dir = 0; dir < 8; dir++) {
                    int nr = r + DDR[dir];
                    int nc = c + DDC[dir];
                    if (0 <= nr && nr < N && 0 <= nc && nc < N) {
                        cost += 1 * sum_future_veges[nr][nc];
                    }
                }

                if(cost > ok_v){
                    res.clear(); res.push_back({r, c});
                    ok_r = r; ok_c = c; ok_v = cost;
                }else if(cost == ok_v){
                    res.push_back({r, c});
                }
            }
        }

        int num = random_num(0, res.size()-1);
        return {res[num].r, res[num].c};
        */
    }

    Node next_machine_place(int day){
        //シミュレーション開始
        simu_vege_values = vege_values;
        //今の日からpredict_dayまでで稼げるマスのコストの合計
        vector<vector<int>> sum_future_veges(N, vector<int>(N, 0));
        //predict_day = (day / 20) + 10;
        for(int i = day; i < (day + predict_day) && i < T; i++){
            //APPEAR
            for (const Vegetable& vege : veges_start[i]) {
                simu_vege_values[vege.r][vege.c] = vege.v;
            }
            //COUNT
            for(int r = 0; r < N; r++){
                for(int c = 0; c < N; c++){
                    if(simu_vege_values[r][c] == 0) continue;
                    sum_future_veges[r][c] += simu_vege_values[r][c];
                    simu_vege_values[r][c] = 0;
                }
            }
            //DISAPPEAR
            for (const Vegetable& vege : veges_end[i]) {
                simu_vege_values[vege.r][vege.c] = 0;
            }
        }

        //マスの評価
        int ok_r = -1, ok_c = -1, ok_v = -1;
        vector<Node> res;
        for(int r = 0; r < N; r++){
            for(int c = 0; c < N; c++){
                int cost = 0;
                if(r == R && c == C) continue; //移動ノードと被ってたらcontinue
                if(machine_status[r][c] != 1) continue; //隣接マスじゃなかったらcontinue
                //そこに置くことで新たにできる隣接マスを評価
                for(int dir = 0; dir < 4; dir++){
                    int nr = r + DR[dir];
                    int nc = c + DC[dir];
                    if (0 <= nr && nr < N && 0 <= nc && nc < N && machine_status[nr][nc] == 0) {
                        cost += 2 * sum_future_veges[nr][nc];
                    }
                }
                //距離2
                
                for (int dir = 0; dir < 8; dir++) {
                    int nr = r + DDR[dir];
                    int nc = c + DDC[dir];
                    if (0 <= nr && nr < N && 0 <= nc && nc < N && machine_status[nr][nc] == 0) {
                        cost += 1 * sum_future_veges[nr][nc];
                    }
                }
                
                if(cost > ok_v){
                    res.clear(); res.push_back({r, c});
                    ok_r = r; ok_c = c; ok_v = cost;
                }else if(cost == ok_v){
                    res.push_back({r, c});
                }
            }
        }

        int num = random_num(0, res.size()-1);
        //cout << "num " << num << " res.size " << res.size() << endl;
        return {res[num].r, res[num].c};
        //return {ok_r, ok_c};
    }

    Action select_next_action6(int day){

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

            //1台目の時
            if(num_machine == 0){
                Node purchase_place = first_machine_place();
                if(purchase_place.r == -1 && purchase_place.c == -1){
                    return Action::pass();
                }
                R = purchase_place.r; C = purchase_place.c; //購入後の位置を記憶
                return Action::purchase(R, C);
            }

            //2台目の時
            if(num_machine == 1){
                Node purchase_place = second_machine_place(day);
                if(purchase_place.r == -1 && purchase_place.c == -1){
                    return Action::pass();
                }
                update_machine_status(purchase_place.r, purchase_place.c);
                return Action::purchase(purchase_place.r, purchase_place.c);
            }

            //3台目以上の時
            
            
            Node purchase_place = next_machine_place(day);
            if(purchase_place.r == -1 && purchase_place.c == -1){
                return Action::pass();
            }
            update_machine_status(purchase_place.r, purchase_place.c);
            return Action::purchase(purchase_place.r, purchase_place.c);
            
            //return Action::pass();
            

        }

    }

};

int main() {
    auto START = std::chrono::system_clock::now();
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

    while(true){
            int64_t spent_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - START).count();
            if (spent_ms > 1960) break;
            dir = 0; dir_now = 0; dir_cnt = 0;

            Game game;
            vector<Action> actions;
            
            for (int day = 0; day < T; day++) {
                game.appear(day); //野菜出現
                //game.calc_number_of_machine_to_buy(day); //購入できるマシンの数
                int X = random_num(100, 150);
                predict_day = (day + X) / 10 + 10;//predict_dayの計算
                Action action = game.select_next_action6(day);
                actions.push_back(action);
                game.simulate(day, action);
            }

            if(game.money > ans_money){
                ans = actions; ans_money = game.money;
            }
            /*
            for(int r = 0; r < N; r++){
                for(int c = 0; c < N; c++){
                    cout << game.machine_status[r][c] << " ";
                }cout << endl;
            }
            */
    }

    for (const Action& ans : ans) {
        for (int i = 0; i < ans.vs.size(); i++) {
            cout << ans.vs[i] << (i == ans.vs.size() - 1 ? "\n" : " ");
        }
    }
}

