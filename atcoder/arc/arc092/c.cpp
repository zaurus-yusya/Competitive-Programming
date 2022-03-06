#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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

#define Cap ll
//mf_graph<Cap> graph(int n) Capはintかll
//int graph.add_edge(int from, int to, Cap cap); 追加された辺の順番をint型で返す
//Cap graph.flow(int s, int t);
//Cap graph.flow(int s, int t, Cap flow_limit);
//O(min(n^2/3 * m, m^3/2)) 辺の容量が全て1のとき
//O(n^2 * m)

// struct mf_graph<Cap>::edge {
//     int from, to;
//     Cap cap, flow;
// };
//mf_graph<Cap>::edge graph.get_edge(int i);
//vector<mf_graph<Cap>::edge> graph.edges();

//void graph.change_edge(int i, Cap new_cap, Cap new_flow); 

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<P> red(n);
    vector<P> blue(n);
    rep(i, n){
        ll x, y; cin >> x >> y;
        red[i] = {x, y};
    }
    rep(i, n){
        ll x, y; cin >> x >> y;
        blue[i] = {x, y};
    }

    mf_graph<Cap> graph(2 * n + 2);
    ll s = 2 * n, t = s+1;

    rep(i, n){
        ll node = i;
        graph.add_edge(s, node, 1);
    }
    rep(i, n){
        ll node = i + n;
        graph.add_edge(node, t, 1);
    }

    rep(i, n){
        rep(j, n){
            ll red_node = i;
            ll blue_node = j + n;
            if(red[i].first < blue[j].first && red[i].second < blue[j].second){
                graph.add_edge(red_node, blue_node, 1);
            }
        }
    }

    cout << graph.flow(s, t) << endl;
    

}