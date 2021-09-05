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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    ll x = n;
    // 3進数変換
    vector<ll> res;
    while(true){
        if(x <= 2){
            res.push_back(x);
            break;
        }else{
            res.push_back(x % 3);
            x /= 3;
        }
    }

    vector<ll> ans;
    bool flag = false;
    rep(i, res.size()){
        if(flag){
            if(res[i] == 0){
                flag = false;
                ans.push_back(POW(3, i));
            }else if(res[i] == 1){
                ans.push_back(-1 * POW(3, i));
            }else{
                
            }
        }else{
            if(res[i] == 0){

            }else if(res[i] == 1){
                ans.push_back(POW(3, i));
            }else{
                flag = true;
                ans.push_back(-1 * POW(3, i));
            }
        }
    }

    if(flag){
        ans.push_back(POW(3, res.size()));
    }

    cout << ans.size() << endl;
    rep(i, ans.size()){
        cout << ans[i] << " ";
    }br;

    //  20
    // 100
    // 010
    //  6
    // 2 ... 0

    // 25
    //  8 ... 1
    //  2 ... 2

    // 2 2 1
    // 8
    // 9 3 1
    // 1 0 0
    //   2 2
}