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
    vector<vector<ll>> dp(n+1, vector<ll>(w+1));

    rep(i,n){
        cin >> weight.at(i) >> value.at(i);
    }

    rep(i,n){
        for(ll sum_w = 0; sum_w <= w; sum_w++){
            if(sum_w - weight.at(i) >= 0){
                chmax(dp.at(i+1).at(sum_w), dp.at(i).at(sum_w - weight.at(i)) + value.at(i));
            }
            
            chmax(dp.at(i+1).at(sum_w), dp.at(i).at(sum_w));
        }
    }

    cout << dp.at(n).at(w) << endl;

}
