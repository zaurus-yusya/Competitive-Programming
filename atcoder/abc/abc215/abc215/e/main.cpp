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

typedef ModInt<998244353> mint;
MComb<998244353> com(510000);
MPow<998244353> mpow;

mint dp[1010][1030][11];

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    string s; cin >> s;

    vector<char> master = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    //vector<vector<ll>> ind(10);
    map<char, ll> MP;
    map<char, ll> NUM;
    rep(i, 10){
        MP[master[i]] = i;
        NUM[master[i]] = (1<<i);
    }
    /*
    rep(i, n){
        rep(j, 10){
            if(s[i] == master[j]) ind[j].push_back(i);
        }
    }

    rep(i, 10){
        cout << master[i] << ": ";
        rep(j, ind[i].size()){
            cout << ind[i][j] << " ";
        }br;
    }
    */

    mint ans = 0;

    //hinagata
    //https://atcoder.jp/contests/past201912-open/submissions/18980789
    
    //vector<vector<mint>> dp(1010, vector<mint>(1030, 0));
    /*
    rep(k, 10){
        dp[0][0][k] = 1;
    }
    */
    
    for(ll i = 0; i < n; i++){ //1000
        ll num = MP[s[i]]; //文字番号

        for(ll j = 0; j < (1<<10); j++){//1024

            if(j == 0){
                //何も選ばれていない
                //選ぶ
                dp[i+1][j | (1<<num)][num] += 1;
            }

            for(ll k = 0; k < 10; k++){//10
                /*
                if(j == 0){
                    //何も選ばれてない
                    //選ぶ(初めて選ばれる)
                    if((j & (1<<num)) == 0){
                        //まだ選ばれてない
                        dp[i+1][j | (1 << num)][num] += 1;
                    }else if(k == num){
                        //選ばれているがラストチョイス
                        dp[i+1][j | (1 << num)][num] += 1;
                    }
                    //選ばない
                    dp[i+1][j][k] += dp[i][j][k]; 
                    continue;
                }
                */
                

                //選ぶ
                //既に選ばれてて最後に選んでる文字じゃなかったらダメ
                if((j & (1<<num)) == 0){
                    //まだ選ばれてない
                    dp[i+1][j | (1 << num)][num] += dp[i][j][k];
                }else if(k == num){
                    //既に選ばれているがラストチョイスがnumである
                    dp[i+1][j | (1 << num)][num] += dp[i][j][k];
                }

                //選ばない
                dp[i+1][j][k] += dp[i][j][k]; 
            }
        }

    }

    for(ll j = 1; j < (1<<10); j++){
        for(ll k = 0; k < 10; k++){
            ans += dp[n][j][k];
        }
    }
    cout << ans << endl;


    /*
    //hinagata
    //https://atcoder.jp/contests/past201912-open/submissions/18980789
    vector<ll> dp(1050, INF);
    dp[0] = 0;
    
    for(ll i = 0; i < (1<<n); i++){
        for(ll j = 0; j < m; j++){
            dp[i | num[j]] = min(dp[i | num[j]], dp[i] + C[j]);
        }
    }
    */
    



}