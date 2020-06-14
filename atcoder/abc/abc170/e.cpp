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
    ll n, q; cin >> n >> q;
    vector<ll> enzi_rate(n);
    vector<ll> enzi_at(n);

    vector<map<ll, ll>> vecmap(200000);
    rep(i, n){
        ll a, b; cin >> a >> b; b--;
        enzi_rate[i] = a;
        enzi_at[i] = b;
        vecmap[b][a]++;
    }

    vector<pll> query(q);
    rep(i, q){
        ll c, d; cin >> c >> d; c--; d--;
        query[i] = {c, d};
    }
    
    /*
    for(auto i: vecmap[0]){
        cout << i.first << " " << i.second << endl;
    }
    変数名.size()
    */
    ll ans = INF;
    ll ans_itr = -1;
    rep(i, vecmap.size()){
        if(vecmap[i].size() != 0){
            ll maxv = vecmap[i].rbegin()->first;
            ans = min(ans, maxv);
        }   
    }

    rep(i, q){
        ll enzi = query[i].first;
        ll youchi = query[i].second;
        
        ll rate = enzi_rate[enzi];
        ll before = enzi_at[enzi];

        ll maxv_b = 0, maxv_a = 0;

        //前いた幼稚園から消す
        maxv_b = vecmap[before].rbegin()->first;
        ll bflag = 0;
        if(ans == maxv_b){
            bflag = 1;
        }
        vecmap[before][rate]--;
        if(vecmap[before][rate] == 0){
            vecmap[before].erase(rate);
        }

        //次の幼稚園に足す
        ll aflag = 0;
        if(vecmap[youchi].size() != 0){
            maxv_a = vecmap[youchi].rbegin()->first;
            if(ans == maxv_a){
                aflag = 1;
            }
        }
        vecmap[youchi][rate]++;

        //ansの計算
        
        if(vecmap[before].size() != 0 && bflag == 1){
            maxv_b = vecmap[before].rbegin()->first;
            ans = min(ans, maxv_b);
        }
        
        if(vecmap[youchi].size() != 0 && aflag == 1){
            maxv_a = vecmap[youchi].rbegin()->first;
            ans = min(ans, maxv_a);
        }

        cout << ans << endl;
    }

    //cout << ans << endl;
    

    
    
    
    

    


}