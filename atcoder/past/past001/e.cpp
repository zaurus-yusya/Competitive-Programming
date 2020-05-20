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
    ll n, q; cin >> n >> q;
    vector<vector<string>> vec(n, vector<string>(n));
    rep(i,n){
        rep(j,n){
            vec[i][j] = "N";
        }
    }

    rep(i,q){
        ll s; cin >> s;
        if(s == 1){
            ll a, b; cin >> a >> b;
            a--; b--;
            vec[a][b] = "Y";
        }
        if(s == 2){
            ll a; cin >> a;
            a--;
            rep(j, n){
                if(vec[j][a] == "Y"){
                    vec[a][j] = "Y";
                }
            }
        }
        if(s == 3){
            ll a; cin >> a;
            a--;
            vector<ll> res;
            rep(j, n){
                if(vec[a][j] == "Y"){
                    rep(k, n){
                        if(vec[j][k] == "Y"){
                            res.push_back(k);
                        }
                    }
                }
            }
            rep(j, res.size()){
                if(res[j] != a){
                    vec[a][res[j]] = "Y";
                }
            }
        }
    }

    rep(i,n){
        rep(j,n){
            cout << vec[i][j];
        }
        cout << endl;
    }

}