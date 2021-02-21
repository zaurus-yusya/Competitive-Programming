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
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!

int main() {
    std::cout << std::fixed << std::setprecision(15);
    string n; cin >> n; 
    ll k; cin >> k;

    if(k == 0){
        cout << n << endl; return 0;
    }

    ll res  = 0;
    for(ll j = 0; j < k; j++){
        sort(all(n), greater<ll>());
        string g1 = n;
        //cout << g1 << endl;
        ll g1x = 0, now = 1;
        for(ll i = 0; i < g1.size(); i++){
            g1x += now * (g1[g1.size() - 1 - i] - 48);
            now *= 10;
        }
        //cout << g1x << endl;
        
        string g2;
        sort(all(g1));
        g2 = g1;
        
        ll g2x = 0;
        now = 1;
        //cout << g2 << endl;
        for(ll i = 0; i < g2.size(); i++){
            g2x += now * (g2[g2.size() - 1 - i] - 48);
            now *= 10;
        }
        //cout << g2x << endl;

        res = g1x - g2x;

        n = to_string(res);

    }

    cout << res << endl;
}