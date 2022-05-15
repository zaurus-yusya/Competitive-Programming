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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll l, r; cin >> l >> r;
        ll delta = abs(l - r);
        ll ok = 0, ng = 4e9;
        while(ng - ok > 1){
            ll mid = (ng + ok) / 2;
            if(mid * (mid+1) <= 2 * delta){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        
        if(l > r){
            l -= (1 + ok) * ok / 2;
        }else{
            r -= (1 + ok) * ok / 2;
        }
        
        bool f = false;
        if(l < r){
            f = true;
            swap(l, r);
        }
        // l は cur+1, cur+3, cur+5, ,,,,
        // r は cur+2, cur+4, cur+6, ,,,,
        ll cur = ok;
        ll add = 0;

        ok = 0, ng = 4e9;
        while(ng - ok > 1){
            ll mid = (ng + ok) / 2;
            if( (1 + 2*mid -1) * mid / 2 + cur * mid <= l){
                ok = mid;
            }else{
                ng = mid;
            }
        }

        l -= (1 + 2*ok -1) * ok / 2 + cur * ok;
        add += ok;

        ok = 0, ng = 4e9;
        while(ng - ok > 1){
            ll mid = (ng + ok) / 2;
            if( (2 + 2*mid) * mid / 2 + cur * mid <= r){
                ok = mid;
            }else{
                ng = mid;
            }
        }

        r -= (2 + 2*ok) * ok / 2 + cur * ok;
        add += ok;

        if(f){
            swap(l, r);
        }

        cout << "Case #" << T+1 << ": " << cur+add << " " << l << " " << r << '\n';
        
    }

}