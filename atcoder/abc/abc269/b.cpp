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
// for(auto& i: mp) &&&&&&&&&&&&&

int main() {
    std::cout << std::fixed << std::setprecision(15);
    vector<vector<char>> vec(10, vector<char>(10));
    rep(i, 10){
        rep(j, 10){
            cin >> vec[i][j];
        }
    }


    ll a = 0, b = -1;

    rep(j, 10){
        bool f = false;
        bool ff = false;
        ll aa = 0, bb = -1;
        rep(i, 10){
            if(f){
                if(vec[i][j] == '#'){
                    
                }else{
                    bb = i-1;
                    f = false;
                }
            }else{
                if(vec[i][j] == '#'){
                    ff = true;
                    f = true;
                    aa = i;
                }else{

                }
            }
        }

        if(ff){
            a = aa;
            if(bb == -1){
                b = 9;
            }else{
                b = bb;
            }
            break;
        }
    }

    ll c = 0, d = -1;
    rep(i, 10){
        bool f = false;
        bool ff = false;
        ll cc = 0, dd = -1;

        rep(j, 10){
            if(f){
                if(vec[i][j] == '#'){
                    
                }else{
                    dd = j-1;
                    f = false;
                }
            }else{
                if(vec[i][j] == '#'){
                    ff = true;
                    f = true;
                    cc = j;
                }else{

                }
            }
        }

        if(ff){
            c = cc;
            if(dd == -1){
                d = 9;
            }else{
                d = dd;
            }
            break;
        }
    }

    // if(b == -1){
    //     b = 9;
    // }

    cout << a+1 << " " << b+1 << endl;
    cout << c+1 << " " << d+1 << endl;




}