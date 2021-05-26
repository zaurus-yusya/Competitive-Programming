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

ll n;
ll cnt = 0;
vector<pair<ll, ll>> inout(n);
vector<ll> depth(n);
vector<ll> seen(n);
void dfs(vector<vector<ll>> &g, ll v, ll d){
    //in
    inout[v].first = cnt;
    depth[v] = d;
    seen[v] = 1;
    cnt++;
    for(ll next : g[v]){
        if(seen[next] == 0){
            dfs(g, next, d+1);
            cnt++;
        }
    }
    //out
    inout[v].second = cnt;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> n;
    vector<vector<ll>> g(n);
    depth.assign(n, 0);
    inout.assign(n, {-1, -1});
    seen.assign(n, 0);
    rep(i, n-1){
        ll p; cin >> p; p--;
        g[i+1].push_back(p); g[p].push_back(i+1);
    }

    dfs(g, 0, 0);
    vector<vector<ll>> hukasa(n);
    rep(i, n){
        ll x = depth[i];
        hukasa[x].push_back(inout[i].first);
    }
    rep(i, n){
        sort(all(hukasa[i]));
    }


    ll q; cin >> q;
    rep(i, q){
        ll u, d; cin >> u >> d; u--;
        ll r = lower_bound(all(hukasa[d]), inout[u].second) - hukasa[d].begin();
        ll l = lower_bound(all(hukasa[d]), inout[u].first) - hukasa[d].begin();
        cout << r - l << endl;
    }
}