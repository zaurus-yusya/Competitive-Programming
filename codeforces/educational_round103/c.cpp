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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll n; cin >> n;
        vector<long long> c(n);
        for(long long i = 0; i < n; i ++){
            cin >> c[i];
        }
        vector<long long> a(n);
        for(long long i = 0; i < n; i ++){
            cin >> a[i];
        }
        vector<long long> b(n);
        for(long long i = 0; i < n; i ++){
            cin >> b[i];
        }

        ll ans = 0;
        ll cur = 0;
        for(ll i = 0; i < n; i++){
            //cout << "i = " << i << endl;

            if(i == 0){
                cur = abs(a[1] - b[1]) + 1;
                continue;
            } 


            if(a[i] == b[i]){
                //同じ値の時curを1にする
                //cur = 1;
                //この鎖で終わる
                ll X = c[i] + cur;
                chmax(ans, X);
                //cout << "この鎖で終わる" << X << endl;
                //次の鎖に行く
                if(i < n-1){
                    ll ma = max(a[i+1], b[i+1]);
                    ll mi = min(a[i+1], b[i+1]);
                    cur += mi - 1 + 1;
                    cur += c[i] - ma + 1;
                    if(a[i+1] == b[i+1]){
                        cur = 1;
                    }
                    //cout << a[i+1] << " " << b[i+1] << endl;
                    //cout << "次の鎖に行く" << cur << endl;
                }

            }else{
                //この鎖で終わる
                ll X = c[i] + cur;
                chmax(ans, X);
                //cout << "この鎖で終わる" << X << endl;

                //次の鎖に行く
                if(i < n-1){
                    ll ma = max(a[i+1], b[i+1]);
                    ll mi = min(a[i+1], b[i+1]);
                    cur += mi - 1 + 1;
                    cur += c[i] - ma + 1;
                    if(a[i+1] == b[i+1]){
                        cur = 1;
                    }
                    //cout << a[i+1] << " " << b[i+1] << endl;
                    //cout << "次の鎖に行く" << cur << endl;
                } 
            }
        }

        cur = 0;
        
        for(ll i = n; i >= 1; i--){
            //cout << i << endl;
            if(i == n){
                cur = c[n-1];
                continue;
            } 


            if(a[i] == b[i]){
                //同じ値の時curを1にする
                //cur = 1;
                //この鎖で終わる
                ll X = abs(a[i] - b[i]) + 1 + cur;
                chmax(ans, X);
                //cout << "この鎖で終わる" << X << endl;
                //次の鎖に行く
                if(i > 1){
                    ll ma = max(a[i], b[i]);
                    ll mi = min(a[i], b[i]);
                    cur += mi - 1 + 1;
                    cur += c[i-1] - ma + 1;
                    if(a[i] == b[i]){
                        cur = c[i-1];
                    }
                    //cout << a[i+1] << " " << b[i+1] << endl;
                    //cout << "次の鎖に行く" << cur << endl;
                }

            }else{
                //この鎖で終わる
                ll X = abs(a[i] - b[i]) + 1 + cur;
                chmax(ans, X);
                //cout << "この鎖で終わる" << X << endl;

                //次の鎖に行く
                if(i > 1){
                    ll ma = max(a[i], b[i]);
                    ll mi = min(a[i], b[i]);
                    cur += mi - 1 + 1;
                    cur += c[i-1] - ma + 1;
                    if(a[i] == b[i]){
                        cur = c[i-1];
                    }
                    //cout << a[i+1] << " " << b[i+1] << endl;
                    //cout << "次の鎖に行く" << cur << endl;
                } 
            }
        }

        cout << ans << endl;
    }


}