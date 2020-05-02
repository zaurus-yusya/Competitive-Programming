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
        map<ll,ll> mp;
        for(long long i = 0; i < S; i ++){
            cin >> vec[i];
            mp[vec[i]]++;
        }

        sort(all(vec));
        ll ans = 2;
        if(D == 2){
            for(auto i: mp){
                if(i.second >= 2){
                    ans = min(ans, (ll)0);
                }else{
                    ans = min(ans, (ll)1);
                }
            }
        }

        if(D == 3){
            for(auto i: mp){
                if(i.second >= 3){
                    ans = min(ans, (ll)0);
                }else if(i.second == 2){
                    rep(j,vec.size()){
                        if(vec[j] > i.first){
                            ans = min(ans, (ll)1);
                        }
                    }
                }else{
                    if(mp.count(i.first * 2) >= 1){
                        ans = min(ans, (ll)1);
                    }
                }
            }
        }

        cout << "Case #" << t+1 << ": " << ans << endl;

    }

}