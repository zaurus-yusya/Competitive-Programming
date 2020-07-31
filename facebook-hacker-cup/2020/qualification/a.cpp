#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll x; cin >> x;
    rep(X, x){
        ll n; cin >> n;
        string s, t; cin >> s >> t;
        vector<vector<char>> ans(n, vector<char>(n, 'Y'));

        for(ll i = 0; i < n; i++){
            for(ll j = i+1; j < n; j++){
                if(ans[i][j-1] == 'N'){
                    ans[i][j] = 'N';
                }else{
                    if(s[j] == 'Y' && t[j-1] == 'Y'){
                        ans[i][j] = 'Y';
                    }else{
                        ans[i][j] = 'N';
                    }
                }
            }
        }

        for(ll i = n-1; i >= 0; i--){
            for(ll j = i-1; j >= 0; j--){
                if(ans[i][j+1] == 'N'){
                    ans[i][j] = 'N';
                }else{
                    if(s[j] == 'Y' && t[j+1] == 'Y'){
                        ans[i][j] = 'Y';
                    }else{
                        ans[i][j] = 'N';
                    }
                }
            }
        }

        cout << "Case #" << X+1 << ":" << endl;
        rep(i, n){
            rep(j, n){
                cout << ans[i][j];
            }
            br;
        }
    }

}