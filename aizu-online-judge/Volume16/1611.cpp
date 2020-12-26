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

ll n;
vector<ll> w;
vector<vector<ll>> dp;

// [l, r)  0 1 2
ll solve(ll l = 0, ll r = n){
    if((r - l) <= 1) return 0;
    if((r - l) == 2){
        if(abs(w[r-1] - w[l]) <= 1) return 2;
        else return 0;
    }

    if(dp[l][r] != -1) return dp[l][r];

    if(abs(w[r-1] - w[l]) <= 1 && solve(l+1, r-1) == r - l - 2){
        dp[l][r] = max(dp[l][r], r - l);
    }

    for(ll i = l + 1; i <= r - 1; i++){
        dp[l][r] = max(dp[l][r], solve(l, i) + solve(i, r));
    }

    return dp[l][r];
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    while(true){
        cin >> n;
        if(n == 0) break;
        w.resize(n);
        rep(i, n) cin >> w[i];
        dp.assign(n + 1, vector<ll>(n + 1, -1));
        cout << solve() << endl;
    }
    

}