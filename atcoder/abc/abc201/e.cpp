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

vector<ll> res;

map<pair<ll, ll>, ll> mp;

vector<bool> seen;
void dfs(const Graph &G, ll v, ll x)
{
    seen[v] = true;
    res[v] = x;

    for(ll next_node : G[v]){
        if(seen[next_node]){
            continue;
        }else{
            ///////
            //今見てるnodeに対する処理
            ///////
            ll y = mp[{v, next_node}];
            dfs(G, next_node, x^y);
        }
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<vector<ll>> g(n);

    rep(i, n-1){
        ll u, v, w; cin >> u >> v >> w; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[{u, v}] = w;
        mp[{v, u}] = w;
    }

    seen.assign(n,false);
    res.assign(n,0);

    dfs(g, 0, 0);

    //vecdbg(res);

    vector<ll> zero(61);
    vector<ll> one(61);
    rep(i, n){
        ll count = 0;
        ll tmp = res[i];
        
        for(ll j = 0; j < 61; j++){
            if(tmp & 1){
                one.at(count)++;
            }else{
                zero.at(count)++;
            }
            count++;
            tmp = tmp >> 1;
        }
    }
 
    ll ans = 0;
    ll twopow = 1;
    rep(i, 61){
        ll tmp;
        tmp = (zero[i] * one[i]) % MOD;
        tmp = (twopow * tmp) % MOD;
        ans = (ans + tmp) % MOD;
        twopow = (twopow * 2) % MOD; 
    }
 
    cout << ans << endl;

}