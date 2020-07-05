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

struct UnionFind
{
    vector<long long> d;
    UnionFind(long long n = 0) : d(n, -1)
    {
    }

    //root : -size, not root: root
    long long root(long long x){
        if(d[x] < 0){
            return x; 
        }
        return d[x] = root(d[x]);
    }

    bool unite(long long x, long long y){
        x = root(x);
        y = root(y);
        if(x == y){
            return false;
        }
        if(d[x] > d[y]){
            swap(x, y);
        }
        d[x] += d[y];
        d[y] = x;
        return true;
    }

    long long size(long long x){
        return -d[root(x)];
    }

    bool issame(long long a, long long b){
        return root(a) == root(b);
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    UnionFind uf(n);
    vector<pll> vec(m);
    rep(i, m){
        cin >> vec[i].first >> vec[i].second;
        vec[i].first--; vec[i].second--;
    }

    vector<ll> ans(m);

    rep(i, m){
        if(i == 0){
            ans[i] = n * (n-1) / 2;
            continue;
        }
        ll l = vec[m-i].first;
        ll r = vec[m-i].second;
        if(uf.issame(l, r)){
            ans[i] = ans[i-1];
            continue;
        }
        ll num = uf.size(l) * uf.size(r);
        ans[i] = max(ans[i-1] - num, (ll)0);
        uf.unite(l, r);
    }

    rep(i, m){
        cout << ans[m - 1 - i] << endl;
    }


}