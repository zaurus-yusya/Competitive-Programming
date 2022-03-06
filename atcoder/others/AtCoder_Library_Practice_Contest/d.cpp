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
    ll n, m; cin >> n >> m;
    vector<vector<char>> vec(n, vector<char>(m));
    rep(i, n)rep(j, m) cin >> vec[i][j];

    mf_graph<ll> graph(n * m + 2);
    ll s = n * m, t = n * m + 1;

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(vec[i][j] == '#') continue;
            ll node = i * m + j;
            if((i+j) % 2 == 0){
                //cout << "ADDED " << s << " " << node << endl;
                graph.add_edge(s, node, 1);
            }else{
                //cout << "ADDED " << node << " " << t << endl;
                graph.add_edge(node, t, 1);
            }
        }
    }

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(vec[i][j] == '#') continue;
            ll node = i * m + j;
            if((i+j) % 2 == 1) continue;

            //上
            if(i != 0 && vec[i-1][j] == '.'){
                ll next = node - m;
                //cout << "added " << node << " " << next << endl;
                graph.add_edge(node, next, 1);
            }
            //下
            if(i != n-1 && vec[i+1][j] == '.'){
                ll next = node + m;
                //cout << "added " << node << " " << next << endl;
                graph.add_edge(node, next, 1);
            }
            //左
            if(j != 0 && vec[i][j-1] == '.'){
                ll next = node - 1;
                //cout << "added " << node << " " << next << endl;
                graph.add_edge(node, next, 1);
            }
            //右
            if(j != m-1 && vec[i][j+1] == '.'){
                ll next = node + 1;
                //cout << "added " << node << " " << next << endl;
                graph.add_edge(node, next, 1);
            }
        }
    }

    cout << graph.flow(s, t) << endl;

    //構築
    vector<mf_graph<Cap>::edge> res = graph.edges();
    vector<vector<char>> ans = vec;
    for(ll i = 0; i < res.size(); i++){
        if(res[i].from == s || res[i].to == t || res[i].flow == 0) continue;

        ll from_i = res[i].from / m, from_j = res[i].from % m;
        ll to_i = res[i].to / m, to_j = res[i].to % m;

        //上
        if(from_i - 1 == to_i){
            ans[to_i][to_j] = 'v';
            ans[from_i][from_j] = '^';
        }
        //下
        if(from_i + 1 == to_i){
            ans[from_i][from_j] = 'v';
            ans[to_i][to_j] = '^';
        }
        //左
        if(from_j - 1 == to_j){
            ans[to_i][to_j] = '>'; ans[from_i][from_j] = '<';
        }
        //右
        if(from_j + 1 == to_j){
            ans[from_i][from_j] = '>'; ans[to_i][to_j] = '<'; 
        }
        
    }

    rep(i, n){
        rep(j, m){
            cout << ans[i][j];
        }br;
    } 

}