#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << endl;
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

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

    /*
    rep(i,2*h){
        rep(j,w){
            cout << vec.at(i).at(j);
        }
        cout << "" << endl;
    }
    */
    //cout << "------" << endl;
    

    
    vector<ll> first(h);
    rep(i,h){
        first.at(i) = vec.at(i).at(0);
    }

    vector<ll> ans(w);
    ans.at(0) = 1;
    for(ll j = 1; j < w; j++){
        for(ll i = 0; i < h; i++){
            ll flag = 0;
            for(ll k = 0; k < h; k++){
                //cout << first.at(i) << " " << vec.at(i+k).at(j) << endl;
                if(first.at(k) != vec.at(i+k).at(j)){
                    flag = 1;
                }
            }
            if(flag == 0){
                ans.at(j) = 1;
            }
        }
    }

    ll ans_flag = 0;
    rep(i,w){
        if(ans.at(i) == 0){
            ans_flag = 1;
            cout << "No" << endl;
            break;
        }
    }
    if(ans_flag == 0){
        cout << "Yes" << endl;
    }
    



}