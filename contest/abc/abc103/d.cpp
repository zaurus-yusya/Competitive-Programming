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
    return a.second < b.second;
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<pair<ll,ll>> vec(m);

    rep(i,m){
        ll a, b;
        cin >> a >> b;
        vec.at(i) = make_pair(a,b);
    }

    sort(all(vec), cmp);

    vector<ll> div;

    rep(i,m){

        if(div.size() == 0){
            div.pb(vec.at(i).second);
            continue;
        }

        ll flag = 0;

        rep(j, div.size()){
            if(vec.at(i).first < div.at(j) && vec.at(i).second >= div.at(j)){
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            div.pb(vec.at(i).second);
        }


    }

    cout << div.size() << endl;

}
