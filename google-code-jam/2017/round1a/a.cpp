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
        ll r, c; cin >> r >> c;
        vector<vector<char>> vec(r, vector<char>(c));

        rep(i, r){
            rep(j, c){
                cin >> vec[i][j];
            }
        }

        //右に伸ばす
        rep(i, r){
            char now = '.';
            rep(j, c){
                if(vec[i][j] != '?'){
                    if(vec[i][j] != now) now = vec[i][j];
                }else{
                    if(now != '.') vec[i][j] = now;
                }
            }
        }
        //左に伸ばす
        rep(i, r){
            char now = '.';
            for(ll j = c-1; j >= 0; j--){
                if(vec[i][j] != '?'){
                    if(vec[i][j] != now) now = vec[i][j];
                }else{
                    if(now != '.') vec[i][j] = now;
                }
            }
        }

        //上から下に
        for(ll i = 1; i < r; i++){
            if(vec[i][0] == '?'){
                if(vec[i-1][0] != '?'){
                    rep(j, c){
                        vec[i][j] = vec[i-1][j];
                    }
                }
            }
        }

        //下から上に
        for(ll i = r-2; i >= 0; i--){
            if(vec[i][0] == '?'){
                if(vec[i+1][0] != '?'){
                    rep(j, c){
                        vec[i][j] = vec[i+1][j];
                    }
                }
            }
        }

        

        cout << "Case #" << T+1 << ":" << '\n';
        rep(i, r){
            rep(j, c){
                cout << vec[i][j];
            }br;
        }




    }

}