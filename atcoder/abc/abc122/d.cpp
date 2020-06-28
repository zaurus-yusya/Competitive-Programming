#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
template<class T>
vector<T> make_vec(size_t a){ return vector<T>(a);}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){ return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// auto dp = make_vec<ll>(n+1, 5, 5, 5);

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n;
    vector<char> mozi = {' ', 'A', 'C', 'G', 'T'};
    auto dp = make_vec<ll>(n+1, 5, 5, 5);
    dp[0][0][0][0] = 1;

    // AGC  GAC  ACG  A?GC  AG?C
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < 5; j++){ //3文字前
            for(ll k = 0; k < 5; k++){ //2文字前
                for(ll l = 0; l < 5; l++){ //1文字前
                    for(ll m = 1; m < 5; m++){ //今の文字
                        dp[i+1][][][] = dp[i][][][];  // AGC 
                    }
                }
            }
        }
    }

}