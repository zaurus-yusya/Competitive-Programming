#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
//#define mp make_pair
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
        ll n;
        cin >> n;
        vector<vector<ll>> vec(n, vector<ll>(n));
        rep(i,n){
            rep(j,n){
                cin >> vec[i][j];
            }
        }

        ll K = 0;
        ll R = 0;
        ll C = 0;

        rep(i,n){
            K += vec[i][i];
        }

        
        rep(i,n){
            map<ll,ll> mp;
            rep(j,n){
                if(mp[vec[i][j]] == 0){
                    mp[vec[i][j]]++;
                }else{
                    R += 1;
                    break;
                }
            }
        }

        rep(j,n){
            map<ll,ll> mp;
            rep(i,n){
                if(mp[vec[i][j]] == 0){
                    mp[vec[i][j]]++;
                }else{
                    C += 1;
                    break;
                }
            }
        }

        cout << "Case #" << t+1 << ": " << K << " " << R << " " << C << endl;

    }

}