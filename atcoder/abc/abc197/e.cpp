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
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}
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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<ll> x(n);
    vector<ll> c(n);
    vector<P> p(n);
    ll ma = 0;

    vector<vector<ll>> ball(n);
    rep(i, n){
        cin >> x[i] >> c[i]; c[i]--;
        ma = max(ma, c[i]);
        p[i] = {c[i], x[i]};
        ball[c[i]].push_back(x[i]);
    }

    sort(all(p));

    vector<vector<ll>> dp(n+10, vector<ll>(2, INF)); //[i番目の玉まで][lで終わるかrで終わるか]
    dp[0][0] = 0; dp[0][1] = 0; //0左 1右

    vector<P> ichi(n+1);
    for(ll i = 0; i <= ma; i++){
        sort(all(ball[i]));
        if(ball[i].size() == 0){
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][1];
            ichi[i+1].first = ichi[i].first;
            ichi[i+1].second = ichi[i].second;
            continue;
        }
        ll l = ball[i][0], r = ball[i][ball[i].size() - 1];

        ichi[i+1].first = l, ichi[i+1].second = r;

        //左から左
        if(ichi[i].first < l){
            chmin(dp[i+1][0], dp[i][0] + 2*(r-l) + l-ichi[i].first);
        }else if(ichi[i].first > r){
            chmin(dp[i+1][0], dp[i][0] + (r-l) + ichi[i].first-r);
        }else{
            chmin(dp[i+1][0], dp[i][0] + (r-l) + r - ichi[i].first);
        }
        //左から右
        if(ichi[i].first < l){
            chmin(dp[i+1][1], dp[i][0] + (r-l) + l-ichi[i].first);
        }else if(ichi[i].first > r){
            chmin(dp[i+1][1], dp[i][0] + 2*(r-l) + ichi[i].first-r);
        }else{
            chmin(dp[i+1][1], dp[i][0] + (r-l) + ichi[i].first - l);
        }

        //右から左
        if(ichi[i].second < l){
            chmin(dp[i+1][0], dp[i][1] + 2*(r-l) + l-ichi[i].second);
        }else if(ichi[i].second > r){
            chmin(dp[i+1][0], dp[i][1] + (r-l) + ichi[i].second-r);
        }else{
            chmin(dp[i+1][0], dp[i][1] + (r-l) + r - ichi[i].second);
        }

        //右から右
        if(ichi[i].second < l){
            chmin(dp[i+1][1], dp[i][1] + (r-l) + l-ichi[i].second);
        }else if(ichi[i].second > r){
            chmin(dp[i+1][1], dp[i][1] + 2*(r-l) + ichi[i].second-r);
        }else{
            chmin(dp[i+1][1], dp[i][1] + (r-l) + ichi[i].second-l);
        }
    }

    ll ans = min(dp[ma+1][0] + abs(ichi[ma+1].first), dp[ma+1][1] + abs(ichi[ma+1].second));
    cout << ans << endl;

}