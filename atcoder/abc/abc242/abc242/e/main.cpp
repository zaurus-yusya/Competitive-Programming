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

//mint dp[100010][2][2]; //前で未満, 後ろで超えたか
int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll n; cin >> n;
        string s; cin >> s;

        //dp[0][0][0] = 1;
        vector<vector<vector<mint>>> dp(n+10, vector<vector<mint>>(2, vector<mint>(2))); 
        dp[0][0][0] = 1;
        //dp[0][0][1] = 1;
        for(ll i = 0; i < (n+1)/2; i++){
            //前の文字
            char bef = s[i];
            char ato = s[s.size() - 1 - i];
            //cerr << bef << " " << ato << endl;

                for(ll j = 0; j < 26; j++){
                    //jを選択
                    //Sの文字
                    ll befll = bef - 'A';
                    ll atoll = ato - 'A';
                    ll nowll = j;

                    //ギリギリからの遷移
                    if(befll >= nowll){
                        if(befll == nowll){
                            if(atoll < nowll){
                                //後ろで超えた
                                dp[i+1][0][1] += dp[i][0][0];

                                //元々超えてた
                                dp[i+1][0][1] += dp[i][0][1];
                            }else{
                                //後ろで超えてない
                                dp[i+1][0][0] += dp[i][0][0];

                                //超えたから超えてない
                                dp[i+1][0][0] += dp[i][0][1];
                            }
                        }else{
                            if(atoll < nowll){
                                //後ろで超えた
                                dp[i+1][1][1] += dp[i][0][0];

                                //元々超えてた
                                dp[i+1][1][1] += dp[i][0][1];
                            }else{
                                //後ろで超えてない
                                dp[i+1][1][0] += dp[i][0][0];

                                //超えたから超えてない
                                dp[i+1][1][0] += dp[i][0][1];
                            }
                        }
                    }

                    //なんでも良いからの遷移
                    if(atoll < nowll){
                        //後ろで超えた
                        dp[i+1][1][1] += dp[i][1][0];

                        //元々超えてた
                        dp[i+1][1][1] += dp[i][1][1];
                    }else{
                        //後ろで超えていない
                        dp[i+1][1][0] += dp[i][1][0];

                        //超えたから超えてない
                        dp[i+1][1][0] += dp[i][1][1];
                    }
                }

        }


        mint ans = 0;
        ans += dp[(n+1)/2][0][0];
        ans += dp[(n+1)/2][0][1];
        ans += dp[(n+1)/2][1][0];
        ans += dp[(n+1)/2][1][1];

        vector<char> x(n);
        for(ll i = 0; i < (n+1)/2; i++){
            x[i] = s[i];
            x[n - 1 - i] = s[i];
        }
        string y = "";
        rep(i, n){
            y += x[i];
        }
        if(y > s){
            ans -= 1;
        }

        cout << ans << '\n';
    }

}