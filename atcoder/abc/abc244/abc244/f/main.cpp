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
vector<vector<ll>> dp(131082, vector<ll>(20, INF));

struct Edge
{
    ll to, bit, path;
    Edge(ll to = 0, ll bit = 0, ll path = 0) : to(to), bit(bit), path(path) {}
};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> n >> m;
    vector<vector<ll>> g(n);

    rep(i, m){
        ll u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v); g[v].push_back(u);
    }

    for(ll i = 0; i < n; i++){
        dp[0][i] = 0;
        dp[(1<<(n-1 - i))][i] = 1;
    }

    queue<Edge> que;
    for(ll i = 0; i < n; i++){
        que.push({i, (1<<(n-1 - i)), 1});

        while(!que.empty()){
            ll now = que.front().to;
            ll nowb = que.front().bit;
            ll nowp = que.front().path;
            que.pop();

            for(ll j = 0; j < g[now].size(); j++){
                ll next = g[now][j];
                ll nextb = nowb ^ (1 << (n-1 - next));
                ll nextp = nowp + 1;

                if(dp[nextb][next] > nextp){
                    dp[nextb][next] = nextp;
                    que.push({next, nextb, nextp});
                }
            }
        }
    }

    ll ans = 0;
    for(ll i = 0; i < (1<<n); i++){
        ll tmp = INF;
        for(ll j = 0; j < n; j++){
            tmp = min(tmp, dp[i][j]);
        }
        ans += tmp;
    }
    cout << ans << endl;

}