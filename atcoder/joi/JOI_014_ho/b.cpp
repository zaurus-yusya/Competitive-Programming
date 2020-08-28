#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
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

ll n;
vector<long long> vec(n+1);
vector<vector<ll>> dp(n+1, vector<ll>(n+1));


ll calc_sec(ll l, ll r){
    if(dp[l][r] != -1){
        return dp[l][r];
    }
    if(l == r){
        dp[l][r] = vec[l];
        return dp[l][r];
    }
    if(r - l == 1){
        ll tmp = max(vec[l], vec[r]);
        dp[l][r] = tmp;
        return dp[l][r];
    }

    ll res = 0;

    for(ll mid = l; mid < r; mid++){
        res = max(res, calc_sec(l,mid) + calc_sec(mid+1,r));
    }
    
    dp[l][r] = res;
    return res;
}


int main() {
    std::cout << std::fixed << std::setprecision(15);
    
    cin >> n;
    vec.resize(2*n+1);
    rep(i, n){
        cin >> vec[i]; vec[i+n] = vec[i];
    }
    dp.resize(n+1, vector<ll>(n+1));
    dp.assign(n+1, vector<ll>(n+1, -1));

    cout << calc_sec(0,n-1) << endl;


}