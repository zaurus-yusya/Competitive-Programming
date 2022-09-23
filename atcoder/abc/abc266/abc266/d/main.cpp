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


//dijkstra
struct Edge
{
    ll x, a;
    Edge(ll x = 0, ll a = 0) : x(x), a(a) {}
    //g[a].emplace_back(x, y) : x = to, y = cost
};


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    map<ll, Edge> mp;
    vector<ll> t(n);
    vector<ll> x(n);
    vector<ll> a(n);
    rep(i, n){
        cin >> t[i] >> x[i] >> a[i];
        mp[t[i]].x = x[i];
        mp[t[i]].a = a[i];
    }

    
    vector<vector<ll>> dp(100010, vector<ll>(5, -INF));
    dp[0][0] = 0;

    for(ll i = 0; i < 100005; i++){
        //あるか
        if(mp.count(i+1) > 0){
            ll xx = mp[i+1].x;
            ll aa = mp[i+1].a;
            // cerr << xx << " " << aa << endl;

            for(ll j = 0; j < 5; j++){
                // j: 移動先
                //左
                if(j != 0){
                    if(j-1 == xx){
                        //cerr << "i = " << i << " j = "<< j << endl;
                        dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j] + aa);
                        // cerr << dp[i+1][j-1] << endl;
                    }else{
                        dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j]);
                    }
                }
                //動かない
                if(j == xx){
                    // cerr << "ii = " << i << " j = "<< j<< endl;
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j] + aa);
                }else{
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                }

                //右
                if(j != 4){
                    if(j+1 == xx){
                        //cerr << "iii = " << i << " j = "<< j<< endl;
                        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + aa);
                    }else{
                        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
                    }
                }
            }
        }else{
            for(ll j = 0; j < 5; j++){
                //左
                if(j != 0){
                    dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j]);
                }
                //動かない
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);

                //右
                if(j != 4){
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
                }
            }
        }
    }

    ll ans = 0;
    rep(i, 5){
        //cerr << dp[100001][i] << endl;
        ans = max(ans, dp[100001][i]);
    }
    cout << ans << endl;

    // cout << dp[1][0] << endl;
    // cout << dp[1][1] << endl;
    // cout << dp[1][2] << endl;
    // cout << dp[1][3] << endl;
    // cout << dp[1][4] << endl;



}