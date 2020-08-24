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
ll ceilll(ll a, ll b) {return (a + b-1) / b;}
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

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
    ll t; cin >> t;
    rep(T, t){
        ll n, k, w; cin >> n >> k >> w;
        vector<long long> l(k);
        for(long long i = 0; i < k; i ++){
            cin >> l[i];
        }
        ll al, bl, cl, dl; cin >> al >> bl >> cl >> dl;
        vector<long long> h(k);
        for(long long i = 0; i < k; i ++){
            cin >> h[i];
        }
        ll ah, bh, ch, dh; cin >> ah >> bh >> ch >> dh;

        if(n > k){
            ll cnt = 1;
            for(ll i = k; i < n; i++){
                ll tmp_l = ((al * l[i-2] + bl * l[i-1] + cl) % dl) + 1;
                l.push_back(tmp_l);
                ll tmp_h = ((ah * h[i-2] + bh * h[i-1] + ch) % dh) + 1;
                h.push_back(tmp_h);
                cnt++;
            }
        }

        /*
        rep(i, l.size()){
            cout << l[i] << " ";
        }br;
        rep(i, h.size()){
            cout << h[i] << " ";
        }br;
        */

        vector<ll> p(n);
        ll start_w = 0;
        ll end_w = 0;
        ll max_h = 0;
        ll before_p = 0;
        rep(i, n){
            if(i == 0){
                start_w = l[i];
                end_w = l[i] + w;
                max_h = h[i];
            }else{
                if(end_w < l[i]){
                    before_p = p[i-1];
                    start_w = l[i];
                    end_w = l[i] + w;
                    max_h = h[i];
                }else{
                    end_w = l[i] + w;
                    max_h = max(max_h, h[i]);
                }
            }

            p[i] = (before_p + ((end_w - start_w) * 2 % MOD) + (max_h * 2 % MOD)) % MOD;
        }
        /*
        rep(i, n){
            cout << p[i] << " ";
        }br;
        */

        ll ans = 1;
        rep(i, n){
            ans = (ans * p[i]) % MOD;
            cout << ans << " " << i << endl;
        }
        cout << ans << endl;





    }

}