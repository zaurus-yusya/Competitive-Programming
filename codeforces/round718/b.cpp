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
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;

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
    ll t; cin >> t; // <= 10000
    rep(T, t){
        ll n, m; cin >> n >> m; // <= 100
        vector<vector<ll>> vec(n, vector<ll>(m));
        rep(i, n){
            rep(j, m){
                cin >> vec[i][j];
            }
        }

        vector<P> now(m);
        vector<vector<ll>> ans(n, vector<ll>(m));

        rep(i, n){
            if(i == 0){
                sort(all(vec[i]));
                rep(j, m){
                    ans[i][j] = vec[i][j];
                    now[j] = {vec[i][j], j};
                }
            }else{
                sort(all(vec[i]));
                sort(all(now));
                reverse(all(now));
                vector<P> tmp = now;

                // cout << "i = " << i << endl;
                // rep(i, m){
                //     cout << tmp[i].first << " " << tmp[i].second << endl;
                // }
                // cout << "--" << endl;

                rep(j, m){

                    ans[i][tmp[j].second] = vec[i][j];
                    now[tmp[j].second] = {min(tmp[j].first, vec[i][j]), tmp[j].second};

                }

            }


        }

        rep(i, n){
            rep(j, m){
                if(j == 0){
                    cout << ans[i][j];
                }else{
                    cout << " " << ans[i][j];
                }
            }br;
        }
    }


}