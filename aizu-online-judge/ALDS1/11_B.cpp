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

ll n;
vector<vector<ll>> to(n);
vector<bool> seen(n);
vector<ll> d(n);
vector<ll> f(n);

ll dfs(ll node, ll time){
    if(seen[node] == false){
        seen[node] = true;
        d[node] = time;
    }

    for(ll next : to[node]){
        if(seen[next]){
            continue;
        }else{
            time = dfs(next, time+1);
        }
    }
    time += 1;

    f[node] = time;

    return time;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> n;
    to.resize(n);
    seen.resize(n);
    d.resize(n);
    f.resize(n);
    rep(i, n){
        ll u; cin >> u; u--;
        ll k; cin >> k;
        rep(j, k){
            ll v; cin >> v; v--;
            to[u].push_back(v);
        }
    }

    ll time = 0;
    for(ll i = 0; i < n; i++){
        if(seen[i] == false){
            time = dfs(i, time+1);
        }
    }
    

    for(ll i = 0; i < n; i++){
        cout << i+1 << " " << d[i] << " " << f[i] << endl;
    }

}