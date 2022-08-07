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
    ll n, w;
    cin >> n >> w;
    vector<ll> weight(n);
    vector<ll> value(n);
    rep(i,n){
        cin >> weight.at(i) >> value.at(i);
    }

    vector<vector<ll>> dp(n+1, vector<ll>(100001));
    rep(i,n+1){
        rep(j,100001){
            dp.at(i).at(j) = 1e10;
        }
    }

    dp.at(0).at(0) = 0;

    rep(i,n){
        for(ll sum_v = 0; sum_v <= 100000; sum_v++){
            if(sum_v - value.at(i) >= 0){
                chmin(dp.at(i+1).at(sum_v), dp.at(i).at(sum_v - value.at(i)) + weight.at(i));
            }

            chmin(dp.at(i+1).at(sum_v), dp.at(i).at(sum_v));
        }
    }

    ll res = 0;
    rep(i,100001){
        if(dp.at(n).at(i) <= w) res = i;
    }
    cout << res << endl;

}
