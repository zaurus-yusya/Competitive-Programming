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
    ll t; cin >> t;
    rep(T, t){
        ll l, r; cin >> l >> r;
        //1000000000
        // 0 -> 10 : 11
        // 0 -> 100 : 11 * 10 + 1
        // 0 -> 1000 : (11 * 10 + 1) * 10 + 1
        vector<ll> vec;
        vec.push_back(1);
        ll x = 11;
        for(ll i = 0; i < 9; i++){
            vec.push_back(x);
            x = x * 10 + 1;
        }
        //vecdbg(vec);

        ll cnt = 0;
        ll L = 0;
        while(l > 0){
            ll tmp = l % 10;
            L += tmp * vec[cnt];
            cnt++; l /= 10;
        }
        cnt = 0;
        ll R = 0;
        while(r > 0){
            ll tmp = r % 10;
            R += tmp * vec[cnt];
            cnt++; r /= 10;
        }
        cout << R - L << endl;

        /*
        ll ans = 0;
        for(ll i = 0; i < 10; i++){
            ll x = (r / POW(10, 9-i)) % 10;
            ll y = (l / POW(10, 9-i)) % 10;

            ll tmp = (10 - y + x) % 10;
            cout << "i = " << i << " tmp = " << tmp << endl;
            ans += tmp * POW(10, 9-i);
        }
        cout << ans << endl;
        */

    }

}