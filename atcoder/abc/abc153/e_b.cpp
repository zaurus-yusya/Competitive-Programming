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
    vector<ll> a(n);
    vector<ll> b(n);

    rep(i,n){
        cin >> a.at(i) >> b.at(i);
    } 

    vector<ll> dp(h+1, INF);
    dp.at(0) = 0;
    rep(i,n){
        rep(j,h+1){
            ll tmp;
            if(j + a.at(i) > h){
                tmp = h;
            }else{
                tmp = j + a.at(i);
            }
            chmin(dp[tmp], dp[j] + b.at(i));
        }
    }

    cout << dp[h] << endl;
    

}
