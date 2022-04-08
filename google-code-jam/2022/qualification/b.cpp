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
        vector<ll> c(3);
        vector<ll> m(3);
        vector<ll> y(3);
        vector<ll> k(3);
        rep(i, 3){
            cin >> c[i] >> m[i] >> y[i] >> k[i];
        }
        sort(all(c)); sort(all(m)); sort(all(y)); sort(all(k));

        if(c[0] + m[0] + y[0] + k[0] < 1000000){
            cout << "Case #" << T+1 << ": " << "IMPOSSIBLE" << '\n';
        }else{
            vector<ll> ans(4);
            ll total = 1000000;
            if(c[0] >= total){
                ans[0] = total;
                total = 0;
            }else{
                ans[0] = c[0];
                total -= c[0];
            }
            if(m[0] >= total){
                ans[1] = total;
                total = 0;
            }else{
                ans[1] = m[0];
                total -= m[0];
            }
            if(y[0] >= total){
                ans[2] = total;
                total = 0;
            }else{
                ans[2] = y[0];
                total -= y[0];
            }
            if(k[0] >= total){
                ans[3] = total;
                total = 0;
            }else{
                ans[3] = k[0];
                total -= k[0];
            }

            cout << "Case #" << T+1 << ": " << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << '\n';


        }


    }

}