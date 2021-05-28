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

ld dp[110][62][40][28];

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, d; cin >> n >> d;
    ll NI = 0, SAN = 0, GO = 0;
    while(true){
        if(d % 2 == 0){
            NI++; d /= 2;
        }else{
            break;
        }
    }
    while(true){
        if(d % 3 == 0){
            SAN++; d /= 3;
        }else{
            break;
        }
    }
    while(true){
        if(d % 5 == 0){
            GO++; d /= 5;
        }else{
            break;
        }
    }

    if(d != 1){
        cout << 0 << endl; return 0;
    }

    dp[0][0][0][0] = 1;

    for(ll i = 0; i < n; i ++){


        for(ll ni = 0; ni <= 60; ni++){
            for(ll san = 0; san <= 38; san++){
                for(ll go = 0; go <= 26; go++){
                    //1
                    dp[i+1][ni][san][go] += dp[i][ni][san][go] * (ld)1 / (ld)6;
                    //2
                    dp[i+1][min((ll)60, ni+1)][san][go] += dp[i][ni][san][go] * (ld)1 / (ld)6;
                    //3
                    dp[i+1][ni][min((ll)38, san+1)][go] += dp[i][ni][san][go] * (ld)1 / (ld)6;
                    //4
                    dp[i+1][min((ll)60, ni+2)][san][go] += dp[i][ni][san][go] * (ld)1 / (ld)6;
                    //5
                    dp[i+1][ni][san][min((ll)26, go+1)] += dp[i][ni][san][go] * (ld)1 / (ld)6;
                    //6
                    dp[i+1][min((ll)60, ni+1)][min((ll)38, san+1)][go] += dp[i][ni][san][go] * (ld)1 / (ld)6;
                }
            }
        }

    }

    ld ans = 0;
    for(ll i = NI; i <= 60; i++){
        for(ll j = SAN; j <= 38; j++){
            for(ll k = GO; k <= 26; k++){
                ans += dp[n][i][j][k];
            }
        }
    }
    cout << ans << endl;

}