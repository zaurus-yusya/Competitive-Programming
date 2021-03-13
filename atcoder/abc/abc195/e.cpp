#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;

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

typedef ModInt<7> mint;
MComb<7> com(510000);
MPow<7> mpow;

mint dp[200010][7];
int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    string s, x; cin >> s >> x;

    mint ans = 0;
    map<ll, ll> taka;
    map<ll, ll> aoki;
    for(ll i = 0; i < n - 1; i ++){
        ll num = s[i] - '0';
        //cout << "num = " << num << endl;
        mint mo = (mint)num * mpow.modpow(10, n-1-i);
        //cout << "mo = " << mo << endl;
        if(x[i] == 'T'){
            taka[(ll)mo]++;
        }else{
            aoki[(ll)mo]++;
        }
    }
    
    //cout << "-taka-" << endl;
    map<ll, ll> takacan; //7回まででいい
    takacan[0] = 1;
    for(auto i : taka){
        //cout << i.first << " " << i.second << endl;
        map<ll, ll> tmp;
        for(ll j = 0; j <= 6; j++){
            if(takacan[j] == 0) continue;
            for(ll k = 0; k < i.second; k++){
                if(k >= 7) break;
                ll x = (j + i.first) % 7;
                tmp[x]++;
            }
        }

        for(auto j: tmp){
            takacan[j.first]++;
        }
    }

    //cout << "-aoki-" << endl;
    map<ll, ll> aokican;
    aokican[0] = 1;
    for(auto i : aoki){
        //cout << i.first << " " << i.second << endl;
        map<ll, ll> tmp;
        for(ll j = 0; j <= 6; j++){
            if(aokican[j] == 0) continue;
            for(ll k = 0; k < i.second; k++){
                if(k >= 7) break;
                ll x = (j + i.first) % 7;
                tmp[x]++;
            }
        }

        for(auto j: tmp){

            aokican[j.first]++;
        }
    }

    /*
    cout << "-takacan-" << endl;
    for(auto i: takacan){
        cout << i.first << " " << i.second << endl;
    }
    cout << "-aokican-" << endl;
    for(auto i: aokican){
        cout << i.first << " " << i.second << endl;
    }
    */

    ll num = s[n-1] - '0';
    if(x[n-1] == 'T'){
        for(auto i: aokican){
            if(i.first == 0) continue;
            if(i.second > 0){
                if(takacan[7 - i.first] == 0){
                    if(num != 0 && i.first != 7 - num){
                        cout << "Aoki" << endl; return 0;
                    }
                }
            }
        }
        cout << "Takahashi" << endl;
    }
    if(x[n-1] == 'A'){
        if(num != 0){
            cout << "Aoki" << endl; return 0;
        }else{
            
        }
    }
    

    

}