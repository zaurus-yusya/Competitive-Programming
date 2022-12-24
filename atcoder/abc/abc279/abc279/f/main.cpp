#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << '\n';
using namespace std;
const long long INF = 8e18;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << ' ';} cerr << '\n';}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << ' ';} cerr << '\n';}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;
const double PI = acos(-1);

// 0 false, 1 true 
// string number to int : -48 or - '0'
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!
// (a * b)over flow?   if(a > INF / b){ /* overflow */}
// for(auto& i: mp) &&&&&&&&&&&&&

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
    ll n, q; cin >> n >> q;

    UnionFind uf(n + q + 10); // ボールを管理

    map<ll, ll> root_to_box; // root, 箱番号
    map<ll, ll> box_to_root; // 箱番号, root
    for(ll i = 1; i <= n; i++){
        root_to_box[i] = i;
        box_to_root[i] = i;
    }

    ll ball = n+1;

    rep(i, q){
        ll t; cin >> t;
        if(t == 1){
            ll x, y; cin >> x >> y; // 箱yを全部箱xに入れる
            // yは空になる

            if(box_to_root.count(x) > 0 && box_to_root.count(y) > 0){
                // cerr << "y to x" << endl; 
                // xのrootを変更する
                ll rx = box_to_root[x];
                ll ry = box_to_root[y];

                root_to_box.erase(rx);

                uf.unite(rx, ry);

                ll new_root = uf.root(rx);
                root_to_box[new_root] = x;

                box_to_root[x] = new_root;
                box_to_root.erase(y);
            }else if(box_to_root.count(x) == 0 && box_to_root.count(y) > 0){
                // cerr << "x empty" << endl;
                // yのrootをxにする
                ll ry = box_to_root[y];
                root_to_box.erase(ry);

                ll r = uf.root(ry);
                root_to_box[r] = x;

                box_to_root[x] = r;
                box_to_root.erase(y);
            }

        }
        if(t == 2){
            ll x; cin >> x; // 箱xにボールballを入れる

            if(box_to_root.count(x) > 0){
                ll rx = box_to_root[x];
                root_to_box.erase(rx);
                
                uf.unite(rx, ball);
                
                ll new_root = uf.root(rx);
                root_to_box[new_root] = x;
            }else{
                // cerr << "EMPTY " << ball << " " << x << endl;
                box_to_root[x] = ball;
                root_to_box[ball] = x;
            }

            ball++;
        }
        if(t == 3){
            ll x; cin >> x; // ボール
            ll r = uf.root(x);
            cout << root_to_box[r] << '\n';
        }

        // cerr << "i = " << i << endl;
        // for(ll j = 1; j < 10; j++){
        //     ll r = uf.root(j);
        //     if(root_to_box.count(r) > 0){
        //         cerr << "ball " << j << " box " << root_to_box[r] << " r = " << r << endl;
        //     }else{
        //         cerr << "ball " << j << " not in box. r = " << r << endl;
        //     }
        // }br;
    }
}