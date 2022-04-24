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


#define MOD 998244353

typedef ModInt<MOD> mint;
MComb<MOD> com(510000);
MPow<MOD> mpow;

ll dp[6010][9010][4];
int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, p; cin >> n >> p;
    // i = 1 ~ i = n-1
    // 辺の本数3n - 2
    // 何本抜いたか
    // 0なし, 1あり
    dp[0][0][1] = 1;
    dp[0][1][0] = 1;

    cout << 6010 * 9010 * 4 << endl;

    // 2 * n - 1状態
    for(ll i = 0; i < 2*n - 1; i++){
        if(i == 0){
            dp[i+1][0][1] = 1;
            dp[i+1][1][0] = 1;
            continue;
        }
        // 0なし 1あり
        // 0なし 1上だけ 2下だけ 3両方
        for(ll j = 0; j < 2*n - 1; j++){
            if(i % 2== 0){
                //縦の辺
                dp[i+1][j][0] += 

            }else{
                //横の辺

                //縦の辺がない場合、少なくとも1つつける
                dp[i+1][j+1][1] += dp[i][j][0]; dp[i+1][j+1][1] = dp[i+1][j+1][1] % p;
                dp[i+1][j+1][2] += dp[i][j][0]; dp[i+1][j+1][2] = dp[i+1][j+1][1] % p;
                dp[i+1][j+2][3] += dp[i][j][0]; dp[i+1][j+2][3] = dp[i+1][j+1][1] % p;

                //縦の辺がある場合、少なくとも1つつける
                dp[i+1][j+1][1] += dp[i][j][1]; dp[i+1][j+1][1] = dp[i+1][j+1][1] % p;
                dp[i+1][j+1][2] += dp[i][j][1]; dp[i+1][j+1][2] = dp[i+1][j+1][1] % p;
                dp[i+1][j+2][3] += dp[i][j][1]; dp[i+1][j+2][3] = dp[i+1][j+1][1] % p;

            }
            /////
            if(i % 3 == 0){
                //縦の辺
                dp[i+1][]
            }else{
                //縦の辺がなかったら上か下をつける
                dp[i+1][] += dp[i][j][0]

            }
            if(i % 3 == 1){
                //上の辺
                //縦の辺がなかったらつける
                dp[i+1][j][1] += dp[i][j][0];

                //縦の辺があったら、つけてもつけなくてもよい
                dp[i+1][j][1] += dp[i][j][1];
                dp[i+1][j+1][0] += dp[i][j][1];


            }
            if(i % 3 == 2){
                // 下の辺

            }
            

        }
    }

}