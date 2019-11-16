#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
ll inf = 1000000007;


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
    ll x, y;
    cin >> x >> y;

    if((x+y)%3 != 0){
        cout << 0 << endl;
        return 0;
    }

    ll idou_kaisu = (x+y) / 3;

    ll x_kaisu = x - idou_kaisu;
    ll y_kaisu = y - idou_kaisu;

    ll num = min(x_kaisu, y_kaisu);

    if(x_kaisu < 0 || y_kaisu < 0){
        cout << 0 << endl;
        return 0;
    }

    ll bunshi = 1;
    ll bunbo = 1;
    rep(i,num){
        bunshi = (bunshi * (idou_kaisu - i)) % inf;
    }
    rep(i,num){
        bunbo = (bunbo * (i+1)) % inf;
    }

    bunshi %= inf;
    cout << bunshi * modinv(bunbo, inf) % inf << endl;

}
