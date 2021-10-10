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

//https://atcoder.jp/contests/abc172/submissions/14765570
//20200724
template<long long mod>
struct ModInt
{
    long long x;
    ModInt () : x(0) {}
    ModInt (long long x) : x(x >= 0 ? x % mod : (mod - -x % mod) % mod) {}
    ModInt &operator += (const ModInt &p){
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator -= (const ModInt &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator *= (const ModInt &p) {
        x = (long long) x * p.x % mod;
        return *this;
    }
    ModInt &operator /= (const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }
    ModInt &operator ^= (long long p) {
        ModInt res = 1;
        for (; p; p >>= 1) {
            if (p & 1) res *= *this;
            *this *= *this;
        }
        return *this = res;
    }
    ModInt operator - () const { return ModInt(-x); }
    ModInt operator + (const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator - (const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator * (const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator / (const ModInt &p) const { return ModInt(*this) /= p; }
    ModInt operator ^ (long long p) const { return ModInt(*this) ^= p; }
    bool operator == (const ModInt &p) const { return x == p.x; }
    bool operator != (const ModInt &p) const { return x != p.x; }
    explicit operator long long() const { return x; }
    ModInt &operator = (const long long p) { x = p; return *this;}
    ModInt inverse() const {
        long long a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            a -= t * b;
            std::swap(a, b);
            u -= t * v;
            std::swap(u, v);
        }
        return ModInt(u);
    }
    friend std::ostream & operator << (std::ostream &stream, const ModInt<mod> &p) {
        return stream << p.x;
    }
    friend std::istream & operator >> (std::istream &stream, ModInt<mod> &a) {
        long long x;
        stream >> x;
        a = ModInt<mod>(x);
        return stream;
    }
};
/*
template<long long mod> struct MComb {
    using mint = ModInt<mod>;
    std::vector<mint> fact;
    std::vector<mint> inv;
    MComb (long long n) { // O(n + log(mod))
        fact = std::vector<mint>(n + 1, 1);
        for (long long i = 1; i <= n; i++) fact[i] = fact[i - 1] * mint(i);
        inv.resize(n + 1);
        inv[n] = fact[n] ^ (mod - 2);
        for (long long i = n; i--; ) inv[i] = inv[i + 1] * mint(i + 1);
    }
    mint ncr(long long n, long r) {
        return fact[n] * inv[r] * inv[n - r];
    }
    mint npr(long n, long r) {
        return fact[n] * inv[n - r];
    }
    //nhr : n : shikiri + 1, r : tamanokazu
    mint nhr(long n, long r) {
        assert(n + r - 1 < (long long) fact.size());
        return ncr(n + r - 1, r);
    }
};

template<long long mod> struct MPow {
    using mint = ModInt<mod>;
    mint modpow(mint a, long long n) {
        mint res = 1;
            while(n > 0){
            if(n & 1){
                res = res * a;
            }
            a = a * a;
            n >>= 1;
        }
        return res;
    }
};
*/

typedef ModInt<998244353> mint;
//MComb<998244353> com(510000);
//MPow<998244353> mpow;

map<pair<ll, ll>, ll> hen;
map<pair<ll, ll>, ll> hennum;

//dijkstra
struct Edge
{
    ll to, cost;
    Edge(ll to = 0, ll cost = 0) : to(to), cost(cost) {}
    //g[a].emplace_back(x, y) : x = to, y = cost
};
vector<ll> dist; //distance
vector<ll> pre; //route restoration
void dijkstra(vector<vector<Edge>> &g, ll start){
    dist.assign(g.size(), INF);
    pre.assign(g.size(), -1);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[start] = 0;
    que.push({0, start});

    while(!que.empty()){
        auto[d, v] = que.top(); que.pop();
        if(dist[v] != d) continue;
        for(Edge& e : g[v]){
            ll next = d + e.cost; // next cost
            if(dist[e.to] <= next){
                continue;
            }else{
                dist[e.to] = next;
                que.push({next, e.to});
                pre[e.to] = v;
            }
        }
    } 
}

vector<ll> route_restoration(vector<ll> &pre, ll goal){
    ll now = goal;
    vector<ll> res;
    while(true){
        //cout << now << endl;
        res.push_back(now);
        if(pre[now] == -1) break;
        now = pre[now];
    }
    return res;
}

//mint dp[1010][101000];

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m, k; cin >> n >> m >> k;
    vector<long long> a(m);
    for(long long i = 0; i < m; i ++){
        cin >> a[i]; a[i]--;
    }
    vector<vector<Edge>> g(n);

    rep(i, n-1){
        ll u, v; cin >> u >> v; u--; v--;
        if(u == v) continue;
        g[u].push_back({v, 1}); g[v].push_back({u, 1});

        if(u < v){
            hen[{u, v}]++;
            hennum[{u, v}] = 0;
        }else{
            hen[{v, u}]++;
            hennum[{v, u}] = 0;
        }
        
    }


    //辺を通る回数
    rep(i, m-1){ //100
        ll u = a[i], v = a[i+1];
        if(u == v) continue;
        dijkstra(g, u);

        vector<ll> tmp = route_restoration(pre, v);

        rep(j, tmp.size()-1){
            ll x = tmp[j], y = tmp[j+1];
            if(x > y) swap(x, y);
            hennum[{x, y}]++;
        }

    }

    vector<ll> y;
    ll sum = 0;
    //cerr << "-map-" << endl;
    for(auto i : hennum){
        //cerr << "{" << i.first.first << " " << i.first.second << "} " << i.second << endl;
        y.push_back(i.second);
        sum += i.second;
    }

    //A = (sum + k) / 2の部分和問題

    ll A = (sum + k) / 2;
    //cout << A << " " << sum + k << endl;
    if((sum + k) % 2 != 0){
        cout << 0 << endl; return 0;
    }
    if(A < 0){
        cout << 0 << endl; return 0;
    }

    vector<vector<mint>> dp(y.size() + 5, vector<mint>(A + 10));
    dp[0][0] = 1;
    for(ll i = 0; i < y.size(); i++){
        for (int j = 0; j <= A; j++) {
            dp[i+1][j] += dp[i][j];
            if (j >= y[i]) dp[i+1][j] += dp[i][j-y[i]];
        }
    }

    /*
    for(auto i : hen){

        if(hennum.count({i.first.first, i.first.second}) == 0){
            dp[y.size()][A] *= 2;
        }

    }
    */

    cout << dp[y.size()][A] << endl;

}

