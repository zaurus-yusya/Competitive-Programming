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

//1-indexed only in the function
//O(log n)
//fenwick<ll> f(n)
template<typename T>
struct fenwick
{
    //constructor
    ll n;
    vector<T> bit;
    fenwick(ll n_) : n(n_ + 1), bit(n, 0) {}

    //method
    void add(ll i, T x){
        i += 1; //1-indexed
        for(ll idx = i; idx < n; idx += (idx & -idx)){
            bit[idx] += x;
        }
    }

    T sum(ll i){
        T s(0);
        //return sum[0, i)
        for(ll idx = i; idx > 0; idx -= (idx & -idx)){
            s += bit[idx];
        }
        return s;
    }

    T sum2(ll l, ll r){
        T L(0);
        T R(0);
        //return sum[l, r)
        for(ll idx = l; idx > 0; idx -= (idx & -idx)){
            L += bit[idx];
        }
        for(ll idx = r; idx > 0; idx -= (idx & -idx)){
            R += bit[idx];
        }
        return R - L;
    }

};

struct Query
{
    ll id, left, right;
    Query(ll id = 0, ll left = 0, ll right = 0) : id(id), left(left), right(right) {}

    bool operator < (const Query& another) const{
        return right < another.right;
    }
    // 追加：g[a].emplace_back(x, y) : x = to, y = cost

    // ソート：operatorを定義する
    // bool operator < (const Query& another) const{
    //     return right < another.right;
    // }
};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, q; cin >> n >> q;
    vector<long long> c(n);
    for(long long i = 0; i < n; i ++){
        cin >> c[i];
        c[i]--;
    }

    fenwick<ll> fw(n);
    vector<ll> right_pos(n, -1);

    vector<Query> query;
    rep(i, q){
        ll l, r; cin >> l >> r;
        query.emplace_back(i, l, r);
        query[i].left--;
    }

    sort(all(query));
    vector<ll> ans(q);

    ll now = 0;
    rep(i, q){
        for(ll j = now; j < query[i].right; j++){
            ll bef = right_pos[c[j]];
            if(bef != -1){
                fw.add(bef, -1);
            }
            fw.add(j, 1);
            right_pos[c[j]] = j;
        }
        now = query[i].right;

        ans[query[i].id] = fw.sum2(query[i].left, query[i].right);
    }


    rep(i, q){
        cout << ans[i] << '\n';
    }

}