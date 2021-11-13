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
const long long MOD = 1e9+7;
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

struct TaskInfo{
    ll id;
    ll sequence;
};
/*
bool taskinfo_sort(TaskInfo a, TaskInfo b){
    return a.sequence > b.sequence;
}
*/

int main() {
    std::cout << std::fixed << std::setprecision(15);
    auto taskinfo_sort = [](TaskInfo a, TaskInfo b) { return a.sequence < b.sequence; };
    priority_queue<TaskInfo, vector<TaskInfo>, decltype(taskinfo_sort)> pque(taskinfo_sort);

    ll n, m; cin >> n >> m;
    vector<vector<ll>> g(n);
    vector<ll> ind(n);
    vector<ll> seq(n);
    rep(i, m){
        ll u, v; cin >> u >> v; u--; v--; g[v].push_back(u);
        ind[u]++;
    }
    queue<ll> que;
    rep(i, n){
        if(ind[i] == 0) que.push(i);
    }
    while(!que.empty()){
        ll num = que.front();
        que.pop();
        for(auto next: g[num]){
            seq[next] += seq[num] + 1;
            ind[next]--;
            if(ind[next] == 0) que.push(next);
        }
    }

    rep(i, n){
        cout << seq[i] << " ";
    }br;

    
    rep(i, n){
        pque.push({i, seq[i]});
    }
    

    
    while(!pque.empty()){
        cout << "id " << pque.top().id << " sequence = " << pque.top().sequence << endl;
        pque.pop();
    }
    


}
