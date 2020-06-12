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
    ll n; cin >> n;
    vector<ll> vec(394); 
    rep(i, n){
        ll s, l, p; cin >> s >> l >> p;
        for(ll j = s; j <= l; j++){
            vec[j] = max(vec[j], p);
        }
    }
    vector<pair<ll,ll>> vec2; 
    
    rep(i, 394){
        if(vec[i] > 0){
            vec2.push_back(make_pair(i, vec[i]));
        }
    }

    vector<vector<ll>> dp(vec2.size()+1, vector<ll>(394, -1));
    dp[0][0] = 0;
    dp[1][0] = 0;

    for(ll i = 0; i < vec2.size(); i++){
        for(ll j = 0; j <= 393; j++){
            if(j - vec2[i].first >= 0 && dp[i + 1][j - vec2[i].first] != -1){
                dp[i+1][j] = max(dp[i][j], dp[i + 1][j - vec2[i].first] + vec2[i].second);
            }else{
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            }
        }
    }

    ll m; cin >> m;
    vector<ll> ans;
    rep(i, m){
        ll w; cin >> w;
        ans.push_back(dp[vec2.size()][w]);
        
        if(dp[vec2.size()][w] == -1){
            cout << -1 << endl;
            return 0;
        }
        
    }
    
    rep(i, m){
        cout << ans[i] << endl;
    }
    

}