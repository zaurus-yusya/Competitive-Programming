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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll a, b; cin >> a >> b; a--; b--;
    vector<vector<char>> vec(3, vector<char>(3));

    vector<ll> dy;
    vector<ll> dx;
    rep(i, 3){
        rep(j, 3){
            cin >> vec[i][j];
            if(vec[i][j] == '#'){
                dy.push_back(-1 + i);
                dx.push_back(-1 + j);
            }
        }
    }

    vector<vector<ll>> dist(9, vector<ll>(9, -1));
    queue<pair<ll, ll>> que;
    que.push({a, b});
    dist[a][b] = 0;
    while(!que.empty()){
        ll nowy = que.front().first;
        ll nowx = que.front().second;
        que.pop();
        rep(i, dy.size()){
            ll nexty = nowy + dy[i];
            ll nextx = nowx + dx[i];

            if(nexty < 0 || nexty >= 9 || nextx < 0 || nextx >= 9){
                continue;
            }
            if(dist[nexty][nextx] != -1){
                continue;
            }

            dist[nexty][nextx] = dist[nowy][nowx] + 1;
            que.push({nexty, nextx});
        }
    }

    ll ans = 0;
    rep(i, 9){
        rep(j, 9){
            if(dist[i][j] != -1){
                ans++;
            }
        }
    }
    cout << ans << endl;
    


}