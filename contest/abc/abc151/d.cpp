#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << endl;
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// stringの数字をint型にしてアスキーコードになったら -48する
// 切り上げ　ceil(a)

vector<int> next_y = {-1,1,0,0};
vector<int> next_x = {0,0,-1,1};

//h : 行 w : 列
ll h, w;
vector<vector<string>> vec(h, vector<string>(w));


int main() {
    cin >> h >> w;
    vec.resize(h, vector<string>(w));

    //グリッドの読み込み
    string s;
    rep(i,h){
        cin >> s;
        rep(j,w){
            vec.at(i).at(j) = s[j];
        }
    }

    ll ans = 0;
    rep(y,h){
        rep(x,w){
            if(vec[y][x] == "#"){
                continue;
            }
            //////////////////////////////////////
            //BFSの準備
            //全マスを未訪問(-1)に初期化
            vector<vector<ll>> dist(h, vector<ll>(w, -1));
            //queはpairで作る
            queue< pair<ll,ll> > que;
            //0-1bfsならdequeにして、pushとpopに_frontか_backを付ける
            //deque< pair<ll,ll> > que;

            //各マスからスタートとする
            dist[y][x] = 0;//
            que.push(make_pair(y,x));

            /////////////////////////////////
            //ここからBFS開始
            while(!que.empty()){
                pair<ll,ll> now_pos = que.front();
                ll now_pos_y = now_pos.first;
                ll now_pos_x = now_pos.second;
                que.pop();

                //上下左右いけるか
                rep(i,4){
                    //次に行くマス
                    ll next_pos_y = now_pos_y + next_y.at(i);
                    ll next_pos_x = now_pos_x + next_x.at(i);
                    
                    //場外なら何もしない
                    if(next_pos_x < 0 || next_pos_x >= w || next_pos_y < 0 || next_pos_y >= h){
                        continue;
                    }

                    
                    //壁なら何もしない
                    if(vec[next_pos_y][next_pos_x] == "#"){
                        continue;
                    }
                    
                    
                    //既に訪問済みなら何もしない
                    if(dist[next_pos_y][next_pos_x] != -1){
                        continue;
                    }

                    //now_posから訪問できるノードをqueに追加
                    dist[next_pos_y][next_pos_x] = dist[now_pos_y][now_pos_x] + 1;
                    que.push(make_pair(next_pos_y,next_pos_x));

                }
            }

            rep(i,h){
                rep(j,w){
                    if(ans < dist[i][j]){
                        ans = dist[i][j];
                    }
                }
            }   

        }
    }

    cout << ans << endl;

    
    

}
