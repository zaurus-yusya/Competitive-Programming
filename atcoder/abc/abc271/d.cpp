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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, s; cin >> n >> s;
    vector<ll> l(n);
    vector<ll> r(n);
    rep(i, n){
        cin >> l[i] >> r[i];
    }

    vector<vector<bool>> dp(110, vector<bool>(10010, false));
    dp[0][0] = true;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j <= 10000; j++){
            if(!dp[i][j]) continue;
            // lを選ぶ
            if(j + l[i] <= 10000){
                dp[i+1][j + l[i]] = true;
            }
            // rを選ぶ
            if(j + r[i] <= 10000){
                dp[i+1][j + r[i]] = true;
            }

        }
    }

    if(dp[n][s]){
        vector<char> ans;
        ll now = s;
        for(ll i = 1; i <= n; i++){
            if(now - l[n - i] >= 0 && dp[n-i][now - l[n - i]]){
                // 左の場合
                ans.push_back('H');
                now = now - l[n - i];
            }else if(now - r[n - i] >= 0 && dp[n-i][now - r[n - i]]){
                // 右の場合
                ans.push_back('T');
                now = now - r[n - i];
            }else{
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
        reverse(all(ans));
        rep(i, n){
            cout << ans[i];
        }br;
    }else{
        cout << "No" << endl;
    }

    /*
    vector<vector<ll>> dp(110, vector<ll>(10010));
    dp[0][0] = 1;

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j <= 10000; j++){
            if(dp[i][j] == 0){
                continue;
            }
            // lを選ぶ
            if(j + l[i] <= 10000){
                dp[i+1][j + l[i]] += dp[i][j];

                if(dp[i+1][j + l[i]] > 1){
                    dp[i+1][j + l[i]] = 1;
                }
            }

            // rを選ぶ
            if(j + r[i] <= 10000){
                dp[i+1][j + r[i]] += dp[i][j];
                if(dp[i+1][j + r[i]] > 1){
                    dp[i+1][j + r[i]] = 1;
                }
            }
        }
    }

    // cout << dp[n][s] << endl;
    if(dp[n][s] >= 1){
        cout << "Yes" << endl;
        vector<char> ans;
        ll now = s;
        for(ll i = 1; i <= n; i++){
            if(dp[n-i][now - l[n - i]] > 0){
                // 左の場合
                ans.push_back('H');
                now = now - l[n - i];
            }else if(dp[n-i][now - r[n - i]] > 0){
                // 右の場合
                ans.push_back('T');
                now = now - r[n - i];
            }else{
                cout << "No" << endl;
                return 0;
            }
        }
        cerr << "now = " << now << endl;
        reverse(all(ans));
        rep(i, n){
            cout << ans[i];
        }br;
    }else{
        cout << "No" << endl;
    }
    */

}