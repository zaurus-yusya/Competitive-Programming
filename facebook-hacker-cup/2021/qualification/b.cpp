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
    rep(T, t){
        ll n; cin >> n;
        vector<vector<char>> vec(n, vector<char>(n));
        rep(i, n)rep(j, n) cin >> vec[i][j];

        map<ll, ll> mp;

        //yoko
        rep(i, n){
            ll cnt = 0;
            bool flag = true;
            ll ind = -1;
            rep(j, n){
                if(vec[i][j] == 'O'){
                    flag = false; break;
                }else if(vec[i][j] == '.'){
                    cnt++;
                    ind = j;
                }
            }
            if(flag){
                mp[cnt]++;
            }
        }

        //tate
        rep(j, n){
            ll cnt = 0;
            bool flag = true;
            rep(i, n){
                if(vec[i][j] == 'O'){
                    flag = false; break;
                }else if(vec[i][j] == '.'){
                    cnt++;
                }
            }
            if(flag){
                mp[cnt]++;
            }
        }

        //tateyoko
        rep(i, n){
            rep(j, n){
                if(vec[i][j] == '.'){
                    bool flag = true;
                    //ue
                    for(ll Y = i-1; Y >= 0; Y--){
                        if(vec[Y][j] != 'X') flag = false;
                    }
                    //shita
                    for(ll Y = i+1; Y < n; Y++){
                        if(vec[Y][j] != 'X') flag = false;
                    }

                    //hidari
                    for(ll X = j-1; X >= 0; X--){
                        if(vec[i][X] != 'X') flag = false;
                    }

                    //migi
                    for(ll X = j+1; X < n; X++){
                        if(vec[i][X] != 'X') flag = false;
                    }

                    if(flag) mp[1]--;

                }
            }
        }

        if(mp.size() == 0){
            cout << "Case #" << T+1 << ": " << "Impossible" << '\n';
        }else{
            ll k = mp.begin()->first;
            cout << "Case #" << T+1 << ": " << k << " " << mp[k] << '\n';
        }
    }

}