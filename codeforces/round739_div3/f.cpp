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

    vector<vector<ll>> num(10);
    for(ll X = 1; X < 10; X++){
        map<ll, ll> mpf;
        for(ll i = 0; i <= 9; i++){
            for(ll j = i+1; j <= 9; j++){
            
                for(ll bit = 0; bit < (1 << X); bit++){
                    map<ll, ll> mp;
                    for(ll ch = 0; ch < X; ch++){
                        if((bit >> ch) & 1){
                            mp[ch]++;
                        }
                    }
                    ll x = 0, y = 0;
                    rep(Y, X){
                        if(mp[Y] > 0){
                            x += i * POW(10, Y);
                        }else{
                            x += j * POW(10, Y);
                        }
                    }
                    
                    if(x < POW(10, X-1)) continue;
                    if(mpf[x] > 0){
                        continue;
                    }
                    num[X].push_back(x); //num[X].push_back(y);
                    mpf[x]++;
                }
                
            }
        }
    }
    rep(i, 10){
        sort(all(num[i]));
    }
    

    rep(T, t){
        ll n, k; cin >> n >> k;
        ll keta = get_digit(n);

        if(k == 1){
            for(ll i = 0; i <= 9; i++){
                ll x = 0;
                rep(j, keta){
                    x += i * POW(10, j);
                }
                if(x >= n){
                    cout << x << endl;
                    break;
                }
            }
        }else{
            if(n < 100){
                cout << n << endl; continue;
            }
            
            if(n == 1000000000){
                cout << n << endl; continue;
            }
            
            ll ans = INF;
            //k=1
            for(ll i = 0; i <= 9; i++){
                ll x = 0;
                rep(j, keta){
                    x += i * POW(10, j);
                }
                if(x >= n){
                    ans = min(ans, x);
                }
            }
            //

            ll x = lower_bound(num[keta].begin(), num[keta].end(), n) - num[keta].begin();
            cout << min(ans, num[keta][x]) << endl;

        }

    }

}