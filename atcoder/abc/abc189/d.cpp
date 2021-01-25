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
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<string> vec(n);
    vector<ll> or_basho;
    ll a = 0, o = 0;
    for(long long i = 0; i < n; i ++){
        cin >> vec[i];
        if(vec[i] == "AND"){
            a++;
        }else{
            or_basho.push_back(i);
            o++;
        }
    }

    if(o == 0){
        cout << 1 << endl; return 0;
    }

    vector<vector<ll>> dp(70, vector<ll>(2));
    dp[0][0] = 1;
    dp[0][1] = 1;
    //0 false 1 true
    rep(i, n){
        if(vec[i] == "AND"){
            //cout << dp[i][0] << " " << dp[i][1] << endl; 
            dp[i+1][0] = (dp[i][0] * 2 + dp[i][1]);
            dp[i+1][1] = dp[i][1];
        }else{
            dp[i+1][0] = (dp[i][0]);
            dp[i+1][1] = (dp[i][0] + dp[i][1] * 2);
        }

        //cout << dp[i+1][0] << " " << dp[i+1][1] << endl;
    }

    cout << dp[n][1] << endl;

    /*

    //vecdbg(or_basho);
    vector<ll> kukan;
    rep(i, or_basho.size()){
        if(i == 0){
            kukan.push_back(or_basho[i] - 0 + 1);
        }else{
            kukan.push_back(or_basho[i] - or_basho[i-1]);
        }
    }
    kukan.push_back(n - or_basho[or_basho.size() - 1]);

    vecdbg(kukan);

    ll tmp = 1;

    rep(i, kukan.size()){
        tmp *= (powl(2, kukan[i]) - 1);
        //cout << tmp << endl;
    }

    ll ans = powl(2, n+1);

    cout << ans - tmp << endl;

    //cout << powl(2, 61) << endl;
    */

}