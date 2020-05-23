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
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, l; cin >> n >> l;
    vector<long long> hurdle(100010);
    for(long long i = 0; i < n; i ++){
        ll tmp; cin >> tmp;
        hurdle[tmp] = 1;
    }
    ll t1, t2, t3; cin >> t1 >> t2 >> t3;

    vector<ll> dp(100010, INF);
    dp[0] = 0;

    vector<ll> dis = {1, 2, 4};
    vector<ll> time = {t1, t1+t2, t1+3*t2};
    rep(i,l+1){

        rep(j, 3){
            if(i - dis[j] < 0){
                continue;
            }else{
                if(hurdle[i] == 1){
                    dp[i] = min(dp[i], dp[i - dis[j]] + time[j]+t3);
                }else{
                    dp[i] = min(dp[i], dp[i - dis[j]] + time[j]);
                }
            }
        }

        if(i == l){
            //1
            dp[i] = min(dp[i], dp[i - 1] + t1);
            dp[i] = min(dp[i], dp[i - 1] + t1/2 + t2/2);
            //2
            dp[i] = min(dp[i], dp[i - 2] + t1/2 + t2*3/2);
            //3
            dp[i] = min(dp[i], dp[i - 3] + t1/2 + t2*5/2);
        }
    }

    cout << dp[l] << endl;
    
}