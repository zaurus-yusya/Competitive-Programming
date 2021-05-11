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
const long long INF = 1e18;
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

vector<ll> use(10010);
vector<ll> ans;

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

PrimeNumber p;
vector<ll> era = p.eratosthenes(5000);

void calc(ll now, vector<ll> vec){
    
    if(now > 10000){
        return;
    }

    use[now] = 1;
    ans.push_back(now);

    for(ll i = 0; i < vec.size(); i++){
        if(now * vec[i] > 10000) break;
        if(use[now * vec[i]] == 0){
            calc(now * vec[i], vec);
        }
    }

    for(ll i = 3; i < era.size(); i++){

        if(now * era[i] > 10000) break;
        if(use[now * era[i]] == 0){
            calc(now * era[i], vec);
        }

    }

}


bool test(vector<ll> &res){

    for(ll i = 0; i < res.size(); i++){
        for(ll j = i+1; j < res.size(); j++){
            if(gcd(res[i], res[j]) == 1){
                return false;
            }
        }
    }

    ll x = 0;
    for(ll i = 0; i < res.size(); i++){
        if(i == 0){
            x = res[i];
        }else{
            x = gcd(x, res[i]);
        }
    }
    if(x != 1){
        return false;
    }

    return true;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;

    vector<ll> x = {2, 3};
    vector<ll> y = {2, 5};
    vector<ll> z = {3, 5};
    vector<ll> w = {2, 3, 5};
    
    calc(6, x);
    calc(10, y);
    calc(15, z);
    calc(30, w);

    //cout << ans.size() << endl;
    sort(all(ans));

    if(n == 3){
        cout << 6 << " " << 10 << " " << 15 << endl;
    }else{
        rep(j, n){
            cout << ans[j] << " ";
        }br;
        /*
        for(ll i = 4; i <= 2500; i++){
            vector<ll> res;
            rep(j, i){
                //cout << ans[i] << " ";
                res.push_back(ans[j]);
            }

            if(test(res)){
                cout << "i = " << i <<" ok" << endl;
            }else{
                cout << "i = " << i <<" ng" << endl;
            }
        }
        */
    }

}