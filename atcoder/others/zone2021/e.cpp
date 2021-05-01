#include <bits/stdc++.h>
// #include <atcoder/aint>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<(n);i++)
#define repr(i,n) for(int i=(n-1);i>=0;i--)
#define aint(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e9;
const long long MOD = 1e9+7;
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
int ceiintl(int a, int b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
int get_digit(int a) {int digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << " ";} br;}}
int POW(int a, int n){ int res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<int, int>;

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

//dijkstra
struct Edge
{
    int to, cost;
    Edge(int to = 0, int cost = 0) : to(to), cost(cost) {}
    //g[a].emplace_back(x, y) : x = to, y = cost
};
vector<int> dist; //distance
//vector<int> pre; //route restoration
void dijkstra(vector<vector<Edge>> &g, int start){
    dist.assign(g.size(), INF);
    //pre.assign(g.size(), -1);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[start] = 0;
    que.push({0, start});

    while(!que.empty()){
        auto[d, v] = que.top(); que.pop();
        if(dist[v] != d) continue;
        for(Edge& e : g[v]){
            int next = d + e.cost; // next cost
            if(dist[e.to] <= next){
                continue;
            }else{
                dist[e.to] = next;
                que.push({next, e.to});
                //pre[e.to] = v;
            }
        }
    } 
}
// void route_restoration(vector<int> &pre, int goal){
//     int now = goal;
//     while(true){
//         cout << now << endl;
//         if(pre[now] == -1) break;
//         now = pre[now];
//     }
// }



int main() {
    std::cout << std::fixed << std::setprecision(15);
    int r, c; cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c-1));
    vector<vector<int>> b(r-1, vector<int>(c));
    rep(i, r){
        rep(j, c-1){
            cin >> a[i][j];
        }
    }
    rep(i, r-1){
        rep(j, c){
            cin >> b[i][j];
        }
    }

    //cout << "in" << endl;
    vector<vector<Edge>> vec(r*c); // Edge = {to, cost}

    rep(i, r){
        rep(j, c-1){
            int x = c*i + j;
            vec[x].push_back({x+1, a[x/c][x%c]});
        }
    }

    rep(i, r){
        for(int j = c-1; j > 0; j--){
            int x = c*i + j;
            vec[x].push_back({x-1, a[x/c][ (x%c) - 1]});
        }
    }

    rep(j, c){
        rep(i, r-1){
            int x = c*i + j;
            vec[x].push_back({x+c, b[x/c][(x%c)]});
        }
    }
    
    rep(j, c){
        for(int i = r-1; i > 0; i--){
            int x = c*i + j;
            
            for(int k = 1; k <= i; k++){
                vec[x].push_back({x-k*c, 1+k});
            }
            
        }
    }
    

    //cout << "in" << endl;
    dijkstra(vec, 0);

    cout << dist[r*c-1] << endl;

}