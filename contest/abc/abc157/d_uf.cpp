#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << endl;
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// stringの数字をint型にしてアスキーコードになったら -48する
// 切り上げ　ceil(a)
// コンパイル　g++ -std=c++17 a.cpp

struct UnionFind
{
    vector<ll> d;
    UnionFind(ll n = 0) : d(n, -1)
    {    
    }

    //root : -size, not root: root
    ll root(ll x){
        if(d[x] < 0){
            return x; 
        }
        return d[x] = root(d[x]);
    }

    bool unite(ll x, ll y){
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

    ll size(ll x){
        return -d[root(x)];
    }

    bool issame(ll a, ll b){
        return root(a) == root(b);
    }
};


//unionfind
int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    UnionFind uf(n);
    vector<ll> friend_num(n);
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        friend_num.at(a)++;
        friend_num.at(b)++;
        uf.unite(a,b);
    }

    vector<ll> block_num(n);
    for (ll i = 0; i < k; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        if(uf.issame(a, b)){
            block_num.at(a)++;
            block_num.at(b)++;
        }
    }
    
    rep(i,n){
        cout << uf.size(i) -1 -friend_num.at(i) -block_num.at(i) << " ";
    }
    cout << endl;

}