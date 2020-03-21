#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
vector<pair<ll,ll>> vec;
ll ans = 0;

void bit_full_research(int n, int m){
    
    for(int bit = 0; bit < (1 << n); bit++){
        vector<ll> res;
        for(int i = 0; i < n; i++){
            if(bit & (1 << i)){
                res.pb(i);
            }
        }
    

        bool flag = true;

        /*
        rep(i,res.size()){
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "---------" << endl;
        cout << "res_size = " << res.size() << endl;
        */

        for(int i = 0; i < (int)res.size() - 1; i++){
            for(int j = i+1; j < (int)res.size(); j++){
                bool flag2 = false;
                for(int k = 0; k < m; k++){

                    //cout << res[i] << " " << res[j] << endl;
                    if(res[i] == vec[k].first && res[j] == vec[k].second){
                        flag2 = true;
                    }

                }
                if(flag2 == false){
                    //cout << "false" << endl;
                    flag = false;
                }
            }
        }

        //cout << "--------------------" << endl;

        if(flag){
            //cout << "ok" << endl;
            ans = max(ans, (ll)res.size());
        }
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m;
    cin >> n >> m;

    if(m == 0){
        cout << 1 << endl;
        return 0;
    }

    vec.resize(m);
    rep(i, m){
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        vec[i] = make_pair(x, y);
    }


    bit_full_research(n, m);

    cout << ans << endl;


}