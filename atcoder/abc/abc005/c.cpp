#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
ll INF = 1000000007;
using Graph = vector<vector<ll>>;

// 0 false, 1 true 
// stringの数字をint型にしてアスキーコードになったら -48する


int main() {
    ll t, n, m;

    cin >> t;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a.at(i);
    }
    cin >> m;
    vector<ll> b(m);
    rep(i,m){
        cin >> b.at(i);
    }

    if(n < m){
        cout << "no" << endl;
        return 0;
    }

    ll tmp = 0;
    rep(i,m){ //kyaku
        ll flag = 0;
        for(ll j = tmp; j < n; j++){ //tako
            if(a.at(j) <= b.at(i) && a.at(j) + t >= b.at(i)){
                tmp = j + 1;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;

}
