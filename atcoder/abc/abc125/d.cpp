#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << endl;
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// stringの数字をint型にしてアスキーコードになったら -48する
// 切り上げ　ceil(a)
// コンパイル　g++ -std=c++17 a.cpp

int main() {
    ll n;
    cin >> n;
    vector<ll> vec(n);
    rep(i, n) cin >> vec.at(i);

    ll dp[n+1][2] = {0};
    dp[0][0] = vec.at(0);
    dp[0][1] = vec.at(0) * (-1);
    rep(i,n-1){
        dp[i+1][0] = max(dp[i][0] + vec.at(i+1), dp[i][1] - vec.at(i+1));
        dp[i+1][1] = max(dp[i][0] - vec.at(i+1), dp[i][1] + vec.at(i+1));
    }

    cout << dp[n-1][0] << endl;

}