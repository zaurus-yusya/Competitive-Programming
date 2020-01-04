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
    ll n;
    cin >> n;

    ll ans = 0;

    vector<ll> vec;

    ll tmp = 1;
    vec.pb(1);
    while(true){
        if(tmp * 6 <= 100000){
            tmp *= 6;
            vec.pb(tmp);
        }else{
            break;
        }
    }
    tmp = 1;
    while(true){
        if(tmp * 9 <= 100000){
            tmp *= 9;
            vec.pb(tmp);
        }else{
            break;
        }
    }

    sort(all(vec),greater<ll>());

    vector<ll> dp(n+1, INF);
    dp.at(0) = 0;
    rep(i,n+1){
        rep(j,vec.size()){
            if(i - vec.at(j) >= 0){
                chmin(dp.at(i), dp.at(i-vec.at(j)) + 1);
            }
        }
    }

    cout << dp.at(n) << endl;

}
