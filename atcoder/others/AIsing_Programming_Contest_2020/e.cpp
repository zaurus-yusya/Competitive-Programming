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

ll f(vector<pair<ll, ll>> p){
    ll n = p.size();
    vector<vector<ll>> vec(n+1);
    rep(i, n){
        if(p[i].first > n) p[i].first = n;
        vec[p[i].first].push_back(p[i].second);
    }
    ll res = 0;
    priority_queue<ll> pq; 
    for(ll i = n; i >= 1; i--){
        rep(j, vec[i].size()){
            pq.push(vec[i][j]);
        }
        if(!pq.empty()){
            res += pq.top();
            pq.pop();
        }
    }
    return res;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;

    rep(T, t){
        ll ans = 0;
        ll n; cin >> n;
        vector<pair<ll, ll>> pl;
        vector<pair<ll, ll>> pr;
        rep(i, n){
            ll k, l, r; cin >> k >> l >> r;
            ll m = min(l, r);
            l -= m; r -= m;
            if(l > 0){
                pl.emplace_back(k, l);
            }else{
                pr.emplace_back(n-k, r);
            }
            ans += m;
        }

        ans += f(pl); ans += f(pr);
        cout << ans << endl;

    }

}