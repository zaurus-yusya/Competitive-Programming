#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}
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

ll h, w, a, b;

ll ans = 0;
void dfs(ll i, ll j, vector<vector<ll>> &vec, ll cnt){
    //cout << i << " " << j << endl;
    
    if(j == w){
        j = 0; i = i+1;
    }
    if(i == h){
        if(cnt == a) ans++;
        return;
    }
    if(vec[i][j] == 1){
        dfs(i, j+1, vec, cnt);
        return;
    }

    //置かない
    vec[i][j] = 1;
    dfs(i, j+1, vec, cnt);
    vec[i][j] = 0;
    //横置き
    if(j + 1 < w && vec[i][j+1] == 0){
        vec[i][j] = 1; vec[i][j+1] = 1;
        dfs(i, j+1, vec, cnt+1);
        vec[i][j] = 0; vec[i][j+1] = 0;
    }
    //縦置き
    if(i + 1 < h && vec[i+1][j] == 0){
        vec[i][j] = 1; vec[i+1][j] = 1;
        dfs(i, j+1, vec, cnt+1);
        vec[i][j] = 0; vec[i+1][j] = 0;
    }


}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> h >> w >> a >> b;
    vector<vector<ll>> vec(h, vector<ll>(w));
    dfs(0, 0, vec, 0);
    cout << ans << endl;
}