#include <bits/stdc++.h>
#include <atcoder/all>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
using namespace atcoder;
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
// If the result in local and judge is different, USE CODETEST!!

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll h, w; cin >> h >> w;
    vector<vector<ll>> vec(h, vector<ll>(w));
    rep(i, h){
        rep(j, w){
            cin >> vec[i][j];
        }
    }

    vector<pair<ll, ll>> from;
    vector<pair<ll, ll>> to;

    for(ll i = 0; i < h; i++){
        if(i % 2 == 0){
            for(ll j = 0; j < w; j++){
                if(vec[i][j] % 2 == 1){
                    if(i == h-1 && j == w-1) continue;
                    if(j == w-1){
                        from.push_back({i, j});
                        to.push_back({i+1, j});
                        vec[i+1][j] += 1;
                    }else{
                        from.push_back({i, j});
                        to.push_back({i, j+1});
                        vec[i][j+1] += 1;
                    }
                }
            }
        }else{
            for(ll j = w-1; j >= 0; j--){
                if(vec[i][j] % 2 == 1){
                    if(i == h-1 && j == 0) continue;
                    if(j == 0){
                        from.push_back({i, j});
                        to.push_back({i+1, j});
                        vec[i+1][j] += 1;  
                    }else{
                        from.push_back({i, j});
                        to.push_back({i, j-1});
                        vec[i][j-1] += 1;  
                    }
                }
            }
        }
    }

    cout << from.size() << endl;
    rep(i, from.size()){
        cout << from[i].first+1 << " " << from[i].second+1 << " " << to[i].first+1 << " " << to[i].second+1 << "\n";
    }

}