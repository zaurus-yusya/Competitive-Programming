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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    string s; cin >> s;
    ll q; cin >> q;
    

    vector<map<ll, ll>> vec(26);
    rep(i, n){
        char c = s[i];
        ll num = c - 'a';
        vec[num][i]++;
    }

    rep(Q, q){
        ll x; cin >> x;
        if(x == 1){
            ll i; char c; cin >> i >> c; i--;
            ll num = c - 'a';
            for(ll j = 0; j < 26; j++){
                if(vec[j].count(i) > 0){
                    vec[j].erase(i);
                    break;
                }
            }
            vec[num][i]++;
        }else{
            ll l, r; cin >> l >> r; l--; r--;
            ll ans = 0;
            for(ll j = 0; j < 26; j++){
                if(vec[j].size() == 0) continue;
                auto itr = vec[j].lower_bound(l);
                ll x = itr -> first;
                if(itr == vec[j].end()) continue;
                if(l <= x && x <= r){
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }

}