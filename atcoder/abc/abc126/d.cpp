#include <bits/stdc++.h>
#include <atcoder/all>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
using namespace atcoder;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// If the result in local and judge is different, USE CODETEST!!

struct edge{
    ll to;
    ll cost;
};

vector<ll> ans;
vector<ll> seen;
void dfs(vector<vector<edge>> &g, ll v, ll color){
    seen[v] = 1;
    ans[v] = color;
    for(auto next: g[v]){
        if(seen[next.to] == 0){
            if(next.cost % 2 == 0){
                dfs(g, next.to, color);
            }else{
                dfs(g, next.to, (color + 1) % 2);
            }
        }
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;

    vector<vector<edge>> g(n);
    rep(i, n-1){
        ll u, v, w; cin >> u >> v >> w; u--; v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    ans.resize(n);
    seen.resize(n);

    dfs(g, 0, 0);

    rep(i, n){
        cout << ans[i] << "\n";
    }



}