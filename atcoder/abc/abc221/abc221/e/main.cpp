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

typedef ModInt<998244353> mint;
MComb<998244353> com(510000);
MPow<998244353> mpow;

template <typename T>
struct Compress {

    //元の座標のリスト 座圧前の座標群をsortして重複を削除する
    vector<T> zahyo_list; 

    //元の配列が座圧されたものに書き換わる O(n logn)
    Compress(vector<T> &vec){
        zahyo_list = vec;
        sort(zahyo_list.begin(), zahyo_list.end());
        zahyo_list.erase(unique(zahyo_list.begin(), zahyo_list.end()), zahyo_list.end());
        for(ll i = 0; i < vec.size(); i++){
            vec[i] = lower_bound(zahyo_list.begin(), zahyo_list.end(), vec[i]) - zahyo_list.begin();
        }
    }

    //座圧後の配列の値の元の値を返す O(1)
    T moto_value(ll i){
        return zahyo_list[i];
    }
};

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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<long long> a(n);
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
    }
    Compress c(a);

    //vecdbg(a);

    fenwick<mint> fw(n+1);

    mint ans = 0;
    rep(i, n){
        //add
        ans += mpow.modpow(2, i-1) * fw.sum(a[i]+1);
        //cout << "i+1 = " << i+1 << endl;
        //cout << mpow.modpow(2, i-1) * fw.sum(a[i]+1) << endl;
        //fw add
        fw.add(a[i], (mint)1 / mpow.modpow(2, i));

        /*
        rep(j, 5){
            cout << fw.sum2(j, j+1) << " ";
        }br;
        */
    }
    cout << ans << endl;

}