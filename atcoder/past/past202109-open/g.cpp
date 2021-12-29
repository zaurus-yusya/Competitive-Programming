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
// for(auto& i: mp) &&&&&&&&&&&&&

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, k; cin >> n >> k;
    vector<ll> a(n); // length
    vector<ll> b(n); // first
    vector<ll> c(n); // div
    rep(i, n){
        cin >> a[i] >> b[i] >> c[i];
    }

    // b + cx  (0 <= x < a)
    // 2 3 4 6 7
    ll l = 0, r = INF;
    while(r - l > 1){
        ll mid = (l + r) / 2;
        //cout << "mid = " << mid << endl;

        ll miman = 0;
        ll cnt = 0;
        // b + cx = mid
        // x = (mid - b) / c
        // 2 4 6
        // 7 - 2 / 2 =.. 3
        // 8 - 2 / 2 = 3
        rep(i, n){
            ll tmp = min(a[i], (mid - b[i] + (c[i] - 1)) / c[i]);
            miman += tmp;
            if((mid - b[i]) % c[i] == 0 && tmp < a[i]){
                cnt++;
            }
        }

        //cout << "cnt = " << cnt << endl;
        //cout << miman + 1 << " " << miman + 1 + cnt - 1 << endl;
        if(miman + 1 <= k && k <= miman + 1 + cnt - 1){
            cout << mid << endl; return 0;
        }else{
            if(k < miman + 1){
                r = mid;
            }else{
                l = mid;
            }

        }
        // miman+1 <= x <= miman+1+cnt-1
        

    }

    // 1000000000 2000000000 3000000000 4000000000
    // 1000000000 2000000000 3000000000 4000000000 5000000000 6000000000



}