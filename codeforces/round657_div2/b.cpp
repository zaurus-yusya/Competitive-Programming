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
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll l, r, m; cin >> l >> r >> m;
        ll sa = r - l;
        if(l == 1){
            cout << l << " " << l << " " << l << endl;

        }else if(sa == 0){
            cout << l << " " << l << " " << l << endl;
        }else{
            for(ll i = l; i <= r; i++){
                ll sho = m / i;
                ll amari = m % i;
                if(sho > 0){
                         
                        if(0 <= (sho + 1) * i - m && (sho + 1) * i - m <= sa){
                            cout << i << " " << l << " " << l+((sho + 1) * i - m) << endl;
                            break;
                        }

                        if(amari <= sa){
                            cout << i << " " << l+amari << " " << l << endl;

                            break;
                        }
                    
                }else{
                    if(0 <= i - m && i - m <= sa){
                        cout << i << " " << l << " " << l+(i-m) << endl;

                        break;
                    }
                }
            }
        }

    }

}