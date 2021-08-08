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
const long long INF = 8e18;
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

//右左
vector<ll> dy = {1, -1, 0, 0};
vector<ll> dx = {0, 0, 1, -1};

vector<ll> ddy = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
vector<ll> ddx = {-1, 0, 1, -1, 0, 1, -1, 0, 1};


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll h, w; cin >> h >> w;
    vector<vector<char>> vec(h, vector<char>(w));
    rep(i, h)rep(j, w) cin >> vec[i][j];

    //vecvecdbg(vec);

    vector<vector<ll>> dist(h, vector<ll>(w, -1));

    deque<pair<ll, ll>> que;

    dist[0][0] = 0;
    que.push_back({0, 0});

    while(!que.empty()){
        ll now_y = que.front().first;
        ll now_x = que.front().second;
        //cerr << "now " << now_y << " " << now_x << endl;
        que.pop_front();

        rep(i, 4){
            ll next_y = now_y + dy[i];
            ll next_x = now_x + dx[i];
            //cerr << "next " << next_y << " " << next_x << endl;

            //場外ならcontinue
            if(next_y < 0 || next_y >= h || next_x < 0 || next_x >= w) continue;

            //既に訪問済みならcontinue
            if(dist[next_y][next_x] != -1){
                if(dist[next_y][next_x] <= dist[now_y][now_x]){
                    continue;
                }
            } 

            if(vec[next_y][next_x] == '#'){
                //2*2を見て更新
                rep(j, 9){
                    ll kowa_y = next_y + ddy[j];
                    ll kowa_x = next_x + ddx[j];
                    //cerr << "kowa " << 

                    //場外ならcontinue
                    if(kowa_y < 0 || kowa_y >= h || kowa_x < 0 || kowa_x >= w) continue;

                    if(dist[kowa_y][kowa_x] == -1){
                        dist[kowa_y][kowa_x] = dist[now_y][now_x] + 1;
                        que.push_back({kowa_y, kowa_x});
                    }else if(dist[kowa_y][kowa_x] > dist[now_y][now_x] + 1){
                        dist[kowa_y][kowa_x] = dist[now_y][now_x] + 1;
                        que.push_back({kowa_y, kowa_x});
                    }

                }
            }else{
                dist[next_y][next_x] = dist[now_y][now_x];
                que.push_front({next_y, next_x});
            }

        }

    }
    

    //vecvecdbg(dist);
    cout << dist[h-1][w-1] << endl;



}