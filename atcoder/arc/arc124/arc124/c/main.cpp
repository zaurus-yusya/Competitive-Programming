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

struct PrimeNumber
{
    //O(sqrt(n))
    //sosu hantei
    bool is_prime(long long n){
        for(long long i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return n != 1;
    }

    //O(sqrt(n))  isn't sorted
    //yakusu rekkyo
    vector<long long> divisor(long long n){
        vector<long long> res;
        for(long long i = 1; i * i <= n; i++){
            if(n % i == 0){
                res.push_back(i);
                if(i != n / i) res.push_back(n / i);
            }
        }
        return res;
    }

    //O(sqrt(n))
    //soinsu bunkai
    map<long long, long long> prime_factor(long long n){
        map<long long, long long> res;
        for(long long i = 2; i * i <= n; i++){
            while(n % i == 0){
                n /= i;
                res[i]++;
            }
        }
        if(n != 1) res[n] = 1;
        return res;
    }

    //O(n log log n)
    //n madeno sosu rekkyo
    vector<long long> eratosthenes(long long n){
        vector<long long> prime;
        vector<bool> is_prime(n + 1, true);
        long long p = 0;
        is_prime[0] = false; is_prime[1] = false;
        for(long long i = 2; i <= n; i++){
            if(is_prime[i]) prime.push_back(i);
            for(long long j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
        return prime;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;

    vector<ll> a(n);
    vector<ll> b(n);
    ll bunbo = 0;
    rep(i, n){
        cin >> a[i] >> b[i];
        bunbo = gcd(bunbo, a[i]);
        bunbo = gcd(bunbo, b[i]);
    }

    ll aa = a[0], bb = b[0];
    for(ll i = 1; i < n; i++){
        ll tmp_la = gcd(aa, a[i]);
        ll tmp_rb = gcd(bb, b[i]);

        ll tmp_ra = gcd(aa, b[i]);
        ll tmp_lb = gcd(bb, a[i]);

        ll lcm1 = lcm(tmp_la, tmp_lb);
        ll lcm2 = lcm(tmp_ra, tmp_lb);

        if(lcm1 > lcm2){
            aa = tmp_la;
            bb = tmp_rb;
        }else{
            aa = tmp_ra;
            bb = tmp_lb;
        }

        if(i == n-1){
            cout << lcm(aa, bb) << endl;
        }

    }

    return 0;

    /*
    lcm = m * n / gcd(m, n)
    */

    ll res_a = a[0];
    ll res_b = b[0];
    // 分子のm, nの候補は res_aの約数, res_bの約数

    PrimeNumber p;
    vector<ll> a0_divisor = p.divisor(res_a);
    vector<ll> b0_divisor = p.divisor(res_b);

    ll ans = 0;
    for(ll i = 0; i < a0_divisor.size(); i++){ // 100
        for(ll j = 0; j < b0_divisor.size(); j++){ // 100
            ll a_now = a0_divisor[i];
            ll b_now = b0_divisor[j];

            bool f = true;
            for(ll k = 0; k < n; k++){ // 50

                if(gcd(a[k], a_now) == a_now && gcd(b[k], b_now) == b_now){
                    // ok
                }else if(gcd(b[k], a_now) == a_now && gcd(a[k], b_now) == b_now){
                    // ok
                }else{
                    // ng
                    f = false; break;
                }
            }

            if(f){
                ans = max(ans, a_now * b_now / bunbo);
            }
        }
    }

    cout << ans << endl;

    // vector<ll> x = p.divisor(1000000000);
    // cout << x.size() << endl; // 100
}