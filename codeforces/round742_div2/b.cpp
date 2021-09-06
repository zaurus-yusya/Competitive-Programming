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
const long long INF = 8e18;
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
ll calc2(ll n){
    if(n % 4 == 0){
        return n;
    }
    if(n % 4 == 1){
        return 1;
    }
    if(n % 4 == 2){
        return n+1;
    }
    return 0;
}

ll calc(ll l, ll r){
    return calc2(r) ^ calc2(l-1);
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll a, b; cin >> a >> b;

        ll now = 0;

        if(a == 1){
            now = 0;
            if(now == b){
                cout << 1 << endl;
            }else if(b == 1){
                cout << 1 + 2 << endl;
            }else{
                cout << 1 + 1 << endl;
            }
            continue;
        }
        if(a == 2){
            // 00001
            now = 1;
            if(now == b){
                cout << 2 << endl;
            }else if((now ^ (a)) == b){
                cout << 2 + 2 << endl;
            }else{
                cout << 2 + 1 << endl;
            }
            continue;
        }

        now = calc(1, a-1);
        if(now == b){
            cout << a << endl;
        }else if((now ^ (a)) == b){
            cout << a + 2 << endl;
        }else{
            cout << a + 1 << endl;
        }
        continue;




    }

}