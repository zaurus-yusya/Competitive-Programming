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
    ll a, b, x;
    cin >> a >> b >> x;

    //10億買えたら10が答え
    if(a * 1e9 + b * 10 <= x){
        cout << 1000000000 << endl;
        return 0;
    }

    ll max = 1e9;
    ll min = 0;
    while(max - min > 1){
        ll tmp = (max + min) / 2;
        ll d_tmp = to_string(tmp).size();

        if(a * tmp + b * d_tmp <= x){
            min = tmp;
        }else{
            max = tmp;
        }
    }
    cout << min << endl;

}
