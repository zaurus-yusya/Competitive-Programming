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
    vector<ll> x(n);
    vector<ll> y(n);
    rep(i,n){
        cin >> x.at(i);
        cin >> y.at(i);
    }

    double ans = 0;
    rep(i,n){
        for(ll j = i+1; j < n; j++){
            double tmp;
            tmp = sqrt( (x.at(i) - x.at(j))*(x.at(i) - x.at(j)) + (y.at(i) - y.at(j))*(y.at(i) - y.at(j)) );
            chmax(ans, tmp);
        }
    }
    
    cout << fixed << setprecision(6) << ans << endl;

}
