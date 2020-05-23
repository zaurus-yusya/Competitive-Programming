#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
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
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m, Q;
    cin >> n >> m >> Q;
    Graph g(n);
    rep(i, m){
        ll u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v); g[v].push_back(u);
    }

    vector<long long> color(n);
    for(long long i = 0; i < n; i ++){
        cin >> color[i];
    }
    vector<ll> ans;
    rep(q, Q){
        ll s; cin >> s;
        if(s == 1){
            ll x; cin >> x; x--;
            //cout << color[x] << endl;
            ans.push_back(color[x]);
            for(ll i = 0; i < g[x].size(); i++){
                color[g[x][i]] = color[x];
            }
        }

        if(s == 2){
            ll x, y; cin >> x >> y; x--;
            //cout << color[x] << endl;
            ans.push_back(color[x]);
            color[x] = y;
        }
    }

    rep(i,ans.size()){
        cout << ans[i] << endl;
    }

}