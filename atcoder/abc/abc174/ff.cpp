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

struct Query
{
    ll id, left, right;
    Query(ll id = 0, ll left = 0, ll right = 0) : id(id), left(left), right(right) {}
    //g[a].emplace_back(x, y) : x = to, y = cost
};

ll sq;
bool cmp(Query a, Query b){
    if(a.left / sq != b.left / sq){
        return a.left < b.left;
    }else if(a.left / sq % 2 == 1){
        return a.right > b.right;
    }else{
        return a.right < b.right;
    }
}

ll cnt = 0;
vector<ll> ss;
vector<long long> c;

void add(ll x){
    if(ss[c[x]] == 0){
        cnt++;
    }
    ss[c[x]]++;
}

void del(ll x){
    ss[c[x]]--;
    if(ss[c[x]] == 0){
        cnt--;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, q; cin >> n >> q;
    c.assign(n, 0);
    for(long long i = 0; i < n; i ++){
        cin >> c[i];
        c[i]--;
    }

    sq = sqrt(n);

    vector<Query> query;
    rep(i, q){
        ll l, r; cin >> l >> r; l--;
        query.emplace_back(i, l, r);
    }

    sort(all(query), cmp);

    vector<ll> ans(q);
    ll now_l = 0, now_r = 0;
    ss.assign(n, 0);

    rep(i, q){
        // cerr << "query " << query[i].left << " " << query[i].right << endl;

        while(now_l > query[i].left){
            add(--now_l);
        }
        while(now_l < query[i].left){
            del(now_l++);
        }
        
        while(now_r < query[i].right){
            add(now_r++);
        }
        while(now_r > query[i].right){
            del(--now_r);
        }
        

        // cerr << "now " << now_l << " " << now_r << endl;
        ans[query[i].id] = cnt;
    }

    rep(i, q){
        cout << ans[i] << '\n';
    }





}