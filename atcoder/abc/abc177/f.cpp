#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b == 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll h, w; cin >> h >> w;
    vector<vector<ll>> vec(h+1, vector<ll>(w));
    vector<pair<ll, ll>> dame;
    vector<pair<ll, ll>> l(h);
    vector<pair<ll, ll>> r(h);
    rep(i, h){
        ll a, b; cin >> a >> b; a--; b--;
        vec[i][a] = 1; vec[i][b] = 1;
        dame.emplace_back(a, b);
        if(a == 0 && b == w-1){
            l.emplace_back(-1, -1);
            r.emplace_back(-1, -1);
        }else if(a > 0 && b < w-1){
            l.emplace_back(0, a-1);
            r.emplace_back(b+1, w-1);
        }else if(a == 0){
            l.emplace_back(-1, -1);
            r.emplace_back(b+1, w-1);
        }else{
            l.emplace_back(0, a-1);
            r.emplace_back(-1, -1);
        }
    }

    for(ll i = 0; i < h; i++){
        if(i == 0){
            if(l[0].first == -1 && r[0].first == -1){
                cout << -1 << endl;
            }else{
                cout << 1 << endl;
            }
        }else{
            
        }
    }

    vecvecdbg(vec);
    
    // dame[i].first <= vec[i][j] <= dame[i].first


}