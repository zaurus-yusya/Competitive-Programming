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

ll n, k;

vector<ll> vec;
vector<ll> dp;

ll rec(ll i){
    if(dp.at(i) < INF) return dp.at(i);

    if(i == 0) return 0;

    ll tmp = INF;
    for(ll j = 1; j <= k; j++){
        if(i - j >= 0) chmin(tmp, rec(i - j) + abs( vec.at(i) - vec.at(i - j)));
    }

    return dp.at(i) = tmp;

}



int main() {
    ll x, y;
    cin >> x >> y;

    n = x;
    k = y;

    vec.resize(n);
    dp.assign(n,INF);
    
    rep(i,n){
        cin >> vec.at(i);
    }

    cout << rec(n-1) << endl;

}
