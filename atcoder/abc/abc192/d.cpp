#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!
// over flow  if(a > INF / b)


int main() {
    std::cout << std::fixed << std::setprecision(15);
    string x; cin >> x; ll m; cin >> m;

    if(x.size() == 1){
        if((ll)(x[0] - '0') > m){
            cout << 0 << endl;
        }else{
            cout << 1 << endl;
        }
        return 0;
    }

    ll d = 0;
    rep(i, x.size()){
        d = max(d, (ll)(x[i] - '0'));
    }
    ll ok = d, ng = m+1;
    while((ng - ok) > 1){
        ll mid = (ok + ng) / 2;
        ll res = 0;
        rep(i, x.size()){
            if(res > m / mid){
                //overflow
                res = m+1;
            }else{
                res = res * mid + (ll)(x[i] - '0');
            }
        }
        if(res <= m){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok - d << endl;

}