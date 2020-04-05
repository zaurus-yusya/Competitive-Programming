#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
ll INF = 1000000007;

// 0 false, 1 true


int main() {
    ll a, b, x;
    cin >> a >> b >> x;

    if(a*1 + b*1 > x){
        cout << 0 << endl;
        return 0;
    }

    ll tmp = 0;
    ll ans = 0;
    ll tmp2 = 0;
    rep(i,10){
        //各桁の最小を調べる
        if(a * pow(10,i) + b * (i+1) > x){
            //cout << "i = " << i << endl;  
            continue;
        }

        //OKなら調べる
        ll b_keta = (b * (i+1));
        ll x_tmp = x - b_keta;
        ll a_tmp = x_tmp / a;  //ans候補

        

        ans = a_tmp;
        if(a_tmp >= pow(10,i+1)){
            ans = pow(10,i+1) - 1;
        }

        //cout << std::setprecision(20) << a_tmp << endl;
    }

    if(ans > 1000000000){
        cout << 1000000000 << endl;
    }else{
        cout << std::setprecision(20) << ans << endl;
    }


}
