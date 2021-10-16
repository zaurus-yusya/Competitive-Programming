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
const long long MOD = 1e9+7;
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
    ll n; cin >> n;
    vector<ld> a(n);
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
    }

    vector<ll> res;
    ll count = 0; ll ima = 0;
    rep(i, n-1){
        if(ima == 0){
            if(a[i] < a[i+1]){
                res.push_back(0);
            }else{
                res.push_back(1);
                count++;
                ima = 1;
            }
        }else{
            if(a[i] > a[i+1]){
                res.push_back(0);
            }else{
                res.push_back(1);
                count++;
                ima = 0;
            }
        }
    }

    if(count % 2 == 0){
        res.push_back(0);
    }else{
        res.push_back(1);
    }
    rep(i, res.size()){
        cout << res[i] << " ";
    }br;
    return 0;



    vector<vector<ld>> dp(n+1, vector<ld>(2, 0));
    vector<vector<P>> pre(n+1, vector<P>(2));
    // 0 金, 1 銀
    dp[0][0] = 1;

    rep(i, n){
        rep(j, 2){
            if(j == 0){
                if(dp[i+1][(j+1)%2] < dp[i][j] * a[i]){
                    pre[i+1][(j+1)%2] = {i, j};
                    chmax(dp[i+1][(j+1)%2], dp[i][j] * a[i]);
                }
                if(dp[i+1][j] < dp[i][j]){
                    pre[i+1][j] = {i, j};
                    chmax(dp[i+1][j], dp[i][j]);
                }
                //chmax(dp[i+1][(j+1)%2], dp[i][j] * a[i]); //金→銀
                //chmax(dp[i+1][j], dp[i][j]);
            }else{
                if(dp[i+1][(j+1)%2] < dp[i][j] / a[i]){
                    pre[i+1][(j+1)%2] = {i, j};
                    chmax(dp[i+1][(j+1)%2], dp[i][j] / a[i]);
                }
                if(dp[i+1][j] < dp[i][j]){
                    pre[i+1][j] = {i, j};
                    chmax(dp[i+1][j], dp[i][j]);
                }
                //chmax(dp[i+1][(j+1)%2], dp[i][j] / a[i]); //銀→金
                //chmax(dp[i+1][j], dp[i][j]);
            }
        }
        /*
        if(dp[i+1][0] < dp[i+1][1]){
            dp[i+1][0] = 1; dp[i+1][1] = 2;
        }else if(dp[i+1][0] == dp[i+1][1]){
            dp[i+1][0] = 1; dp[i+1][1] = 1;
        }else{
            dp[i+1][0] = 2; dp[i+1][1] = 1;
        }
        */

    }

    vector<P> ans;
    P x = {n, 0};

    while(true){
        x = pre[x.first][x.second];
        ans.push_back(x);
        if(x.first == 0 && x.second == 0) break;
    }

    reverse(all(ans));
    
    
    rep(i, ans.size()){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    
    /*
    rep(i, n+1){
        cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    */
    

    ll cnt = 0;
    ll now = 0;
    for(ll i = 1; i < ans.size(); i++){
        if(now == ans[i].second){
            cout << 0 << " ";
        }else{
            cout << 1 << " ";
            now = ans[i].second;
        }
    }

    if(now == 0){
        cout << 0 << endl;
    }else{
        cout << 1 << endl;
    }

}