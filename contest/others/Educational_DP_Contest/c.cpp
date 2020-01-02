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

vector<vector<ll>> vec(1, vector<ll>(3));
vector<vector<ll>> dp(1, vector<ll>(3));

int main() {
    ll n;
    cin >> n;

    vec.resize(n+1, vector<ll>(3));
    dp.resize(n+1, vector<ll>(3));

    rep(i,n){
        rep(j,3){
            cin >> vec.at(i).at(j);
        }
    }

    //dp配列だけ[1]は1日目。他は[0]が1日目
    for(ll i = 0; i < n; i ++){
        for(ll j = 0; j < 3; j++){
            for(ll k = 0; k < 3; k++){
                if(j == k) continue;
                chmax(dp.at(i + 1).at(k), dp.at(i).at(j) + vec.at(i).at(k));
            }
        }
    }

    ll res = 0;
    rep(i,3){
        chmax(res, dp.at(n).at(i));
    }
    cout << res << endl;

}
