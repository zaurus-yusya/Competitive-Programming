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
    string n;
    cin >> n;
    ll k;
    cin >> k;

    ll dp[110][2][k+1];

    dp[0][0][0] = 1;

    for(ll i = 0; i < n.size(); i++){
        for(ll smaller = 0; smaller < 2; smaller++){
            for(ll y = 0; y < k; y++){
                ll tmp = n[i] - 48;
                for(ll x = 0; x <= (smaller ? 9 : tmp); x++){
                    if(x == 0){
                        cout << " ok " << endl;
                        dp[i+1][smaller || x < tmp][y] += dp[i][smaller][y];
                    }else{
                        cout << " okok " << endl;
                        dp[i+1][smaller || x < tmp][y+1] += dp[i][smaller][y];
                    }
                }
                cout << "i + 1 = " << i+1 << " smaller = " << smaller << " " << dp[i+1][smaller][y] << endl;
            }
        }
    }

    cout << dp[n.size()][0][k] << endl;
    cout << dp[n.size()][1][k] << endl;


}