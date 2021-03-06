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
// コンパイル　g++ -std=c++17 a.cpp

int main() {
    ll n;
    cin >> n;

    rep(i,n){
        ll m;
        cin >> m;

        vector<ll> vec(m);

        ll ans = 0;
        rep(j,m){
            cin >> vec.at(j);
            if(vec.at(j) == 0){
                vec.at(j)++;
                ans++;
            }
        }
        ll tmp = 0;
        rep(j,m){
            tmp += vec.at(j);
        }

        if(tmp == 0){
            cout << ans + 1<< endl;
        }else{
            cout << ans << endl;
        }
    }


}