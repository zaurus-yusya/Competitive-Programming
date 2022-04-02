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
    ll t; cin >> t;
    rep(T, t){
        ll l, r; cin >> l >> r;
        vector<long long> a(r - l + 1);
        for(long long i = 0; i < r - l +1; i ++){
            cin >> a[i];
        }

        vector<ll> bit(20); //目的
        rep(i, r - l + 1){
            ll now = 0;
            ll x = a[i];
            while(x > 0){
                if((x&1) == 1){
                    bit[now]++;
                }
                now++;
                x = x >> 1;
            }
        }

        vector<ll> p(20); // 0 ~ r-l+1
        rep(i, r - l + 1){
            ll now = 0;
            ll x = i;
            while(x > 0){
                if((x&1) == 1){
                    p[now]++;
                }
                now++;
                x = x >> 1;
            }
        }

        vector<ll> p2(20); // l ~ r
        for(ll i = l; i <= r; i++){
            ll now = 0;
            ll x = i;
            while(x > 0){
                if((x&1) == 1){
                    p2[now]++;
                }
                now++;
                x = x >> 1;
            }
        }
        
        // vecdbg(bit);
        // vecdbg(p);
        // vecdbg(p2);


        // vector<ll> ans(20);
        // rep(i, 20){
        //     if(bit[i] != p[i]){
        //         ans[i] = 1;
        //     }
        // }
        vector<ll> ans(20);
        rep(i, 20){
            if(p2[i] != p[i]){
                ans[i] = 1;
            }
        }
        ll res = 0;
        rep(i, 20){
            if(ans[i] == 1){
                res += POW(2, i);
            }
        }
        //cerr << res << endl;

        vector<ll> ans2(20);
        rep(i, 20){
            if(bit[i] != p[i]){
                ans2[i] = 1;
            }
        }
        ll res2 = 0;
        rep(i, 20){
            if(ans2[i] == 1){
                res2 += POW(2, i);
            }
        }
        //cerr << res2 << endl;

        cout << (res ^ res2) << endl;
    }
    
}