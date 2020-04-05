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
    ll price;
    cin >> price;

    ll ans = 0;
    ll change = 1000 - price;

    vector<int> vec = {500, 100, 50, 10, 5, 1};
    ll i = 0;
    while(true){
        if(change == 0) break;

        if(change - vec.at(i) < 0){
            i++;
        }else{
            change -= vec.at(i);
            ans++;
        }
    }

    cout << ans << endl;

}
