#include <bits/stdc++.h>
#include <atcoder/all>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
using namespace atcoder;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// If the result in local and judge is different, USE CODETEST!!

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
    vector<pair<ld, ld>> node(n);
    vector<ll> color(n);
    vector<pair<ld, ld>> konode(m);
    vector<ll> kocolor(m);

    rep(i, n){
        ld x, y; ll c; cin >> x >> y >> c;
        node[i] = {x, y}; color[i] = c;
    }
    rep(i, m){
        ld x, y; ll c; cin >> x >> y >> c;
        konode[i] = {x, y}; kocolor[i] = c;
    }

    ld ans = 10000000000000000;
    //konodeどれ使うか
    for(ll i = 0; i < (1<<m); i++){

        vector<ll> kouse;
        for(ll j = 0; j < m; j++){
            if((i & (1<<j))){
                //cout << j << " ";
                kouse.push_back(j);
            }
        }

        //使うノードと色のvector
        vector<pair<ld, ld>> use = node;
        vector<ll> usec = color;
        for(ll j = 0; j < kouse.size(); j++){
            use.push_back({konode[kouse[j]]});
            usec.push_back(kocolor[kouse[j]]);
        } 
        //辺を繋ぐ
        vector<tuple<ld, ll, ll>> g; // cost, from, to
        for(ll j = 0; j < use.size(); j++){
            for(ll k = j+1; k < use.size(); k++){
                ld x1 = use[j].first, y1 = use[j].second;
                ld x2 = use[k].first, y2 = use[k].second;
                
                ld cost = sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1));
                if(usec[j] != usec[k]) cost *= 10;
                g.push_back({cost, j, k});
            }
        }

        sort(all(g));

        //クラスカル
        UnionFind uf(use.size());
        ld tmp = 0;
        for(ll j = 0; j < g.size(); j++){
            if(!uf.issame(get<1>(g[j]), get<2>(g[j]))){
                tmp += get<0>(g[j]);
                uf.unite(get<1>(g[j]), get<2>(g[j]));
            }
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;


}