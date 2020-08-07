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

template<typename T>
struct BIT{
    ll n;
    vector<ll> d;
    BIT(int n=0):n(n),d(n+1) {}

    void add(ll i, T x=1){
        for(i++; i <= n; i += (i & -i)){
            d[i] += x;
        }
    }

    T sum(ll i) {
        T x = 0;
        for (i++; i; i -= i&-i) {
        x += d[i];
        }
        return x;
    }

};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, q; cin >> n >> q;
    vector<long long> vec(n);
    for(long long i = 0; i < n; i ++){
        cin >> vec[i];
    }

    vector<ll> last(n+1, -1);
    vector<vector<ll>> num_kukan(n);
    rep(i, n){
        ll tmp = last[vec[i]];
        if(tmp != -1){
            num_kukan[tmp].push_back(i);
        }
        last[vec[i]] = i;
    }

    vector<vector<pair<ll, ll>>> query(n);
    rep(i, q){
        ll l, r; cin >> l >> r; l--; r--;
        query[l].emplace_back(r, i); //右、クエリ番号
    }

    BIT<ll> d(n);
    
    vector<ll> ans(q);

    for(ll x = n-1; x >= 0; x--){
        for(ll y : num_kukan[x]){
            d.add(y, 1);
        }
        for(pair<ll, ll> qu : query[x]){
            ll r = qu.first; ll i = qu.second;
            ans[i] = (r - x + 1) - d.sum(r);
        }
    }

    rep(i, q){
        cout << ans[i] << endl;
    }
}