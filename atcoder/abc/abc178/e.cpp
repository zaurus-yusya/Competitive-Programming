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
const long long INF = 1e10;
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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> posi(n);
    vector<ll> nega(n);
    rep(i, n){
        cin >> x[i] >> y[i];
        posi[i] = x[i] + y[i];
        nega[i] = x[i] - y[i];
    }
    ll pmax = -1 * INF, pmin = INF;
    ll nmax = -1 * INF, nmin = INF;
    rep(i, n){
        pmax = max(pmax, posi[i]); pmin = min(pmin, posi[i]);
        nmax = max(nmax, nega[i]); nmin = min(nmin, nega[i]);
    }
    ll ans = -1 * INF;
    ans = max(ans, pmax - pmin);
    ans = max(ans, nmax - nmin);
    cout << ans << endl;

}