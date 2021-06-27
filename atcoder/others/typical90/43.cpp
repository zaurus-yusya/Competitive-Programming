#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;
const double PI = acos(-1);

// 0 false, 1 true 
// string number to int : -48 or - '0'
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!
// (a * b)over flow?   if(a > INF / b){ /* overflow */}

ll dist[1010][1010][4];
struct x {
    ll y, x, muki;
};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll h, w; cin >> h >> w;
    ll rs, cs; cin >> rs >> cs; rs--; cs--;
    ll rt, ct; cin >> rt >> ct; rt--; ct--;
    vector<vector<char>> vec(h, vector<char>(w));
    rep(i, h)rep(j, w) cin >> vec[i][j];
    rep(i, 1010)rep(j, 1010)rep(k, 4) dist[i][j][k] = INF;

    dist[rs][cs][0] = 0;
    dist[rs][cs][1] = 0;
    dist[rs][cs][2] = 0;
    dist[rs][cs][3] = 0;

    vector<ll> dy = {-1, 1, 0, 0}; 
    vector<ll> dx = {0, 0, -1, 1};

    deque<x> que;
    que.push_front({rs, cs, 0});
    que.push_front({rs, cs, 1});
    que.push_front({rs, cs, 2});
    que.push_front({rs, cs, 3});
    
    while(!que.empty()){
        ll now_y = que.front().y, now_x = que.front().x, muki = que.front().muki;
        que.pop_front();
        // d u l r
        rep(i, 4){
            ll next_y = now_y + dy[i], next_x = now_x + dx[i];
            ll next_cost = dist[now_y][now_x][muki];
            
            //場外ならcontinue
            if(next_y < 0 || next_y >= h || next_x < 0 || next_x >= w) continue;
            //壁ならcontinue
            if(vec[next_y][next_x] == '#') continue;

            //向きを変える
            if(muki != i){
                next_cost++;
                if(next_cost < dist[next_y][next_x][i]){
                    dist[next_y][next_x][i] = next_cost;
                    que.push_back({next_y, next_x, i});
                }
            }else{
                //進む
                if(next_cost < dist[next_y][next_x][i]){
                    dist[next_y][next_x][i] = next_cost;
                    que.push_front({next_y, next_x, i});
                }
            }
            


        }
    }

    //vecvecdbg(dist);
    ll ans = INF;
    rep(i, 4){
        chmin(ans, dist[rt][ct][i]);
    }
    cout << ans << endl;

}