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
    ll n, l, r; cin >> n >> l >> r;

    vector<ll> vec;
    ll x = n;
    for(ll i = 0; i < 65; i++){
    //while(x > 0){
        vec.push_back(x&1);
        x = x>>1;
    }
    reverse(all(vec));
    //vecdbg(vec);

    ll ans = r - l + 1;
    //cerr << "ans = " << ans << endl;
        // ll tmp = vec.size();
        // ll ma = POW(2, tmp+1) - 1;
        // ll mi = POW(2, tmp);
        // ll dame = 0;
        // if(ma <= r && l <= mi){
        //     dame = ma - mi + 1;
        // }else if(r < mi || ma < l){
        //     dame = 0;
        // }else if(mi <= l && r <= ma){
        //     dame = r - l + 1;
        // }else if(l < mi && r <= ma){
        //     dame = r - mi + 1;
        // }else{
        //     dame = ma - l + 1;
        // }
        // ans  -= dame;
    rep(i, vec.size()){
        if(vec[i] == 0){
            ll tmp = vec.size() - 1 - i;
            ll ma = POW(2, tmp+1) - 1;
            ll mi = POW(2, tmp);
            ll dame = 0;
            if(ma <= r && l <= mi){
                dame = ma - mi + 1;
            }else if(r < mi || ma < l){
                dame = 0;
            }else if(mi <= l && r <= ma){
                dame = r - l + 1;
            }else if(l < mi && r <= ma){
                dame = r - mi + 1;
            }else{
                dame = ma - l + 1;
            }
            ans  -= dame;
            //cerr << "dame = " << dame << " ans = " << ans << " i = " << i << endl;
        }
    }
    cout << ans << endl;

}