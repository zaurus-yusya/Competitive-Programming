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
// for(auto& i: mp) &&&&&&&&&&&&&

ll n, m;
vector<ll> dp(131082, INF);
void dfs(vector<vector<ll>> &g, ll v, ll now, ll path){

    for(ll j = 0; j < g[v].size(); j++){
        ll next = g[v][j];
        ll nextb = (1 << (n-1 - next));

        if(dp[now ^ nextb] > path + 1){
            dp[now ^ nextb] = path + 1;
            dfs(g, next, (now ^ nextb), path+1);
        }
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> n >> m;
    vector<vector<ll>> g(n);

    rep(i, m){
        ll u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v); g[v].push_back(u);
    }

    dp[0] = 0;
    for(ll i = 0; i < n; i++){
        dp[(1<<i)] = 1;
    }

    for(ll i = 0; i < n; i++){
        dfs(g, i, (1<<i), 1);
    }

    ll ans = 0;
    for(ll i = 0; i < (1<<n); i++){
        //cerr << "bit = " << i << endl;
        //cout << dp[i] << endl;
        ans += dp[i];
    }
    cout << ans << endl;



}