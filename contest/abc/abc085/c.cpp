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
    ll n, y;
    cin >> n >> y;
    n++;

    rep(i,n){
        rep(j,n-i){
            ll tmp = y - i * 10000 - j * 5000;
            if(tmp % 1000 == 0){
                if(i + j + tmp/1000 == n-1){
                    cout << i << " " << j << " " << tmp / 1000 << endl;
                    return 0;
                }
            }
        }
    }
    cout << "-1 -1 -1" << endl;


}
