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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(i, t){
        ll b, k, sx, sy, gx, gy; cin >> b >> k >> sx >> sy >> gx >> gy;

        if(sx > gx){
            swap(sx, gx);
            swap(sy, gy);
        }
        ll ans = 0;

        // 両方とも大通り上ある場合
        // if( ((sx % b == 0) && (gy % b == 0)) || ((sy % b == 0) && (gx % b == 0))){
        //     ans = abs(sx - gx) + abs(sy - gy);
        //     cout << ans << endl;
        //     continue;
        // }

        // sxより右で最も近いxの大通り
        ll sxr = sx + (b - (sx % b));
        // gxより左で最も近いxの大通り
        ll gxl = gx - (gx % b);

        if(sy < gy){
            // syより上で最も近いyの大通り
            ll syu = sy + (b - (sy % b));
            // gyより下で最も近いyの大通り
            ll gyd = gy - (gy % b);

            ll tmp = min((sxr - sx), (syu - sy)) + min((gx - gxl), (gy - gyd));
            ll nokori = abs(sx - gx) + abs(sy - gy) - tmp;

            cout << tmp * k + nokori << '\n';

        }else{
            // syより下で最も近いyの大通り
            ll syd = sy - (sy % b);
            // gyより上で最も近いyの大通り
            ll gyu = gy + (b - (gy % b));

            ll tmp = min((sxr - sx), (sy - syd)) + min((gx - gxl), (gyu - gy));
            ll nokori = abs(sx - gx) + abs(sy - gy) - tmp;

            cout << tmp * k + nokori << '\n';








        }

        

    }

}