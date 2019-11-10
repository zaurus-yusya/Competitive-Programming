#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define repr(i,n) for(int i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;

int main() {
    ll sub = 998244353;
    ll n;
    cin >> n;

    vector<ll> vec(n);
    map<int,int> mp;
    ll tmp = 0;
    rep(i,n){
        cin >> vec.at(i);
        mp[vec.at(i)]++;
        if(tmp < vec.at(i)){
            tmp = vec.at(i);
        }
    }

    if(vec.at(0) != 0){
        cout << 0 << endl;
        return 0;
    }
    if(mp[0] > 1){
        cout << 0 << endl;
        return 0;
    }
    rep(i,tmp){
        if(mp[i] == 0){
            cout << 0 << endl;
            return 0;
        }
    }

    ll ans = 1;
    ll tmp2 = 1;
    rep(i,tmp){
        tmp2 = 1;
        if(i==0){
            continue;
        }
        rep(j, mp[i+1]){
            tmp2 = tmp2  * mp[i] % sub;
            //ans *= mp[i] % sub;
        }
        ans = ans * tmp2 % sub;
        //cout << "tmp2 = " << tmp2 << endl;
        //cout << "ans = " << ans << endl;
    }

    cout << ans << endl;

}
