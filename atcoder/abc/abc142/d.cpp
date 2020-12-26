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
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b == 0) (a/b) + 1
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
    ll a, b; cin >> a >> b;
    PrimeNumber p;
    vector<ll> ag = p.divisor(a);
    vector<ll> bg = p.divisor(b);
    map<ll, ll> mp;
    rep(i, ag.size()){
        mp[ag[i]] += 1;
    }
    rep(i, bg.size()){
        mp[bg[i]] += 1;
    }
    map<ll, ll> res;
    for(auto i : mp){
        if(i.second == 2) res[i.first]++;
    }
    

    vector<ll> tmp;
    for(auto i : res){
        if(i.first == 1) continue;
        bool flag = true;
        for(ll j = 0; j < tmp.size(); j++){
            if(i.first % tmp[j] == 0) flag = false;
        }
        if(flag) tmp.push_back(i.first);
    }
    cout << tmp.size() + 1 << endl; 

}