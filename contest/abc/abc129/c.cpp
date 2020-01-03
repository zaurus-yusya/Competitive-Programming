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
    ll n, m;
    cin >> n >> m;
    vector<ll> vec(m);
    rep(i,m){
        cin >> vec.at(i);
    }

    vector<ll> dp(n+1);
    dp.at(0) = 1;

    ll tmp = 0;
    rep(i,n+1){
        if(i == 1){
            if(tmp < m && vec.at(tmp) == 1){
                tmp++;
                continue;
            }else{
                dp.at(1) = 1;
                continue;
            }
        }
        if(tmp < m && i == vec.at(tmp)){
            tmp++;
            continue;
        }
        if(i >= 2){
            dp.at(i) = dp.at(i-1) % MOD + dp.at(i-2) % MOD;
            dp.at(i) = dp.at(i) % MOD;
        } 
    }

    cout << dp.at(n) << endl;

}
