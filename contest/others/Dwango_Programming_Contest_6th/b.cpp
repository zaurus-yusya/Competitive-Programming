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

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}


int main() {
    ll n;
    cin >> n;
    
    vector<ll> x(n);
    rep(i,n){
        cin >> x.at(i);
    }

    
    ll count = 1;

    ll kaijo = 1;
    for(ll i = 1; i <= n-1; i++){
        kaijo *= i % MOD;
    }

    ll ans = 0;

    for(ll i = n-1; i > 0; i--){
        ans += (x.at(i) - x.at(i-1)) * kaijo / count;
        //ans += ( ((x.at(i) - x.at(i-1)) % MOD) * (kaijo * modinv(count, MOD) % MOD) ) % MOD;
        cout << ans << endl;
        count++;
    }


    cout << ans << endl;
    




    

    

}
