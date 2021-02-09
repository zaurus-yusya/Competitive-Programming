#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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
    ll n, m; cin >> n >> m;
    if(m == 0){
        cout << -1 << endl; return 0;
    }
    vector<ll> a(n);
    vector<ll> b(n);
    map<pair<ll, ll>, ll> p;

    
    map<ll, ll> mp;
    vector<map<ll, ll>> vm(n);

    rep(i, m){
        cin >> a[i] >> b[i]; a[i]--; b[i]--;
        p[make_pair(a[i], b[i])]++;
        mp[a[i]]++;
        mp[b[i]]++;
    }

    ll k; cin >> k;
    vector<ll> c(k);
    rep(i, k){
        cin >> c[i]; c[i]--;
        if(mp[c[i]] == 0){
            cout << -1 << endl; return 0;
        }
    }

    //hinagata
    //https://atcoder.jp/contests/past201912-open/submissions/18980789
    vector<ll> dp(1050000, INF);
    dp[0] = 0;
    
    for(ll i = 0; i < (1<<k); i++){
        //ひとつたてる
        for(ll x = 0; x < k; x++){
            if(mp[c[i]] > 0){
                dp[i | (1<<x)] = min(dp[i | (1<<x)], dp[i] + 2);
            }
        }
        //ふたつたてる
        for(ll x = 0; x < k; x++){
            for(ll y = x+1; y < k; y++){
                ll X = c[x], Y = c[Y];
                if(X > Y) swap(X, Y);
                ll bit = (1<<x) || (1 << y);
                if(p[{X, Y}] > 0){
                    dp[i | (1<<bit)] = min(dp[i | (1<<bit)], dp[i] + 2);
                }
            }
        }
    }

    cout << dp[(1<<k)] << endl;



}