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
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;

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
    ll n, k; cin >> n >> k;
    vector<long long> vec(n);
    ll sum = 0;
    for(long long i = 0; i < n; i ++){
        cin >> vec[i];
        sum += vec[i];
    }

    ll ok = sum, ng = 0;
    while(ok - ng > 1){
        //cout << ng << " " << ok << endl;
        ll mid = (ok + ng) / 2;
        ll dai = 1;
        ll tmp = 0;
        bool flag = false;
        rep(i, n){
            if(vec[i] > mid){
                ng = mid;
                flag = true;
                break;
            }
            if(tmp + vec[i] > mid){
                dai += 1;
                tmp = vec[i];
            }else{
                tmp += vec[i];
            }
        }

        if(flag) continue;
        //cout << "mid " << mid << " " << dai << endl;

        if(dai <= k){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;
    
}

