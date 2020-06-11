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
    if(a.second == b.second){
        return a.first > b.first;
    }else{
        return a.second > b.second;
    }
}

bool cmp2(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first == b.first){
        return a.second > b.second;
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
    sort(all(blue));
    
    
    ll ans = 0;
    vector<ll> res_r(n, 0);
    vector<ll> res_b(n, 0);
    rep(j ,blue.size()){
        rep(i, red.size()){
            if(res_r[i] == 1){
                continue;
            }
            if(res_b[j] == 1){
                break;
            }
            if(red.at(i).first < blue.at(j).first && red.at(i).second < blue.at(j).second){
                ans++;
                res_r[i] = 1;
                res_b[j] = 1;
            }
        }
    }

    cout << ans << endl;
    

}
