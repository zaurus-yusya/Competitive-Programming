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
    ll t; cin >> t;
    map<ll, ll> mp;
    for(ll i = 0; i <= 9; i++){
        for(ll j = 0; j <= 9; j++){
            mp[i+j]++;
        }
    }

    rep(T, t){
        ll n; cin >> n;
        string s = to_string(n);

        vector<ll> moto;
        ll x = n;
        while(x > 0){
            moto.push_back(x % 10);
            x /= 10;
        }

        if(n < 100){
            ll ans = 0;
            for(ll i = 1; i < n; i++){
                ll x = i, y = n - i;
                if((x % 10) + (y % 10) >= 10) continue;
                if(((x/10) % 10) + ((y/10) % 10) >= 10) continue;
                ans++;
            }
            cout << ans << endl;
            continue;
        }

        ll bsize = s.size() - 2;

        ll ans = 0;
        for(ll bit = 0; bit < (1<<bsize); bit++){
            vector<ll> num = moto;

            for(ll j = 0; j < bsize; j++){
                if((bit >> j) & 1){
                    num[j] += 10; num[j+2] -= 1;
                }
            }

            ll tmp = 1;
            rep(i, num.size()){
                tmp *= mp[num[i]];
            }
            ans += tmp;

        }

        cout << ans - 2 << endl;

    }
    

}