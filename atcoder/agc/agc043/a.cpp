#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

ll h, w;
vector<vector<string>> vec(h, vector<string>(w));

vector<int> next_y = {1,0};
vector<int> next_x = {0,1};

int main() {
    std::cout << std::fixed << std::setprecision(15);
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
    
    vector<vector<ll>> dist(h, vector<ll>(w, -1));
    //queはpairで作る
    deque< pair<ll,ll> > que;
    if(vec[0][0] == "#"){
        dist[0][0] = 1;
    }else{
        dist[0][0] = 0;
    }
    
    que.push_back(make_pair(0,0));

    while(!que.empty()){
        pair<ll,ll> now_pos = que.front();
        ll now_pos_y = now_pos.first;
        ll now_pos_x = now_pos.second;
        que.pop_front();

        //上下左右いけるか
        rep(i,2){
            //次に行くマス
            ll next_pos_y = now_pos_y + next_y.at(i);
            ll next_pos_x = now_pos_x + next_x.at(i);
            
            //場外なら何もしない
            if(next_pos_x < 0 || next_pos_x >= w || next_pos_y < 0 || next_pos_y >= h){
                continue;
            }

            /*
            //壁なら何もしない
            if(vec[next_pos_y][next_pos_x] == "#"){
                continue;
            }
            */
            
            
            //既に訪問済みなら何もしない
            if(dist[next_pos_y][next_pos_x] != -1){
                ll tmp;
                if(vec[next_pos_y][next_pos_x] == "#" && vec[now_pos_y][now_pos_x] != "#"){
                    tmp = dist[now_pos_y][now_pos_x] + 1;
                    //dist[next_pos_y][next_pos_x] = dist[now_pos_y][now_pos_x] + 1;
                }else{
                    tmp = dist[now_pos_y][now_pos_x];
                    //dist[next_pos_y][next_pos_x] = dist[now_pos_y][now_pos_x];
                }

                if(tmp < dist[next_pos_y][next_pos_x]){
                    dist[next_pos_y][next_pos_x] = tmp;
                }
                continue;
            }
            
            

            /*
            //now_posから訪問できるノードをqueに追加
            dist[next_pos_y][next_pos_x] = dist[now_pos_y][now_pos_x] + 1;
            que.push(make_pair(next_pos_y,next_pos_x));
            */

            //now_posから訪問できるノードをqueに追加　壁なら+1
            if(vec[next_pos_y][next_pos_x] == "#" && vec[now_pos_y][now_pos_x] != "#"){
                dist[next_pos_y][next_pos_x] = dist[now_pos_y][now_pos_x] + 1;
                que.push_back(make_pair(next_pos_y,next_pos_x));
            }else{
                dist[next_pos_y][next_pos_x] = dist[now_pos_y][now_pos_x];
                que.push_back(make_pair(next_pos_y,next_pos_x));
            }
        }
    }

    /*
    rep(i,h){
        rep(j,w){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    */
    

    cout << dist[h-1][w-1] << endl;

}