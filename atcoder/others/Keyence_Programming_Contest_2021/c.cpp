#include <bits/stdc++.h>
#include <atcoder/all>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
using namespace atcoder;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// If the result in local and judge is different, USE CODETEST!!

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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll h, w, k; cin >> h >> w >> k;
    vector<vector<char>> vec(h, vector<char>(w, '.'));


    rep(i, k){
        ll x, y; cin >> x >> y; x--; y--;
        char c; cin >> c;
        vec[x][y] = c;
    }

    //vecvecdbg(vec);
    vector<vector<ll>> gyo_ruiseki(h, vector<ll>(w+1));
    vector<vector<ll>> retsu_ruiseki(w, vector<ll>(h+1));

    //横に見る
    rep(i, h)rep(j, w){
        if(vec[i][j] == '.'){
            gyo_ruiseki[i][j+1] = gyo_ruiseki[i][j] + 1;
            retsu_ruiseki[j][i+1] = retsu_ruiseki[j][i] + 1;
        }else{
            gyo_ruiseki[i][j+1] = gyo_ruiseki[i][j];
            retsu_ruiseki[j][i+1] = retsu_ruiseki[j][i];
        }
    }    

    vector<vector<mint>> dp(h+1, vector<mint>(w+1));
    dp[0][0] = 1;
    vector<mint> memo(5010, 0);
    rep(i, 5000){
        memo[i] = mpow.modpow(3, i);
    }

    //配るDP
    for(ll i = 0; i < h; i++){
        for(ll j = 0; j < w; j++){
            if(vec[i][j] == 'X'){
                //右に足す
                //dp[i][j+1] += dp[i][j] * mpow.modpow(3, (retsu_ruiseki[j][h] - retsu_ruiseki[j][i+1]));
                dp[i][j+1] += dp[i][j] * memo[retsu_ruiseki[j][h] - retsu_ruiseki[j][i+1]];
                //下に足す
                //dp[i+1][j] += dp[i][j] * mpow.modpow(3, (gyo_ruiseki[i][w] - gyo_ruiseki[i][j+1]));
                dp[i+1][j] += dp[i][j] * memo[gyo_ruiseki[i][w] - gyo_ruiseki[i][j+1]];
            }else if(vec[i][j] == 'R'){
                //右に足す
                //dp[i][j+1] += dp[i][j] * mpow.modpow(3, (retsu_ruiseki[j][h] - retsu_ruiseki[j][i+1]));
                dp[i][j+1] += dp[i][j] * memo[retsu_ruiseki[j][h] - retsu_ruiseki[j][i+1]];
            }else if(vec[i][j] == 'D'){
                //下に足す
                //dp[i+1][j] += dp[i][j] * mpow.modpow(3, (gyo_ruiseki[i][w] - gyo_ruiseki[i][j+1]));
                dp[i+1][j] += dp[i][j] * memo[gyo_ruiseki[i][w] - gyo_ruiseki[i][j+1]];
            }else{
                //右に足す 2倍(RのときとXのとき)
                //dp[i][j+1] += dp[i][j] * mpow.modpow(3, (retsu_ruiseki[j][h] - retsu_ruiseki[j][i+1])) * 2;
                dp[i][j+1] += dp[i][j] * memo[retsu_ruiseki[j][h] - retsu_ruiseki[j][i+1]] * 2;
                //下に足す 2倍(DのときとXのとき)
                //dp[i+1][j] += dp[i][j] * mpow.modpow(3, (gyo_ruiseki[i][w] - gyo_ruiseki[i][j+1])) * 2;
                dp[i+1][j] += dp[i][j] * memo[gyo_ruiseki[i][w] - gyo_ruiseki[i][j+1]] * 2;
            }
        }
    }
    
    if(vec[h-1][w-1] == '.'){
        dp[h-1][w-1] = dp[h-1][w-1] * 3;
    }
    cout << dp[h-1][w-1] << endl;
    
}