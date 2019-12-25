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

bool cmp(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first == b.first){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>> red(n);
    vector<pair<ll,ll>> blue(n);

    rep(i,n){
        ll x, y;
        cin >> x >> y;
        red.at(i) = make_pair(x, y);
    }
    rep(i,n){
        ll x, y;
        cin >> x >> y;
        blue.at(i) = make_pair(x, y);
    }

    sort(all(red), cmp);
    sort(all(blue), cmp);

    /*
    rep(i, red.size()){
        cout << red.at(i).first << " " << red.at(i).second << endl;
    }
    */

    ll ans = 0;
    rep(i,red.size()){
        rep(j, blue.size()){
            if(red.at(i).first < blue.at(i).first && red.at(i).second < blue.at(i).second){
                ans++;
                blue.at(i).first = -1;
                blue.at(i).second = -1;
            }
        }
    }

    cout << ans << endl;

}
