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


struct Edge{
    ll from;
    ll to;
    ll cost;
    Edge(ll from = 0, ll to = 0, ll cost = 0) : from(from), to(to), cost(cost) {}
};

bool cmp(Edge a, Edge b){
    if(a.cost != b.cost){
        return a.cost < b.cost;
    }else{
        return a.from < b.from;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i, n){
        rep(j, n){
            cin >> a[i][j];
        }
    }

    vector<Edge> vec; 
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    rep(i, n){
        rep(j, n){
            dist[i][j] = a[i][j];
            
        }
    }

    map<pair<ll, ll>, ll> mp;
    rep(k, n){ // 中継点
        rep(i, n){ // 始点
            rep(j, n){ // 終点

                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    cout << -1 << endl; return 0;
                }else if(dist[i][j] == dist[i][k] + dist[k][j]){
                    if(i < j && i != k && j != k){
                        mp[{i, j}]++;
                    }
                }else{
                    
                }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = i+1; j < n; j++){
            if(mp[{i, j}] > 0){

            }else{
                ans += a[i][j];
            }
        }
    }
    cout << ans << endl;


}