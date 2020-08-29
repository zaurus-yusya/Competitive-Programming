#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e10;
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

map<ll, ll> g;
bool pair_flag = true;

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
    //map<long long, long long> prime_factor(long long n){
    void prime_factor(long long n){
        if(pair_flag == false){
            return;
        }
        //map<long long, long long> res;
        map<ll, ll> tmp; 
        for(long long i = 2; i * i <= n; i++){
            while(n % i == 0){
                n /= i;
                if(g[i] > 0 && tmp[i] == 0){
                    pair_flag = false;
                }
                //res[i]++;
                g[i]++;
                tmp[i]++;
                /*
                if(g[i] > 0){
                    pair_flag = false; 
                }
                g[i]++; 
                cout << i << endl;
                */
            }
        }
        if(n != 1){
            //res[n] = 1;
            if(g[n] > 0 && tmp[n] == 0){
                pair_flag = false;
            }
            g[n]++;
            tmp[n]++;
            /*
            if(g[n] > 0){
                pair_flag = false;
            }
            g[n] = 1;
            */
        } 

        //return res;
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
    vector<long long> vec(n);
    bool not_flag = false;
    for(long long i = 0; i < n; i ++){
        cin >> vec[i];
        if(vec[i] == 1) not_flag = true; 
    }

    ll semi;
    ll tmp;
    PrimeNumber p;
    rep(i, n){
        if(i == 0){
            if(vec[i] != 1) p.prime_factor(vec[i]);
            continue;
        } 
        if(i == 1){
            semi = gcd(vec[1], vec[0]);
        }else{
            semi = gcd(vec[i], semi);
        }
        if(vec[i] != 1) p.prime_factor(vec[i]);
    }

    if(pair_flag){
        cout << "pairwise coprime" << endl;
    }else if(semi == 1){
        cout << "setwise coprime" << endl;
    }else{
        if(not_flag){
            cout << "setwise coprime" << endl;
        }else{
            cout << "not coprime" << endl;
        }
    }

}