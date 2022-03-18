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
        ll n, a, b; cin >> n >> a >> b;
        vector<long long> u(n);
        for(long long i = 0; i < n; i ++){
            cin >> u[i];
        }

        ll res = n-1;
        ll now = res;
        while(true && now < 1000){
            vector<ll> tmp(now + 1);
            tmp[now] = 1;

            //cout << "res now = " << res << " " << now << endl;

            bool flag = true;
            for(ll i = now; i >= 0; i--){
                if(i >= n){
                    //全部分解
                    if(i - a >= 0){
                        tmp[i - a] += tmp[i];
                    }
                    if(i - b >= 0){
                        tmp[i - b] += tmp[i];
                    }
                }else{
                    if(tmp[i] < u[i]){
                        flag = false; break;
                    }
                    //分解できるだけ分解
                    if(i - a >= 0){
                        tmp[i - a] += tmp[i] - u[i];
                    }
                    if(i - b >= 0){
                        tmp[i - b] += tmp[i] - u[i];
                    }
                }

            }

            //チェック
            for(ll i = 0; i < n; i++){
                if(tmp[i] < u[i]) flag = false;
            }

            //vecdbg(tmp);

            res += 1;
            now = res;

            if(flag) break;
        }

        if(now == 1000){
            cout << "Case #" << T+1 << ": " << "IMPOSSIBLE" << '\n';
        }else{
            cout << "Case #" << T+1 << ": " << res << '\n';
        }
        
    }

}