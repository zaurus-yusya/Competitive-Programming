#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef int ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 8e18;
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

map<pair<ll, ll>, char> mp;

vector<ll> seen;
vector<ll> label;

ll zero = 0;
ll one = 0;

bool flag = true;

void dfs(vector<vector<ll>> &g, ll node, ll la){
    seen[node] = 1;
    label[node] = la;

    if(la == 0){
        zero++;
    }else{
        one++;
    }
        
    for(auto next: g[node]){
        //次のラベル
        ll nl;
        if(node < next){
            if(mp[{node, next}] == 'i'){
                nl = (la + 1) % 2;
            }else{
                nl = la;
            }
        }else{
            if(mp[{next, node}] == 'i'){
                nl = (la + 1) % 2;
            }else{
                nl = la;
            }
        }


        if(seen[next] == 0){
            dfs(g, next, nl);
        }else{
            //矛盾判定
            if(label[next] != nl){
                flag = false;
            }
        }
    }

}



int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll n, m; cin >> n >> m;
        vector<vector<ll>> g(n);
        mp.clear();
        flag = true; //dfsの矛盾フラグ
        bool f = true;
        rep(i, m){
            ll x, y; cin >> x >> y; x--; y--;
            g[x].push_back(y); g[y].push_back(x);
            string s; cin >> s;

            if(x > y){
                swap(x, y);
            }
            if(s[0] == 'i'){
                if(mp[{x, y}] == 'c'){
                    f = false;
                }
                mp[{x, y}] = 'i';
            }else{
                if(mp[{x, y}] == 'i'){
                    f = false;
                }
                mp[{x, y}] = 'c';
            }

        }

        if(!f){
            cout << -1 << endl;
            continue;
        }

        seen.assign(n, 0);
        label.assign(n, -1);

        ll ans = 0;
        rep(i, n){
            zero = 0; one = 0;
            if(seen[i] == 0){
                dfs(g, i, 0);
            }

            ans += max(zero, one);

            if(!flag) break;
        }

        if(!flag){
            cout << -1 << endl;
        }else{
            cout << ans << endl;
        }

    }

}