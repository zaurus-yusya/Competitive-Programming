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

// 0 false, 1 true 
// string to int : -48
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    ll t;
    cin >> t;

    rep(i,t){
        string s;
        cin >> s;
        ll n = s.size();

        ll count = 0;
        ll ans = 0;
        for(ll j = 0; j < s.size(); j++){
            if(s.at(j) == 'L'){
                count++;
                if(ans < count){
                    ans = count;
                }
            }
            if(s.at(j) == 'R'){
                count = 0;
            }
        }
        
        cout << ans + 1 << endl;

    }

}