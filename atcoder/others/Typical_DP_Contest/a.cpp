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

bool dp[110][10010];

int main() {
    ll n;
    cin >> n;
    vector<ll> vec(n);

    map<ll,ll> mp;
    mp.emplace(0,1);

    rep(i,n){
        ll num;
        cin >> num;
        vector<ll> tmp;
        for(auto x : mp){
            tmp.pb(x.first + num);
        }
        rep(j,tmp.size()){
            mp.emplace(tmp.at(j), 1);
        }
    }

    cout << mp.size() << endl;

}
