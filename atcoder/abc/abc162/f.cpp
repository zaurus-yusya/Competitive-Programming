#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const ll INF = 1e15;
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
    ll n;
    cin >> n;
    vector<long long> vec(n);
    ll minimum = INF;

    
    rep(i, n){
        cin >> vec[i];
        chmin(minimum, vec[i]);
    }
    /*
    if(minimum < 0){
        rep(i, n){
            vec[i] -= minimum;
        }
    }else{
        minimum = 0;
    }
    */


    
    /*
    if(n % 2 == 0){
        rep(i,n){
            if(i >= 1 && i % 2 == 1){
                ans += vec[i];
            }
            
        }
    }else{
        rep(i,n){
            if(i >= 2 && i % 2 == 0){
                ans += vec[i];
            } 
        }
    }
    */

    
    
    vector<vector<ll>> dp(n+1, vector<ll>(3));
    ll tmp_min = INF;


    if(n % 2 == 0){
        ll ans_0 = 0;
        ll ans_1 = 0;
        rep(i,n){
            if(i % 2 == 0){
                ans_0 += vec[i];
            }else{
                ans_1 += vec[i];
            }
        }

        cout << max(ans_0, ans_1) << endl;
        
    }else{
        // n >= 7
        // 2個とばし2回
        // 2個とばし1回
        ll ans = 0;
        dp[0][0] = vec[0];
        
        rep(i,n){
            if(i % 2 == 0){
                chmin(tmp_min, vec[i]);
            }
            if(i == 0) continue;
            if(i == 1) continue;
            
            rep(j,3){
                //1個とばし
                //dp[i][j] = dp[i-2] + vec[i][j];
                if(i - 2 >= 0){
                    chmax(dp[i][j], dp[i-2][j] + vec[i]);
                }
                
                //2個とばし
                if(j >= 1 && i - 3 >= 0){
                    //dp[i][j] = dp[i-3] + vec[i][j-1];
                    chmax(dp[i][j], dp[i-3][j-1] + vec[i]);
                }
                //3個とばし
                if(j >= 2 && i - 4 >= 0){
                    //dp[i][j] = dp[i-4] + vec[i][j-2];
                    chmax(dp[i][j], dp[i-4][j-2] + vec[i]);
                } 
            }
        }

        chmax(ans, dp[n-1][0] - tmp_min);
        chmax(ans, dp[n-1][1]);
        chmax(ans, dp[n-1][2]);
        cout << ans << endl;
    }


    
    /*
    cout << dp[n-1][0] - vec[0] - minimum<< endl;
    cout << dp[n-1][1] - minimum << endl;
    cout << dp[n-1][2] - minimum << endl;
    */







}