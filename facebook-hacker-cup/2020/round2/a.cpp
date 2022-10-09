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
        ll n, k; cin >> n >> k; // 10,000,000
        vector<long long> s(n);
        for(long long i = 0; i < k; i ++){
            cin >> s[i];
        }
        ll as, bs, cs, ds; cin >> as >> bs >> cs >> ds;
        vector<long long> x(n);
        for(long long i = 0; i < k; i ++){
            cin >> x[i];
        }
        ll ax, bx, cx, dx; cin >> ax >> bx >> cx >> dx;
        vector<long long> y(n);
        for(long long i = 0; i < k; i ++){
            cin >> y[i];
        }
        ll ay, by, cy, dy; cin >> ay >> by >> cy >> dy;

        rep(i, n){
            if(i >= k){
                s[i] = ((as * s[i-2]) % ds + (bs * s[i-1]) % ds + cs % ds) % ds;
                x[i] = ((ax * x[i-2]) % dx + (bx * x[i-1]) % dx + cx % dx) % dx;
                y[i] = ((ay * y[i-2]) % dy + (by * y[i-1]) % dy + cy % dy) % dy;
            }
        }
        rep(i, n){
            y[i] = x[i] + y[i];
        }

        ll customer = 0;
        ll mi = 0;
        ll ma = 0;
        rep(i, n){
            customer += s[i];
            mi += x[i];
            ma += y[i];
        }

        ll huyasu = 0;
        ll herasu = 0;
        if(mi <= customer && customer <= ma){
            rep(i, n){
                if(s[i] < x[i]){
                    huyasu += x[i] - s[i];
                }
                if(y[i] < s[i]){
                    herasu += s[i] - y[i];
                }
            }
            cout << "Case #" << T+1 << ": " << max(huyasu, herasu) << '\n';
        }else{
            cout << "Case #" << T+1 << ": " << -1 << '\n';
        }
    }

}