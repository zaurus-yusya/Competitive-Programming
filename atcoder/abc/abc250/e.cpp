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
// for(auto& i: mp) &&&&&&&&&&&&&

//dijkstra
struct Query
{
    ll x, y, ind;
    Query(ll x = 0, ll y = 0, ll ind = 0) : x(x), y(y), ind(ind) {}

};

bool cmp(Query a, Query b){
    if(a.x == a.y){
        if(a.y == b.y){
            return a.ind < b.ind;
        }else{
            return a.y < b.y;
        }
    }else{
        return a.x < b.x;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<long long> a(n);
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
    }
    vector<long long> b(n);
    for(long long i = 0; i < n; i ++){
        cin >> b[i];
    }

    vector<ll> a2(n); map<ll, ll> mpa;
    vector<ll> b2(n); map<ll, ll> mpb;
    vector<ll> asize(n);
    vector<ll> bsize(n);
    rep(i, n){
        if(mpa[a[i]] > 0){
            a2[i] = -1;
        }else{
            a2[i] = a[i]; mpa[a[i]]++;
        }
        asize[i] = mpa.size();
        if(mpb[b[i]] > 0){
            b2[i] = -1;
        }else{
            b2[i] = b[i]; mpb[b[i]]++;
        }
        bsize[i] = mpb.size();
    }

    vector<ll> ans(n+10);

    ll nowx = 0, nowxind = 0;
    ll nowy = 0, nowyind = 0;

    set<ll> sa;
    set<ll> sb;
    map<pair<ll, ll>, ll> mp;
    ll syugo = 1;
    while(syugo <= max(mpa.size(), mpb.size())){

        // aの集合が+1されるまで増やす
        for(ll i = nowxind; i <= n; i++){
            if(i == n) break;
            if(asize[i] <= syugo){
                sa.insert(a[i]);
            }else{
                nowxind = i;
                break;
            }
        }

        // bの集合が+1されるまで増やす
        for(ll i = nowyind; i <= n; i++){
            if(i == n) break;
            if(bsize[i] <= syugo){
                sb.insert(b[i]);
            }else{
                nowyind = i;
                break;
            }
        }
        if(sa == sb){
            ans[syugo] = 1;
        }

        syugo++;
        if(nowxind == n && nowyind == n){
            break;
        }
    }


    ll Q; cin >> Q;

    rep(i, Q){
        ll x, y; cin >> x >> y; x--; y--;
        if(asize[x] == bsize[y] && ans[asize[x]] == 1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }


}