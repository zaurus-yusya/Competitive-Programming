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
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    string s, t; cin >> s >> t;
    ll s_size = s.size(), t_size = t.size();

    vector<vector<ll>> dp(s_size+1, vector<ll>(t_size+1));
    
    for(ll i = 0; i < s_size; i++){
        for(ll j = 0; j < t_size; j++){
            if(s[i] == t[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            }else{
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    ll i = s_size, j = t_size;
    string ans = "";
    while(i > 0 && j > 0){
        if(dp[i][j] == dp[i-1][j]){
            i--;
        }else if(dp[i][j] == dp[i][j-1]){
            j--;
        }else{
            ans = s[i-1] + ans;
            i--; j--;
        }
    }

    cout << ans << endl;

}