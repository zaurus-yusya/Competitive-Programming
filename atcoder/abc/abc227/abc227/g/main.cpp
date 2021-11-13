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

class smart_sieve {
  intmax_t L, R, M;
  std::vector<int> small;  // 小さい篩
  std::vector<std::vector<intmax_t>> large;  // 大きい篩
  std::vector<intmax_t> aux;  // aux[i] := large[i] の素因数の積

public:
  smart_sieve(intmax_t L, intmax_t R): L(L), R(R), M(sqrt(R)+1) {
    small.resize(M);
    std::iota(small.begin(), small.end(), 0);
    large.resize(R-L);
    aux.assign(R-L, 1);

    for (intmax_t i = 2; i*i < R; ++i) {
      if (small[i] < i) continue;
      small[i] = i;
      for (intmax_t j = i*i; j < M; j += i)
        if (small[j] == j) small[j] = i;

      for (intmax_t j = (L+i-1)/i*i; j < R; j += i) {
        intmax_t k = j;
        do {
          // aux[j-L] > M で判定した方がいいかも？
          // j / aux[j-L] < M の方がいい？（割り算したくない）
          if (aux[j-L] * aux[j-L] > R) break;

          large[j-L].push_back(i);
          aux[j-L] *= i;
          k /= i;
        } while (k % i == 0);
      }
    }
  }

  std::vector<intmax_t> factor(intmax_t n) {
    assert(L <= n && n < R);
    std::vector<intmax_t> res = large[n-L];
    n /= aux[n-L];
    if (n >= M) {
      // この場合，n は素数となることが示せる（はず）
      // n*n >= R だとオーバーフローしそう？
      res.push_back(n);
      return res;
    }
    while (n > 1) {
      res.push_back(small[n]);
      n /= small[n];
    }
    return res;
  }
};

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
MPow<998244353> mpow;

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, k; cin >> n >> k;
    //ll L, R; cin >> L >> R;

    ll L = n - k + 1;
    ll R = n + 1;
    //scanf("%jd %jd", &L, &R);
    //L = 1e12 - 1e6;
    //R = 1e12;

    smart_sieve ss(L, R);
    unordered_map<ll, ll> mp;
    //map<ll, ll> mp;
    for (ll i = L; i < R; ++i) {
        auto f = ss.factor(i);
        
        //printf("%jd:", i);
        for (const auto& j: f){
            mp[j]++;
            //printf(" %jd", j);
        }
        //printf("\n");
        
    }

    L = 1;
    R = k+1;
    smart_sieve sss(L, R);
    for (ll i = L; i < R; ++i) {
        auto f = sss.factor(i);
        
        for (const auto& j: &f){
            mp[j]--;
        }
        
    }

    mint ans = 1;
    for(auto& i : mp){
        ans *= (i.second + 1);
    }

    cout << ans << endl;

    
    


}