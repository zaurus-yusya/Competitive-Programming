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
    ll n;
    cin >> n;
    vector<ll> vec(n);
    vector<ll> ans;

    rep(i,n){
        cin >> vec.at(i);
    }

    rep(i,n){
        
        if(ans.size() == 0){
            ans.pb(vec.at(i));
            continue;
        }

        ll flag = 0;
        rep(j,ans.size()){
            if(vec.at(i) <= ans.at(j)){
                ans.at(j) = vec.at(i);
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            ans.pb(vec.at(i));
        }

    }

    cout << ans.size() << endl;

}
