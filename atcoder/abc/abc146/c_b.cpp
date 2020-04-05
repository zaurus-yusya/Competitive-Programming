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
long long d(long long N){
    long long res=0;
    while(N>0){
        res++;
        N/=10;
    }
    return res;
}

int main() {
    ll a, b, x;
    cin >> a >> b >> x;

    //10億買えたら10が答え
    if(a * 1e9 + b * 10 <= x){
        cout << 1000000000 << endl;
        return 0;
    }

    ll left = 0;
    ll right = 1000000000;

    while(right - left > 1){
        ll mid = (right + left) / 2;
        if(a * mid + b * d(mid) <= x){
            left = mid;
        }else{
            right = mid;
        }
    }

    cout << left << endl;

}
