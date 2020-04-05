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
        ll n, m;
        cin >> n >> m;
        
        string s;
        cin >> s;

        vector<vector<ll>> vec(n, vector<ll>(26));
        rep(i,n){
            rep(j,26){
                if(i != 0){
                    vec[i] = vec[i-1];
                }
            }
            ll tmp = (int)s.at(i) - 97;
            vec[i][tmp] += 1;
        }

        vector<ll> ans(26);

        rep(i,m){
            ll tmp;
            cin >> tmp;
            tmp--;
            rep(j,26){
                ans[j] += vec[tmp][j];
            }
        }

        rep(j,26){
            ans[j] += vec[n-1][j];
        } 

        rep(i,26){
            cout << ans[i] << " ";
        }
        cout << endl;
        


    }
    
    


}