#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

vector<ll> dr = {-2, 2, 0, 0};
vector<ll> dc = {0, 0, 2, -2};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    
    while(true){
        ll w, h; cin >> w >> h;
        if(h == 0 && w == 0){
            break;
        }
        vector<vector<string>> maze(2*h-1, vector<string>(2*w-1, "."));

        rep(i, 2*h-1){
            if(i % 2 == 0){
                rep(j, w-1){
                    ll tmp; cin >> tmp;
                    if(tmp == 1) maze[i][2*j+1] = "#";
                }
            }else{
                rep(j, w){
                    ll tmp; cin >> tmp;
                    if(tmp == 1) maze[i][2*j] = "#";
                }
            }
        }

        vector<vector<ll>> dist(2*h-1, vector<ll>(2*w-1, -1));
        queue<pair<ll, ll>> que;
        dist[0][0] = 0;
        que.push({0, 0});

        while(!que.empty()){
            pair<ll, ll> now_pos = que.front();
            ll now_row = now_pos.first;
            ll now_col = now_pos.second;
            que.pop();
            rep(i, 4){
                ll next_row = now_row + dr[i];
                ll next_col = now_col + dc[i];

                //場外ならcontinue
                if(next_row < 0 || next_row >= 2*h - 1) continue;
                if(next_col < 0 || next_col >= 2*w - 1) continue;

                //すでに訪れていたらcontinue
                if(dist[next_row][next_col] != -1) continue;

                //壁があったらcontinue
                if(maze[now_row + dr[i]/2][now_col + dc[i]/2] == "#") continue;

                //dist格納,que追加
                dist[next_row][next_col] = dist[now_row][now_col] + 1;
                que.push({next_row, next_col});
            }
        }

        /*
        rep(i, 2*h-1){
            rep(j, 2*w-1){
                cout << dist[i][j] << " ";
            }
            br;
        }
        */

        cout << dist[2*h-2][2*w-2] + 1 << endl;

    }

}