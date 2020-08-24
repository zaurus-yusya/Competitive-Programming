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
ll ceilll(ll a, ll b) {return (a + b-1) / b;}
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll h, w; cin >> h >> w;
    ll ch, cw; cin >> ch >> cw; ch--; cw--;
    ll dh, dw; cin >> dh >> dw; dh--; dw--;

    vector<vector<string>> vec(h, vector<string>(w));
    rep(i, h){
        string s; cin >> s;
        rep(j, w){
            vec[i][j] = s[j];
        }
    }

    vector<vector<ll>> dist(h, vector<ll>(w, -1));
    deque< pair<ll,ll> > que;

    dist[ch][cw] = 0;
    que.push_front(make_pair(ch,cw));

    vector<ll> next_y = {-1,1,0,0};
    vector<ll> next_x = {0,0,-1,1};

    vector<ll> dy = {-2, -2, -2, -2, -2, -1, -1, -1, -1, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2};
    vector<ll> dx = {-2, -1, 0, 1, 2, -2, -1, 1, 2, -2, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2};

    while(!que.empty()){
        pair<ll,ll> now_pos = que.front();
        ll now_pos_y = now_pos.first;
        ll now_pos_x = now_pos.second;
        que.pop_front();

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
                //dist[next_pos_y][next_pos_x] = dist[now_pos_y][now_pos_x] + 1;
                //vec[next_pos_y][next_pos_x] = ".";
                //que.push_back(make_pair(next_pos_y,next_pos_x));
                continue;
            }  
            //既に訪問済みなら何もしない
            if(dist[next_pos_y][next_pos_x] != -1){
                if(dist[next_pos_y][next_pos_x] <= dist[now_pos_y][now_pos_x]){
                    continue;
                }
            }
            //now_posから訪問できるノードをqueに追加
            dist[next_pos_y][next_pos_x] = dist[now_pos_y][now_pos_x];
            que.push_front(make_pair(next_pos_y,next_pos_x));
        }

        //ワープ判定
        rep(i, dy.size()){
            ll next_pos_y = now_pos_y + dy.at(i);
            ll next_pos_x = now_pos_x + dx.at(i);  

            //場外なら何もしない
            if(next_pos_x < 0 || next_pos_x >= w || next_pos_y < 0 || next_pos_y >= h){
                continue;
            }

            //壁なら何もしない
            if(vec[next_pos_y][next_pos_x] == "#"){
                continue;
            }  

            //既に訪問済みなら何もしない
            //if(dist[next_pos_y][next_pos_x] < dist[now_pos_y][now_pos_x]+1){
            //if(dist[next_pos_y][next_pos_x] != -1){
                //if(dist[next_pos_y][next_pos_x] < dist[now_pos_y][now_pos_x]+1) continue;
            //}
            if(dist[next_pos_y][next_pos_x] != -1){
                continue;
            }

            //now_posから訪問できるノードをqueに追加
            dist[next_pos_y][next_pos_x] = dist[now_pos_y][now_pos_x]+1;
            que.push_back(make_pair(next_pos_y,next_pos_x));

        }
    }

    
    /*
    rep(i, h){
        rep(j, w){
            if(dist[i][j] == -1 && vec[i][j] == "."){

            }
        }
    }

    rep(i, h){
        rep(j, w){
            cout << dist[i][j] << " ";
        }
        br;
    }
    */
   cout << dist[dh][dw] << endl;


}