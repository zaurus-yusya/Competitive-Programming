#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e9;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);

    string s; cin >> s;
    ll size = s.size();

    ll dp[size + 1][2][size + 1]; //kは状況に応じてsize+1じゃない値になる
    rep(i, size+1){
        rep(j, 2){
            rep(k, size+1){
                dp[i][j][k] = 0;
            }
        }
    }

    dp[0][0][0] = 1;

    for(ll i = 0; i < size; i++){
        ll D = s[i] - '0';
        for(ll j = 0; j < 2; j++){
            for(ll k = 0; k < size+1; k++){
                for(ll d = 0; d <= (j ? 9 : D); d++){

                }
            }
        }
    }
    

}