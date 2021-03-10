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
    ll n; cin >> n;
    vector<long long> p(n);
    for(long long i = 0; i < n; i ++){
        cin >> p[i];
    }

    vector<ll> high(n);
    ll cur = 0;
    vector<ll> peak;
    vector<ll> takasa;
    ll mae = 0;
    bool flag = true;
    map<ll, ll> kyoku;

    peak.push_back(0);
    kyoku[0]++;
    takasa.push_back(0);

    rep(i, n){
        if(i == 0){
            high[i] = cur;
        }else{
            bool tmp = flag;
            if(p[i] > p[i-1]){
                cur++;
                flag = true;
            }else{
                cur--;
                flag = false;
            }
            high[i] = cur;

            if(tmp != flag){
                peak.push_back(i-1);
                kyoku[i-1]++;
                takasa.push_back(abs(high[i-1]));
                mae = high[i-1];
            }
        }
    }
    peak.push_back(n-1);
    kyoku[n-1]++;
    takasa.push_back(abs(high[n-1]));


    vecdbg(high);
    vecdbg(peak);
    vecdbg(takasa);
    ll ans = 0;
    rep(i, n){

    }


}