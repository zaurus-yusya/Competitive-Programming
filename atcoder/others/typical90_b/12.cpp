#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;

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
    ll h, w; cin >> h >> w;
    vector<ll> vec(h*w);
    vector<vector<ll>> use(h, vector<ll>(w));
    UnionFind uf(h*w);

    vector<ll> d = {w, -w, 1, -1};
    vector<ll> dy = {1, -1, 0, 0};
    vector<ll> dx = {0, 0, 1, -1};
    
    ll q; cin >> q;

    rep(i, q){
        ll t; cin >> t;
        if(t == 1){
            ll y, x; cin >> y >> x; y--; x--;
            ll masu = (y*w) + x;
            vec[masu] = 1;
            use[y][x] = 1;

            rep(j, 4){
                if(y + dy[j] < 0 || y + dy[j] >= h) continue;
                if(x + dx[j] < 0 || x + dx[j] >= w) continue;
                ll atoy = y + dy[j], atox = x + dx[j];
                if(use[y + dy[j]][x + dx[j]] == 1){
                    uf.unite(masu, (atoy*w+atox));
                }

                /*
                if((masu + d[j] < 0) || (masu + d[j] >= h*w)){
                    continue;
                }
                if(vec[masu + d[j]] == 1){
                    uf.unite(masu, (masu+d[j]));
                }
                */

            }

        }else{
            ll y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2; y1--; x1--; y2--; x2--;
            ll masu1 = (y1*w) + x1; ll masu2 = (y2*w) + x2;
            if(use[y1][x1] == 1 && use[y2][x2] == 1 && uf.issame(masu1, masu2)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
            /*
            if(vec[masu1] == 1 && vec[masu2] == 1 && uf.issame(masu1, masu2)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
            */
        }
    }

}