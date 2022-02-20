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

vector<long long> x;
vector<ll> seen;
vector<vector<ll>> ans(100010);

void dfs(vector<vector<ll>> &g, ll v, ll p){
    seen[v] = 1;

    vector<ll> tmp;
    tmp.push_back(x[v]);

    for(auto next: g[v]){
        if(seen[next]){
            continue;
        }else{
            dfs(g, next, v);
            for(ll i = 0; i < ans[next].size(); i++){
                tmp.push_back(ans[next][i]);
            }
        }
    }

    sort(all(tmp), greater<ll>());

    vector<ll> res;
    for(ll i = 0; i < min(20, (int)tmp.size()); i++){
        res.push_back(tmp[i]);
    }

    ans[v] = res;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, q; cin >> n >> q;
    
    for(long long i = 0; i < n; i ++){
        ll xx; cin >> xx; x.push_back(xx);
    }
    vector<vector<ll>> g(n);
    rep(i, n-1){
        ll a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b); g[b].push_back(a);
    }

    seen.assign(n, 0);

    dfs(g, 0, -1);

    rep(i, q){
        ll v, k; cin >> v >> k; v--; k--;
        cout << ans[v][k] << endl;
    }

}