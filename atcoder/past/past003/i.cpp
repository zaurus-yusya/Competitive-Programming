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
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, Q;
    cin >> n >> Q;

    vector<vector<ll>> vec(n, vector<ll>(n));

    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= n; j++){
            vec[i-1][j-1] = n * (i-1) + j-1; 
        }
    }

    vector<ll> gyo(n);
    vector<ll> retsu(n);
    rep(i, n){
        gyo[i] = i;
        retsu[i] = i;
    }
    

    ll flag = 0;
    vector<ll> res;
    rep(q,Q){
        ll t; cin >> t;
        if(t == 1){
            ll a, b; cin >> a >> b; a--; b--;
            swap(gyo[a] , gyo[b]);
        }

        if(t == 2){
            ll a, b; cin >> a >> b; a--; b--;
            swap(retsu[a] , retsu[b]);
        }

        if(t == 3){
            vector<ll> tmp(n);
            tmp = gyo;
            gyo = retsu;
            retsu = gyo;
        }

        if(t == 4){
            ll a, b; cin >> a >> b; a--; b--;
            
        }
    }

    rep(i, n){
        cout << gyo[i] << " ";
        
    }
    br;
    rep(i, n){
        cout << retsu[i] << " ";
    }
    br;

}