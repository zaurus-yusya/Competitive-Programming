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

void rec(const vector<vector<long long>> &dp, const vector<ll> &a, int i, int j, deque<ll> &keiro, vector<deque<ll>> &ans) {
    if (i == 0) {
        if (j == 0) {
            ans.push_back(keiro);
        }
        return;
    }

    // 上へ遡る (dp[i-1][j] == 0) だったら無視)
    if (dp[i-1][j]) {
        rec(dp, a, i-1, j, keiro, ans);
    }
    // 左上へ遡る (dp[i-1][j-a[i-1]] == 0 だったら無視)
    if ( ((j-a[i-1]+200)%200) >= 0 && dp[i-1][(j-a[i-1] + 200) % 200]) {
        //keiro.push_front(a[i-1]);
        keiro.push_front(i);
        rec(dp, a, i-1, (j-a[i-1]+200)%200, keiro, ans);
        keiro.pop_front();
    }
}





int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<long long> a(n);
    vector<ll> m(n);
    map<ll, ll> mp;
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
        a[i] = a[i] % 200;
        m[i] = a[i] % 200;
    }

    vector<vector<ll>> dp(210, vector<ll>(210));
    dp[0][0] = 1;

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < 200; j++){
            //選ぶ
            dp[i+1][(j + a[i]) % 200] += dp[i][j];

            //選ばない
            dp[i+1][j] += dp[i][j];
        }

        for(ll j = 0; j < 200; j++){
            if(j == 0){
                if(dp[i+1][j] >= 3){
                    deque<ll> keiro;
                    vector<deque<ll>> ans;
                    rec(dp, a, i+1, j, keiro, ans);
                    cout << "Yes" << endl;
                    cout << ans[1].size();
                    for (auto el : ans[1]) cout << " " << el;
                    br;
                    cout << ans[2].size();
                    for (auto el : ans[2]) cout << " " << el;
                    br;
                    return 0;
                }
            }else{
                if(dp[i+1][j] >= 2){
                    deque<ll> keiro;
                    vector<deque<ll>> ans;
                    rec(dp, a, i+1, j, keiro, ans);
                    cout << "Yes" << endl;
                    cout << ans[0].size();
                    for (auto el : ans[0]) cout << " " << el;
                    br;
                    cout << ans[1].size();
                    for (auto el : ans[1]) cout << " " << el;
                    br;
                    return 0;
                }
            }

        }
    }
    /*
    cerr << "--" << endl;
    rep(i, 200){
        cout << "i = " << i << " " << dp[n][i] << endl;
    }
    */

    cout << "No" << endl;
    /*
    rec(dp, a, n, 0, keiro, ans);

    cout << "the num of combinations is: " << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << i+1 << " case:";
        for (auto el : ans[i]) cout << " " << el;
        cout << endl;
    }
    */




}