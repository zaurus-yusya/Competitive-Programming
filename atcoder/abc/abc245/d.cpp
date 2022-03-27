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
    ll n, m; cin >> n >> m;
    vector<long long> a(n+1);
    for(long long i = 0; i < n+1; i ++){
        cin >> a[i];
    }
    vector<long long> c(n+m+1);
    for(long long i = 0; i < n+m+1; i ++){
        cin >> c[i];
    }
    vector<ll> b(m+1);
    // b[0] = c[0] / a[0];
    // b[1] = 

    for(ll i = m; i >= 0; i--){
        ll x = m + n - (m - i);
        ll tmp = c[m + n - (m - i)];
        // cerr << "i = " << i << endl;
        // cerr << "x = " << x << endl;
        // cerr << "tmp = " << tmp << endl;
        for(ll j = 0; j <= (m - i); j++){
            if(j == (m-i)){
                //cerr << tmp << " " << a[n] << endl;
                b[i] = tmp / a[n];
            }else{
                if(x-(m-j) < 0) continue;
                //cerr << "j = " << j << " " << m-j << " " << x-(m-j) << endl;
                tmp -= b[m - j] * a[x - (m-j)];
            }
        }
    }

    // for(ll i = 0; i <= m; i++){
    //     ll tmp = c[i];
    //     for(ll j = 0; j <= i; j++){
    //         if(j == i){
    //             b[i] = tmp / a[j - i];
    //         }else{
    //             tmp -= b[j] * a[i - j];
    //         }
    //     }
    // }
    
    rep(i, m+1){
        cout << b[i] << " ";
    }br;



}