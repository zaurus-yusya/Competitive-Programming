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


int main() {
    ll x;
    cin >> x;

    rep(i,1000){

        if((x >= (i+1)*100) && (x <= (i+1)*105)){
            cout << 1 << endl;
            return 0;
        }

    }
    
    cout << 0 << endl;


}
