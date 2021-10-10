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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll n; cin >> n; //even
        vector<vector<ll>> vec(n, vector<ll>(5));
        rep(i, n){
            rep(j, 5){
                cin >> vec[i][j];
            }
        }

        bool ans = false;
        for(ll fd = 0; fd <= 4; fd++){
            for(ll sd = fd+1; sd <= 4; sd++){

                ll cntf = 0, cnts = 0, cntb = 0;
                bool f = true;
                for(ll i = 0; i < n; i++){
                    if(vec[i][fd] == 1 && vec[i][sd] == 1){
                        cntb++;
                    }else if(vec[i][fd] == 1){
                        cntf++;
                    }else if(vec[i][sd] == 1){
                        cnts++;
                    }else{
                        f = false;
                    }
                }

                if(!f) continue;
                
                //cout << fd << " " << sd << " " << cntf << " " << cnts << endl;
                if(cntf <= n/2 && cnts <= n/2){
                    ans = true;
                }

            }
        }

        if(ans){
            cout << "YES" << '\n';
        }else{
            cout << "NO" << '\n';
        }
    }

}