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


int main() {
    ll h, n;
    cin >> h >> n;
    vector<pair<ll,ll>> vec2(n);
    ll max = 0;
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        vec2.at(i) = make_pair(a,b);
        chmax(max, vec2.at(i).first);
    }

    cout << max << endl;

    vector<ll> dp(1000100, INF);

    ll flag = 0;
    while(true){
        rep(i, max + 1){
            if(flag == 0){
                flag = 1;
                rep(j, n){
                    dp[vec2.at(j).first] = vec2.at(j).second;
                }
            }else{
                if(dp[i] != 0){
                    rep(j,n){
                        chmin(dp[i + vec2.at(j).first], dp[i] + vec2.at(j).second);
                    }
                }
            }
        }
        max += max;
    }
    

    rep(i,20){
        cout << "i = " << i << " " << dp[i] << endl;
    }
    

}
