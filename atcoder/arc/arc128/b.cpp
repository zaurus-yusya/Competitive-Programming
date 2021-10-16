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
    ll t; cin >> t;
    rep(T, t){
        ll r, g, b; cin >> r >> g >> b;
        ll ans = INF;

        //Rにする
        if(g == b){
            ans = min(ans, g);
        }else{
            if(abs(g - b) % 3 == 0){

                ll x = abs(g - b) / 3;
                if(x <= r){
                    ans = min(ans, x + (g+b+x)/2);
                }else{
                    ll y = ceilll((x-r), 2);
                    ll tmp = max(g, b) - (x+y);
                    ans = min(ans, x+y+tmp);
                }
            }
        }

        //Gにする
        if(r == b){
            ans = min(ans, r);
        }else{
            if(abs(r - b) % 3 == 0){
                ll x = abs(r - b) / 3;
                if(x <= g){
                    ans = min(ans, x + (r+b+x)/2);
                }else{
                    ll y = ceilll((x-g), 2);
                    ll tmp = max(r, b) - (x+y);
                    ans = min(ans, x+y+tmp);
                }
            }
        }

        //Bにする
        if(r == g){
            ans = min(ans, r);
        }else{
            if(abs(r - g) % 3 == 0){
                ll x = abs(r - g) / 3;
                if(x <= b){
                    ans = min(ans, x + (r+g+x)/2);
                }else{
                    ll y = ceilll((x-b), 2);
                    ll tmp = max(r, g) - (x+y);
                    ans = min(ans, x+y+tmp);
                }
            }
        }

        if(ans == INF){
            cout << -1 << endl;
        }else{
            cout << ans << endl;
        }

    }

}