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


struct Choco
{
    ll y, x, num;
    Choco(ll y = 0, ll x = 0, ll num = 0) : y(y), x(x), num(num) {}
    //g[a].emplace_back(x, y) : x = to, y = cost
};

bool cmp(Choco a, Choco b){
    if(a.y != b.y){
        return a.y > b.y;
    }else if(a.x != b.x){
        return a.x > b.x;
    }else{
        return a.num > b.num;
    }
    
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    vector<Choco> vec;
    vector<ll> a(n); rep(i, n) cin >> a[i];
    vector<ll> b(n); rep(i, n) cin >> b[i];
    vector<ll> c(m); rep(i, m) cin >> c[i];
    vector<ll> d(m); rep(i, m) cin >> d[i];

    rep(i, n){
        vec.emplace_back(a[i], b[i], 0);
    }
    rep(i, m){
        vec.emplace_back(c[i], d[i], 1);
    }
    sort(all(vec), cmp);

    map<ll, ll> mp;
    rep(i, vec.size()){
        if(vec[i].num == 1){
            mp[vec[i].x]++;
        }else{
            auto itr = mp.lower_bound(vec[i].x);
            if(itr == mp.end()){
                cout << "No" << endl; return 0;
            }else if(mp.count(itr->first) == 0){
                cout << "No" << endl; return 0;
            }else{
                mp[itr->first]--;
                if(mp[itr->first] == 0){
                    mp.erase(itr->first);
                }
            }

        }
    }
    cout << "Yes" << endl;
    



}