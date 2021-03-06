#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, w;
    cin >> n >> w;

    vector<ll> weight(n);
    vector<ll> value(n);
    vector<vector<ll>> dp(n+1, vector<ll>(w+1));
    

    rep(i,n){
        cin >> value[i] >> weight[i];
    }
    
    rep(i, n){

        for(ll j = 0; j <= w; j++){
            if(j - weight[i] >= 0){
                chmax(dp[i+1][j], dp[i][j-weight[i]] + value[i]); 
            }
            chmax(dp[i+1][j], dp[i][j]); 
        }
    }
    
    
    

    cout << dp[n][w] << endl;


}