#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
using namespace std;


int main() {
    ll h, w;
    cin >> h >> w;

    vector<vector<ll>> vec(2*h, vector<ll>(w));
    rep(i,h){
        rep(j,w){
            cin >> vec.at(i).at(j);
            vec.at(i+h).at(j) = vec.at(i).at(j);
        }
    }

    vector<ll> ans(w);
    ans.at(0) = 1;
    for(ll j = 1; j < w; j++){
        for(ll i = 0; i < h; i++){
            ll flag = 0;
            for(ll k = 0; k < h; k++){
                if(vec.at(k).at(0) != vec.at(k + i).at(j)){
                    flag = 1;
                }
            }
            if(flag == 0){
                ans.at(j) = 1;
            }
        }
    }


    rep(i,w){
        if(ans.at(i) == 0){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    
}