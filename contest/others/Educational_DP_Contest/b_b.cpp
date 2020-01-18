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
    ll n, k;
    cin >> n >> k;
    vector<ll> vec(n);
    rep(i,n){
        cin >> vec.at(i);
    }


    vector<ll> dp(n,INF);

    rep(i,n){
        if(i==0){
            dp.at(i) = 0;
            continue;
        }
        for(ll j = i - k; j < i; j++){
            if(j < 0) continue;
            chmin(dp.at(i), dp.at(j) + abs(vec.at(i) - vec.at(j)));
        }
    }

    cout << dp.at(n-1) << endl;
    
}
