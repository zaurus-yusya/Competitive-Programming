#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e9;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
vector<bool> seen;
vector<ll> ans;
void dfs(vector<vector<pair<ll,ll>>> &g, ll node, ll cost){
    seen[node] = true;
    ans[node] = cost % 2;

    for(ll i = 0; i < g[node].size(); i++){
        ll next_node = g[node][i].second;
        if(seen[next_node]){
            continue;
        }else{
            ///////
            //今見てるnodeに対する処理
            ///////
            cost += g[node][i].first;
            dfs(g, next_node, cost);
            cost -= g[node][i].first;
        }
    }
    
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<vector<pair<ll, ll>>> g(n);
    rep(i, n - 1){
        ll u, v, w; cin >> u >> v >> w; u--; v--;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    
    seen.resize(n);
    ans.resize(n, -1);
    ans[0] = 0;
    dfs(g, 0, 0);

    rep(i, n){
        cout << ans[i] << endl;
    }

}