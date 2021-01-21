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
    ll n, c; cin >> n >> c;

    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> v(n);
    vector<ll> sum_x(n+1);
    vector<ll> sum_y(n+1);

    rep(i, n){
        cin >> x[i] >> v[i];
        sum_x[i+1] = sum_x[i] + v[i]; 
    }

    rep(i, n){
        y[i] = c - x[n-1 - i];
        sum_y[i+1] = sum_y[i] + v[n-1 - i];
    }

    vector<ll> x_max_katamichi(n+1);
    vector<ll> y_max_katamichi(n+1);
    ll cur_x = -INF;
    ll cur_y = -INF;
    rep(i, n){
        cur_x = max(cur_x, sum_x[i+1] - x[i]);
        x_max_katamichi[i+1] = cur_x;
        cur_y = max(cur_y, sum_y[i+1] - y[i]);
        y_max_katamichi[i+1] = cur_y;
    }

    vector<ll> x_max_modori(n+1);
    vector<ll> y_max_modori(n+1);
    cur_x = -INF;
    cur_y = -INF;
    rep(i, n){
        cur_x = max(cur_x, sum_x[i+1] - 2 * x[i]);
        x_max_modori[i+1] = cur_x;
        cur_y = max(cur_y, sum_y[i+1] - 2 * y[i]);
        y_max_modori[i+1] = cur_y;
    }


    ll ans = 0;
    //x start y katamichi
    rep(i, n+1){
        chmax(ans, x_max_modori[i] + y_max_katamichi[n - i]);
    }
    //y start x katamichi
    rep(i, n+1){
        if(i == n){
            chmax(ans, y_max_modori[i]); continue;
        }
        chmax(ans, y_max_modori[i] + x_max_katamichi[n - i]);
    }

    cout << ans << endl;
}