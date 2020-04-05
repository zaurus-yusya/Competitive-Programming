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

ll least_common_multiple(ll a, ll b){
    ll x = a * b;
    if(a < b){
        ll tmp = a;
        a = b;
        b = tmp;
    }
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return x / b;
}


int main() {
    ll n, m;
    cin >> n >> m;

    ll less_common = 1;
    rep(i,n){
        ll tmp;
        cin >> tmp;
        if(tmp % 2 != 0){
            continue;
        }
        tmp /= 2;
        less_common = least_common_multiple(less_common, tmp);
    }

    if((m / less_common) % 2 == 0){
        cout << m / less_common / 2 << endl;
    }else{
        cout << (m / less_common / 2) + 1 << endl;
    }

}
