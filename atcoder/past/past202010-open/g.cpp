#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
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

vector<ll> dy = {1, -1, 0, 0};
vector<ll> dx = {0, 0, 1, -1};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    vector<vector<char>> vec(n, vector<char>(m));
    rep(i, n){
        rep(j, m){
            cin >> vec[i][j];
        }
    }

    ll ans = 0;
    rep(i, n){
        rep(j, m){
            if(vec[i][j] == '.') continue;

            vec[i][j] = '.';

            vector<vector<ll>> dist(n, vector<ll>(m, -1));
            queue<pair<ll, ll>> que;
            
            //最初のマス
            bool ff = false;
            rep(ii, n){
                rep(jj, m){
                    if(vec[ii][jj] == '.'){
                        dist[ii][jj] = 0;
                        que.push({ii, jj});
                        ff = true;
                        break;
                    }
                }
                if(ff) break;
            }
            
            while(!que.empty()){
                pair<ll, ll> now = que.front();
                ll nowy = now.first, nowx = now.second;
                que.pop();
            
                rep(iii, dy.size()){
                    ll nexty = nowy + dy[iii], nextx = nowx + dx[iii];
            
                    //場外ならcontinue
                    if(nexty < 0 || nexty >= n || nextx < 0 || nextx >= m) continue;
                    //壁ならcontinue
                    if(vec[nexty][nextx] == '#') continue;
                    //訪問済みならcontinue
                    if(dist[nexty][nextx] != -1) continue;
            
                    dist[nexty][nextx] = dist[nowy][nowx] + 1;
                    que.push({nexty, nextx});
                }
            }

            ll tmp = 1;
            rep(ii, n){
                rep(jj, m){
                    if(vec[ii][jj] == '.' && dist[ii][jj] == -1){
                        tmp = 0;
                    }
                }
            }
            ans += tmp;

            vec[i][j] = '#';
        }
    }
    cout << ans << endl;

}