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

ll dp[110][100010][2];

void rev(ll (&dp)[110][100010][2], vector<ll> &a, vector<ll> &b, ll i, ll j, ll k, string ans){
    if(i == 0 && j == 0){
        reverse(all(ans));
        cout << ans << endl;
        exit(0);
    }

    //aを作った方に遡る
    if(j - a[i-1] >= 0 && dp[i-1][j - a[i-1]][0] != 0){
        rev(dp, a, b, i-1, j-a[i-1], 0, ans += "A");
    }
    if(j - a[i-1] >= 0 && dp[i-1][j - a[i-1]][1] != 0){
        rev(dp, a, b, i-1, j-a[i-1], 0, ans += "A");
    }

    //bを使った方に遡る
    if(j - b[i-1] >= 0 && dp[i-1][j - b[i-1]][0] != 0){
        rev(dp, a, b, i-1, j-b[i-1], 1, ans += "B");
    }
    if(j - b[i-1] >= 0 && dp[i-1][j - b[i-1]][1] != 0){
        rev(dp, a, b, i-1, j-b[i-1], 1, ans += "B");
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, s; cin >> n >> s;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i, n){
        cin >> a[i] >> b[i];
    }
    dp[0][0][0] = 1, dp[0][0][1] = 1;
    rep(i, n){
        if(i == 0){
            dp[i+1][0 + a[i]][0] = 1;
            dp[i+1][0 + b[i]][1] = 1;
            continue;
        }
        rep(j, 100001){
            rep(k, 2){
                if(dp[i][j][k] != 0){
                    //aを使う
                    dp[i+1][min(j + a[i], (ll)100001)][0] += dp[i][j][k];
                    //bを使う
                    dp[i+1][min(j + b[i], (ll)100001)][1] += dp[i][j][k];
                }
            }
        }
    }
    string ans = "";
    
    if(dp[n][s][0] != 0){
        rev(dp, a, b, n, s, 0, ans);
    }else if(dp[n][s][1] != 0){
        rev(dp, a, b, n, s, 0, ans);
    }else{
        cout << "Impossible" << endl;
    }


}