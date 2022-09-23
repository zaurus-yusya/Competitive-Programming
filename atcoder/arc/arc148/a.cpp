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
// 50847478個

const int TIME_LIMIT = 1950;
int main() {
    std::cout << std::fixed << std::setprecision(15);
    clock_t start = clock();

    ll n; cin >> n;
    vector<long long> a(n);
    rep(i, n){
        cin >> a[i];
    }
    sort(all(a));
    // vecdbg(a);

    vector<ll> kaisa;
    rep(i, n-1){
        kaisa.push_back(a[i+1] - a[i]);
        // cout << a[i+1] - a[i] << endl;
    }

    ll x = 0;
    rep(i, n-1){
        x = gcd(kaisa[i], x);
    }
    // cerr << x << endl;

    if(x != 1){
        cout << 1 << endl;
    }else{
        cout << 2 << endl;
    }

    return 0;

    PrimeNumber p;
    vector<ll> era = p.eratosthenes(100000);

    // rep(i, n){
    //     map<ll, ll> mp = p.prime_factor(a[i]);
    //     for(auto& i: mp){
    //         cout << i.first << " " << i.second << endl;
    //     }
    // }

    ll ans = INF;

    rep(i, era.size()){
        ll num = era[i];
        
        bool f = true;
        map<ll, ll> mp;

        rep(j, n){
            mp[(a[j] % num)]++;
            if(mp.size() >= ans){
                f = false;
                break;
            }
        }

        if(f){
            ans = min(ans, (ll)mp.size());
            if(ans == 1){
                break;
            }
        }
        
        clock_t end = clock();
        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        if(time > TIME_LIMIT){
            break;
        }
    }
    cout << ans << endl;


    /*
    ll x = 0;
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
        x = gcd(x, a[i]);
    }
    // テスト
    ll y; cin >> y;
    rep(i, n){
        cout << a[i] % y << " ";
    }br;
    */

    
    /*
    for(ll i = 2; i <= 10740; i++){
        map<ll, ll> mp;
        vector<ll> tmp = a;
        rep(j, n){
            tmp[j] = tmp[j] % i;
            mp[tmp[j]]++;
        }
        if(mp.size() == 1){
            cout << i << endl;
        }
    }
    */

    /*
    cerr << "x = " << x << endl;

    if(x != 1){
        cout << 1 << endl;
    }else{
        map<ll, ll> mp;
        rep(i, n){
            a[i] = a[i] % 2;
            mp[a[i]]++;
        }
        cout << mp.size() << endl;
    }
    */
    


}