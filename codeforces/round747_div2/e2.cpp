#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
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

typedef ModInt<1000000007> mint;
MComb<1000000007> com(510000);
MPow<1000000007> mpow;

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll k; cin >> k;
    ll m; cin >> m;

    map<string, ll> color;
    color["white"] = 1;
    color["yellow"] = 1;
    color["green"] = 2;
    color["blue"] = 2;
    color["red"] = 4;
    color["orange"] = 4;
    //white yellow   001
    //green blue     010
    //red orange     100

    bool flag = false;
    vector<pair<ll, ll>> vec;

    map<ll, ll> nuri; //nodeの塗られている色
    rep(i, m){
        ll x; cin >> x; string s; cin >> s;
        if(x == 1) flag = true;
        ll y = color[s];
        nuri[x] = y;
        vec.push_back({x, y});
    }
    sort(all(vec));

    map<ll, ll> mp; //nodeのダメな色
    rep(i, m){
        ll node = vec[i].first, iro = vec[i].second;
        // /2
        if(node != 1) mp[node/2] |= iro;
        // *2
        if(node < POW(2, k-1)) mp[node*2] |= iro;
        // *2 + 1
        if(node < POW(2, k-1)) mp[(node*2) + 1] |= iro;
    }

    bool f = true;
    //塗られてるところ判定
    for(auto i : nuri){
        if(mp.count(i.first) > 0){
            if((i.second & mp[i.first]) != 0){
                f = false;
            }
        }
    }
    if(!f){
        cout << 0 << endl; return 0;
    }


    mint ans = 1;
    rep(i, k){
        ll node = POW(2, i);
        //cout << node << endl;
        if(i == 0){
            ans *= node * 6;
        }else{
            ans *= mpow.modpow(4, node);
        }
    }

    //色指定されたところを割る
    if(flag){
        ans /= (mint)6;
        ans /= mpow.modpow(4, m-1);
    }else{
        ans /= mpow.modpow(4, m);
    }

    //影響範囲を割る
    for(auto i : mp){
        if(nuri.count(i.first) > 0) continue;

        ll cnt = 0;
        ll x = i.second;
        while(x > 0){
            if((x & 1)) cnt++;
            x = x >> 1;
        }

        if(i.first == 1){
            mint y = 2 * (3 - cnt);
            ans /= (mint)6;
            ans *= y;
        }else{
            mint y = 2 * (3 - cnt);
            if(cnt == 0){
                y = 4;
            }
            ans /= (mint)4;
            ans *= y;
        }

    }



    cout << ans << endl;

}