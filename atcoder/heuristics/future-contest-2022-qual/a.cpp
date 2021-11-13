#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << '\n';
using namespace std;
const long long INF = 8e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << ' ';} cerr << '\n';}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << ' ';} cerr << '\n';}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;
const double PI = acos(-1);

#define LOCAL false

int N, M, K, R; 

//タスクに付与する情報
struct TaskInfo{
    int id;
    int sequence; //後続に控えているタスクの数
    int sumd; //タスクの技能レベルの合計
};

//入力受け取り
void input(vector<vector<int>> &D, vector<vector<int>> &G, vector<int> &IND, vector<vector<int>> &Gr, vector<int> &INDr, vector<TaskInfo> &Task){
    rep(i, N){
        int sum = 0;
        rep(j, K){
            cin >> D[i][j]; sum += D[i][j];
        }
        Task[i].id = i;
        Task[i].sumd = sum;
    }
    rep(i, R){ int u, v; cin >> u >> v; u--; v--; G[u].push_back(v); IND[v]++; Gr[v].push_back(u); INDr[u]++;}
}

//入力受け取り(隠れ情報)
void input2(vector<vector<int>> &S, vector<vector<int>> &T){
    rep(i, M) rep(j, K) cin >> S[i][j];
    rep(i, N) rep(j, M) cin >> T[i][j];
}

//タスクのsequenceの計算
void calc_task_sequence(vector<TaskInfo> &Task, vector<vector<int>> &Gr, vector<int> &INDr){
    queue<int> que;
    rep(i, INDr.size()){
        if(INDr[i] == 0) que.push(i);
    }
    while(!que.empty()){
        ll now = que.front(); que.pop();
        for(auto next: Gr[now]){
            Task[next].sequence += Task[now].sequence + 1;
            INDr[next]--;
            if(INDr[next] == 0) que.push(next);
        }
    }
}

//memberにtaskをアサイン
void assign_task(int &member, int &task, vector<pair<int, int>> &output, vector<int> &member_status, vector<int> &task_status, vector<vector<int>> &callback_for_debug, int &DAY, vector<vector<int>> &T){
    member_status[member] = task;
    task_status[task] = member;
    output.push_back({member+1, task+1});
    //LOCALの場合、タスク終了日にメンバーのIDを挿入
    if(LOCAL){
        int task_end_day = DAY + T[task][member] - 1;
        if(task_end_day < 2000) callback_for_debug[task_end_day].push_back(member+1);
    }
}

//outputを出力
void do_output(vector<pair<int, int>> &output){
    cout << output.size();
    for(int i = 0; i < output.size(); i++){
        cout << ' ' << output[i].first << ' ' << output[i].second;
    }
    cout << '\n';
    fflush(stdout);
}



int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> N >> M >> K >> R; // N=1000 タスクの数, M=20 メンバーの数, K=[10, 20] 技能ベクトルの次元, R=[1000, 3000] 依存関係の数
    vector<vector<int>> D(N, vector<int>(K)); // タスクの技能ベクトル (タスクは0-indexed)
    vector<vector<int>> G(N); //タスクの依存関係 (タスクは0-indexed)
    vector<int> IND(N); 
    vector<vector<int>> Gr(N); //タスクの依存関係の逆 (タスクは0-indexed)
    vector<int> INDr(N); 
    vector<TaskInfo> Task(N);
    input(D, G, IND, Gr, INDr, Task); //入力受取

    int finished = 0;

    //隠れ情報の入力
    vector<vector<int>> S(M, vector<int>(K));
    vector<vector<int>> T(N, vector<int>(M));
    if(LOCAL){
        input2(S, T);
    }
    /////////

    //後続タスク量の計算
    calc_task_sequence(Task, Gr, INDr);
    /////////
    
    //後続のタスクが多い方が優先順位高めにする
    auto taskinfo_sort = [](TaskInfo a, TaskInfo b) { 
        if(a.sequence != b.sequence){
            return a.sequence < b.sequence; 
        }
        return a.sumd > b.sumd;
        
    };
    priority_queue<TaskInfo, vector<TaskInfo>, decltype(taskinfo_sort)> pque(taskinfo_sort);
    rep(i, N){
        if(IND[i] == 0) pque.push(Task[i]);
    }
    
    vector<int> task_status(N, -1); // -1: not started, k: assigned member k (0 <= k < M), -2: completed
    vector<int> member_status(M, -1); // -1: not assigned, k: assigned task k (0 <= k < N)
    

    
    vector<vector<int>> callback_for_debug(2000);
    for(int DAY = 0; DAY < 2000; DAY++){

        vector<pair<int, int>> output;

        rep(i, M){
            if(pque.empty()) break;
            int member = i;
            if(member_status[member] == -1){
                //アサイン
                TaskInfo task = pque.top();
                pque.pop();
                assign_task(member, task.id, output, member_status, task_status, callback_for_debug, DAY, T);
            }
        }
        
        //出力
        do_output(output);

        
        //入力受け取り
        if(!LOCAL){
            int x; cin >> x;
            if(x == -1) break;
            for(int i = 0; i < x; i++){
                int m; cin >> m; m--;//メンバーmのタスクが終わった
                int task = member_status[m]; //メンバーmのタスク
                member_status[m] = -1;
                task_status[task] = -2;

                //依存関係の更新
                for(auto next: G[task]){
                    IND[next]--;
                    if(IND[next] == 0){
                        pque.push(Task[next]);
                    }
                }
            }
        }
        

        //LOCALの場合 callbackの処理を実施
        if(LOCAL){
            if(DAY == 2000-1) break;
            int x = callback_for_debug[DAY].size();
            sort(all(callback_for_debug[DAY]));
            for(int j = 0; j < x; j++){
                int m = callback_for_debug[DAY][j];
                m--;
                int task = member_status[m]; //メンバーmのタスク
                member_status[m] = -1;
                task_status[task] = -2;

                //依存関係の更新
                for(auto next: G[task]){
                    IND[next]--;
                    if(IND[next] == 0){
                        pque.push(Task[next]);
                    }
                }
            }

            finished += x;
            if(finished == N){
                ofstream writing_file;
                string filename = "./out/score.txt";
                writing_file.open(filename, ios::app);
                string writing_text = to_string(N + 2000 - DAY - 1);
                writing_file << writing_text << endl;
                writing_file.close();
                break;
            }
        }
    }
    

    return 0;

}

//考察
/*
・タスクの難しさ
・メンバーの有能度
・タスクを終わらせることでできるようになるタスクの数
*/