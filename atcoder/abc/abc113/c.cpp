#include <bits/stdc++.h>
#include <atcoder/all>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
using namespace atcoder;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b == 0) (a/b) + 1
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
// If the result in local and judge is different, USE CODETEST!!


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    map<ll, ll> mp;
    vector<ll> Y(m);
    vector<vector<ll>> vec(n+1);
    rep(i, m){
        ll p, y; cin >> p >> y;
        mp[y] = p;
        vec[p].push_back(y);
        Y[i] = y;
    }

    rep(i, n+1){
        if(vec[i].size() != 0){
            sort(all(vec[i]));
        }
    }

    rep(i, m){
        ll x = mp[Y[i]];
        ll tmp = 1000000;
        string ans = to_string(tmp + x);
        ans.erase(0, 1);
        ll ind = lower_bound(vec[x].begin(), vec[x].end(), Y[i]) - vec[x].begin() + 1;
        string ans2 = to_string(tmp + ind);
        ans2.erase(0, 1);
        cout << ans << ans2 << endl;
    }





}