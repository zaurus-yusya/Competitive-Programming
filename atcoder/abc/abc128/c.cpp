#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
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
ll ans = 0;
vector<vector<ll>> vec;
vector<ll> p;



void bit_full_search(int n, int m)
{
    for(int bit = 0; bit < (1 << n); bit++){
        //cout << "{";
        vector<ll> res(m);
        for(int i = 0; i < n; i++){
            if(bit & (1<<i)){
                //cout << " " << i << " ";
                rep(j, m){
                    rep(k, vec[j].size()){
                        if(i == vec[j][k]){
                            res[j]++;
                        }
                    }
                }
            }
        }

        bool flag = true;
        rep(i, m){
            if(res[i] % 2 == p[i]){
                continue;
            }else{
                flag = false;
            }
        }
        if(flag) ans++;

        //cout << "}" << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m;
    cin >> n >> m;

    vec.resize(m);
    rep(i, m){
        ll k;
        cin >> k;
        rep(j, k){
            ll s;
            cin >> s;
            s--;
            vec[i].pb(s);
        }
    }

    p.resize(m);
    rep(i, m){
       cin >> p[i];
    }

    
    bit_full_search(n, m);

    cout << ans << endl;

}