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


struct Node
{
    ll r, c, a;
    Node(ll r = 0, ll c = 0, ll a = 0) : r(r), c(c), a(a) {}
};

bool cmp(Node a, Node b){
    if(a.a != b.a){
        return a.a > b.a;
    }else{
        if(a.r != b.r){
            return a.r < b.r;
        }else{
            return a.c < b.c;
        }
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll h, w, n; cin >> h >> w >> n;
    vector<Node> vec;

    map<ll, vector<ll>> mp;
    rep(i, n){
        ll r, c, a; cin >> r >> c >> a;
        vec.emplace_back(r, c, a);
        mp[a].push_back(i);
    }

    map<ll, ll> row;
    map<ll, ll> column;

    vector<ll> res(n);

    for(auto itr = mp.rbegin(); itr != mp.rend(); itr++){
        
        // 同じ a の値
        for(ll i = 0; i < itr->second.size(); i++){
            ll x = itr->second[i]; // x番目のマス
            ll nowr = vec[x].r;
            ll nowc = vec[x].c;
            
            res[x] = max(row[nowr], column[nowc]);
        }

        // 同じ a の値
        for(ll i = 0; i < itr->second.size(); i++){
            ll x = itr->second[i]; // x番目のマス
            ll nowr = vec[x].r;
            ll nowc = vec[x].c;

            row[nowr] = max(row[nowr], (res[x]+1));
            column[nowc] = max(column[nowc], (res[x]+1));
        }
    }

    rep(i, n){
        cout << res[i] << '\n';
    }
    

}