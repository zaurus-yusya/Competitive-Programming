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
        ll S, D;
        cin >> S >> D;
        vector<long long> vec(S);
        map<ll,ll, greater<ll>> mp;
        for(long long i = 0; i < S; i ++){
            cin >> vec[i];
            mp[vec[i]]++;
        }

        sort(all(vec));
        ll ans = INF;

        
        /*
        for(auto i: mp){
            cout << i.first << " " << i.second << endl;
        }
        */


        
        vector<pair<ll,ll>> tmp;
        for(auto i: mp){
            sort(all(tmp));
            if(i.second >= D){
                ans = 0;
                break;
            }else{
                ll now = i.second;
                ll cutnum = 0;
                ll zouka = 0;
                ll konokai = 0;
                rep(j,tmp.size()){
                    //cout << tmp[j].first << endl;
                    
                    konokai += (tmp[j].first / i.first) * tmp[j].second;

                    zouka += konokai;
                    //cout << tmp[j].second << " " << tmp[j].first << endl;
                    if(tmp[j].first % i.first == 0){
                        cutnum = konokai - (1 * tmp[j].second);
                    }else{
                        cutnum = konokai;
                    }

                    if(now + zouka >= D){
                        break;
                    }

                }

                if(now + zouka >= D){
                    ans = min(ans, (ll)D - now);
                }else{

                }

                /*
                if(now + can >= D){
                    ans = min(ans, (ll)D - now);
                    cout << i.first << " y " << ans << endl;
                }else{
                    cout << i.first << endl;
                }
                */
                tmp.push_back(make_pair(i.first, i.second));
            }
        }
        
        

        cout << "Case #" << t+1 << ": " << ans << endl;

    }

}