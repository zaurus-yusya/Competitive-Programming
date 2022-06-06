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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    while(true){
        ll n, m; cin >> n >> m;
        if(n == 0 && m == 0) break;

        vector<ll> c(m);
        rep(i, m) cin >> c[i];

        vector<ll> x(n);
        rep(i, n) cin >> x[i];

        vector<vector<ll>> dp(n+10, vector<ll>(255+10, INF));
        dp[0][128] = 0;

        for(ll i = 0; i < n; i++){ // 20000

            for(ll j = 0; j < m; j++){ // 16

                for(ll k = 0; k <= 255; k++){ // 255
                    ll y = k + c[j];
                    if(y < 0) y = 0;
                    if(y > 255) y = 255;
                    dp[i+1][y] = min(dp[i+1][y], dp[i][k] + (x[i] - (y)) * (x[i] - (y)));
                }

            }

        }

        ll ans = INF;
        for(ll i = 0; i <= 255; i++){
            ans = min(ans, dp[n][i]);
        }
        cout << ans << '\n';

    }

}