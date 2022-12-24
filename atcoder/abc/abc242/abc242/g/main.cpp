#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef int ll;
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

struct Query{
    ll l;
    ll r;
    ll id;

    Query(ll l = 0, ll r = 0, ll id = 0) : l(l), r(r), id(id) {}
};

ll sq;

bool cmp(Query a, Query b){
    if((a.l / sq) != (b.l / sq)){
        return a.l < b.l;
    }else if((a.l / sq) % 2 == 1){
        return a.r > b.r;
    }else{
        return a.r < b.r;
    }
}

vector<long long> a;
vector<ll> res;
ll cnt = 0;

void add(ll x){
    if((res[a[x]] % 2 + 2) % 2 == 1){
        cnt++;
    }
    res[a[x]]++;
}
void del(ll x){
    if((res[a[x]] % 2 + 2) % 2 == 0){
        cnt--;
    }
    res[a[x]]--;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    a.assign(n, 0);
    for(long long i = 0; i < n; i ++){
        cin >> a[i]; a[i]--;
    }

    ll qq; cin >> qq;
    vector<Query> q;

    sq = sqrt(qq);

    rep(i, qq){
        ll l, r; cin >> l >> r; l--;
        q.emplace_back(l, r, i);
    }

    sort(all(q), cmp);

    res.assign(n, 0);

    ll now_l = 0;
    ll now_r = 0;
    vector<ll> ans(qq);

    rep(i, qq){
        while(now_l > q[i].l){
            add(--now_l);
        }
        while(now_l < q[i].l){
            del(now_l++);
        }
        while(now_r < q[i].r){
            add(now_r++);
        }
        while(now_r > q[i].r){
            del(--now_r);
        }
        
        ans[q[i].id] = cnt;

        // vecdbg(res);
        // cerr << cnt << endl;
        // cerr << "---" << endl;
    }


    rep(i, qq){
        cout << ans[i] << '\n';
    }

}