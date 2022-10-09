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
    ll n; cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i, n){
        rep(j, n){
            cin >> a[i][j];
        }
    }

    vector<vector<map<ll, ll>>> vec(n, vector<map<ll, ll>>(n));
    vec[0][0][a[0][0]]++;
    // 前半
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n-i; j++){
            // 左から
            if(j > 0){
                for(auto&k: vec[i][j-1]){
                    vec[i][j][k.first ^ a[i][j]] += k.second;
                }
            }
            // 上から
            if(i > 0){
                for(auto&k: vec[i-1][j]){
                    vec[i][j][k.first ^ a[i][j]] += k.second;
                }
            }
        }
    }

    // 後半
    vector<vector<map<ll, ll>>> vec2(n, vector<map<ll, ll>>(n));
    vec2[n-1][n-1][a[n-1][n-1]]++;
    for(ll i = n-1; i >= 0; i--){
        for(ll j = n-1; j >= n-1-i; j--){
            // 右から
            if(j < n-1){
                for(auto&k: vec2[i][j+1]){
                    if(j == n-1-i){
                        vec2[i][j][k.first] += k.second;
                    }else{
                        vec2[i][j][k.first ^ a[i][j]] += k.second;
                    }
                }
            }
            // 下から
            if(i < n-1){
                for(auto&k: vec2[i+1][j]){
                    if(j == n-1-i){
                        vec2[i][j][k.first] += k.second;
                    }else{
                        vec2[i][j][k.first ^ a[i][j]] += k.second;
                    }
                }
            }
        }
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++){
        for(auto&k: vec[i][n-1-i]){
            if(vec2[i][n-1-i].count(k.first) > 0){
                ans += k.second * vec2[i][n-1-i][k.first];
            }
        }

    }

    cout << ans << endl;

}