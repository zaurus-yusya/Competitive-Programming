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

int main() {
    ll n;
    cin >> n;
    ll ans = 1;

    //odd
    if(n % 2 == 1){
        rep(i,n){
            //last
            if(i == 0) continue;
            if(i == n-2){
                ans = (ans * 2) % MOD;
                break;
            }
            if(i % 2 == 1){
                ans = (ans * (n-i)) % MOD;
            }
        }
    }
    
    //even
    if(n % 2 == 0){
        rep(i,n){
            if(i == 0){
                ans = (ans * n) % MOD;
                continue; 
            }
            if(i == n-2){
                ans = (ans * 2) % MOD;
                break;
            }
            if(i % 2 == 0){
                ans = (ans * (n-i)) % MOD;
            }
        }
    }



    cout << ans << endl;

}