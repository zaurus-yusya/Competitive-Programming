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

ll func(ll a, ll b){
    ll tmp, r;
    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }
    ll tmp_a = a;
    ll tmp_b = b;
    r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
    return (tmp_a / b) * tmp_b;
}

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
    vector<ll> vec(n);

    ll saisyo_kobaisu = 1;
    rep(i,n){
        cin >> vec.at(i);
        
        //saisyo_kobaisu %= MOD;
    }

    sort(all(vec));

    rep(i,n){
        saisyo_kobaisu = func(saisyo_kobaisu, vec.at(i));
    }

    //cout << saisyo_kobaisu << endl;
    
    ll ans = 0;
    rep(i,n){
        //ans = (ans % MOD + (saisyo_kobaisu / vec.at(i)) % MOD) % MOD;
        ans = (ans % MOD + ((saisyo_kobaisu % MOD ) * modinv(vec.at(i), MOD))) % MOD;
    }

    cout << ans % MOD << endl;

}
