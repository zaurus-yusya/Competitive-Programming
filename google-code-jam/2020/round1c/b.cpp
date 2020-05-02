#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll T;
    cin >> T;
    rep(t,T){
        ll U;
        cin >> U;
        vector<pair<ll, string>> vec(10000);
        vector<char> ans(10);
        rep(i,10000){
            ll m;
            string r;
            cin >> m >> r;
            vec[i] = make_pair(m, r);
        }

        sort(all(vec));

        ll count = 1;
        map<char, ll> mp;
        rep(i,10000){
            if(count < 10){
                if(vec[i].first == count){
                    if(mp.count(vec[i].second[0]) == 0){
                        mp[vec[i].second[0]]++;
                        ans[count] = vec[i].second[0];
                        count++;
                    }
                }
            }
            if(count == 10){
                if(vec[i].first == count){
                    if(vec[i].second.size() == 2){
                        ans[0] = vec[i].second[1];
                        break;
                    }
                }
            }
        }

        /*
        rep(i,10000){
            cout << vec[i].first << endl;
        }
        */

        /*
        rep(i,10000){
            if(vec[i].first >= 10 && vec[i].first <= 19){
                if(vec[i].second.size() == 2){
                    
                }
            }
        }
        */
        cout << "Case #" << t+1 << ": ";
        rep(i,10){
            cout << ans[i];
        }
        cout << endl;

    }

}