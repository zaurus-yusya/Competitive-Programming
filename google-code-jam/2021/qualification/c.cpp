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
bool flag = true;

void rec2(const vector<vector<long long>> &dp, const vector<ll> &a, int i, int j, vector<ll> &keiro, vector<ll> &ans) {
    if (i == 0) {
        if (j == 0) {
            ans = keiro;
            /*
            cout << "keiro" << endl;
            rep(k, keiro.size()){
                cout << keiro[k] << " ";
            }br;
            */
            
        }
        flag = false;
        return;
    }

    // 上へ遡る (dp[i-1][j] == 0) だったら無視)
    if (dp[i-1][j]) {
        if(flag) rec2(dp, a, i-1, j, keiro, ans);
    }
    // 左上へ遡る (dp[i-1][j-a[i-1]] == 0 だったら無視)
    if (j-a[i-1] >= 0 && dp[i-1][j-a[i-1]]) {
        keiro.push_back(a[i-1]);
        if(flag) rec2(dp, a, i-1, j-a[i-1], keiro, ans);
        keiro.pop_back();
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll n, c; cin >> n >> c;
        
        ll mi = n-1;
        ll ma = ( (n*(n+1))/2 ) - 1;

        flag = true;
        
        if(c < mi || ma < c){
            cout << "Case #" << (T+1) << ": IMPOSSIBLE" << endl; continue;
        }else if(c == n-1){
            cout << "Case #" << (T+1) << ": ";
            rep(i, n){
                if(i == 0) cout << i+1;
                else cout << " " << i+1;
            }br;
            continue;
        }
        

        ll x = c - (n-1);
        //cout << "x = " << x << endl;

        vector<ll> vec(n-1);
        rep(i, n-1) vec[i] = i+1;
        reverse(all(vec));

        vector<vector<ll>> dp(n, vector<ll>(10000, 0));
        dp[0][0] = 1;
        for(ll i = 0; i < n-1; i++){
            for(ll j = 0; j < ma+1; j++){
                dp[i+1][j] += dp[i][j];
                dp[i+1][j + vec[i]] += dp[i][j];
            }
        }
        //cout << "dp = " << dp[n-1][x] << endl;

        vector<ll> keiro;
        vector<ll> ans;

        rec2(dp, vec, n-1, x, keiro, ans);

        vector<ll> select(ans.size());
        rep(i, ans.size()){
            select[i] = n-ans[i];
        }

        //cout << "select" << endl;
        //vecdbg(select);

        vector<ll> l(n); rep(i, n) l[i] = i+1;
        for(ll i = 0; i < select.size(); i++){
            vector<ll> tmp;
            for(ll j = select[i]-1; j < n; j++){
                tmp.push_back(l[j]);
            }
            reverse(all(tmp));
            for(ll j = 0; j < tmp.size(); j++){
                l[select[i]-1 + j] = tmp[j];
            }
        }

        cout << "Case #" << (T+1) << ": ";
            rep(i, n){
                if(i == 0) cout << l[i];
                else cout << " " << l[i];
            }br;

    }

}