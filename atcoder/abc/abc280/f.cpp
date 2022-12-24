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
    ll to, cost;
    Edge(ll to = 0, ll cost = 0) : to(to), cost(cost) {}
};


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m, q; cin >> n >> m >> q;
    vector<vector<Edge>> g(n);
    rep(i, m){
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, -c);
    }

    vector<ll> label(n, -1);
    vector<ll> dist(n, INF);

    map<ll, ll> inf_label;

    ll cnt = 0;
    for(ll i = 0; i < n; i++){
        if(dist[i] == INF){
            dist[i] = 0;
            label[i] = cnt;

            queue<pair<ll, ll>> que; // {node, parent}
            que.push({i, -1});

            while(!que.empty()){
                auto [now, par] = que.front();
                que.pop();
                label[now] = cnt;

                for(auto &[to, cost]: g[now]){
                    if(dist[to] == INF){
                        // いく
                        dist[to] = dist[now] + cost;
                        que.push({to, now});
                    }else{
                        if(to != par){
                            // 親じゃなくて、距離違ったらinf
                            if(dist[to] != dist[now] + cost){
                                inf_label[cnt]++;
                            }
                        }
                    }

                }
            }
            cnt++;
        }
    }

    rep(i, q){
        ll x, y; cin >> x >> y;
        x--; y--;
        if(label[x] != label[y]){
            cout << "nan" << '\n';
        }else if(inf_label.count(label[x])){
            cout << "inf" << '\n';
        }else{
            cout << dist[y] - dist[x] << endl;
        }
    }

}