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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m;
    cin >> n >> m;
    
    vector<vector<pair<ll,ll>>> vec(11);
    
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < m; j++){
            char c; cin >> c;
            ll tmp = (ll)c - 48;
            for(ll k = 0; k < 9; k++){
                if(tmp == k+1){
                    vec[k+1].push_back({i,j});
                }
            }
            if(tmp == 35){
                vec[0].push_back({i,j});
            }
            if(tmp == 23){
                vec[10].push_back({i,j});
            }
        }
    }
    
    ll ans = 0;
    ll dp[12][2510];
    rep(i,12){
        rep(j,2510){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(ll i = 1; i <= 10; i++){
        
        if(vec[i].size() == 0){
            cout << -1 << endl;
            return 0;
        }
        for(ll j = 0; j < vec[i].size(); j++){
            for(ll k = 0; k < vec[i-1].size(); k++){
                chmin(dp[i][j], dp[i-1][k] + ( abs(vec[i][j].first - vec[i-1][k].first) + abs(vec[i][j].second - vec[i-1][k].second) ) );
            }
        }

    }

    cout << dp[10][0] << endl;
    


}