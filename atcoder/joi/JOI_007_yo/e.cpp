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

ll r, c;
vector<vector<ll>> vec(r, vector<ll>(c));
ll ans = 0;

void bit_search(ll r, ll c){
    vector<vector<ll>> vec2(r, vector<ll>(c));
    for(ll bit = 0; bit < (1<<r); bit++){
        vec2 = vec;
        for(ll i = 0; i < r; i++){
            if(bit & (1<<i)){
                rep(j, c){
                    if(vec2[i][j] == 0){
                        vec2[i][j] = 1;
                    }else{
                        vec2[i][j] = 0;
                    }
                }
            }
        }
        ll tmp = 0;
        rep(j, c){
            ll zero = 0;
            ll one = 0;
            rep(k, r){
                if(vec2[k][j] == 0){
                    zero++;
                }else{
                    one++;
                }
            }
            tmp += max(zero, one);
        }
        ans = max(ans, tmp);
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> r >> c;
    vec.resize(r, vector<ll>(c));
    rep(i, r){
        rep(j, c){
            cin >> vec[i][j];
        }
    }

    bit_search(r, c);

    cout << ans << endl;
    
}