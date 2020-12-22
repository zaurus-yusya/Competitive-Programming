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
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b == 0) (a/b) + 1
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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<ll> X(n);
    vector<ll> Y(n);
    vector<ll> Z(n);
    rep(i, n){
        cin >> X[i] >> Y[i] >> Z[i];
    }
    
    vector<vector<ll>> g(n, vector<ll>(n));; //g[i][j]  from i to j
    for(ll i = 0; i < n; i ++){
        for(ll j = 0; j < n; j++){
            g[i][j] = abs(X[j] - X[i]) + abs(Y[j] - Y[i]) + max((ll)0, Z[j] - Z[i]);
        }
    }

    vector<vector<ll>> dp((1<<n) + 10, vector<ll>(n, INF));
    dp[0][0] = 0;

    for(ll S = 0; S < (1 << n); S++){
        for(ll v = 0; v < n; v++){
            for(ll u = 0; u < n; u++){
                if(S != 0 && !(S & (1<<u))) continue;
                if((S & (1 << v)) == 0){
                    if(v != u){
                        dp[S | (1 << v)][v] = min(dp[S | (1 << v)][v], dp[S][u] + g[u][v]); //uからvへ遷移
                    }
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][0] << endl;

}