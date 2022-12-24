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


struct smart_sieve{
    ll L, R, M;
    vector<ll> small; // 小さい篩
    vector<vector<ll>> large; // 大きい篩
    vector<ll> aux;

    smart_sieve(ll L, ll R): L(L), R(R), M(sqrt(R)+1){
        small.resize(M);
        iota(small.begin(), small.end(), 0);
        large.resize(R-L);
        aux.assign(R-L, 1);

        for (ll i = 2; i*i < R; ++i) {
            if (small[i] < i) continue;
            small[i] = i;
            for (ll j = i*i; j < M; j += i)
                if (small[j] == j) small[j] = i;

            for (ll j = (L+i-1)/i*i; j < R; j += i) {
                ll k = j;
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
};


// nまでの整数の最小の素因数を格納した配列を返す
vector<ll> sieve(ll n){
    vector<ll> res(n+1);
    iota(res.begin(), res.end(), 0); // resのi番目の値にiを与える
    for(ll i = 2; i*i <= n; i++){
        if(res[i] < i) continue;
        for(ll j = i*i; j <= n; j += i){
            if(res[j] == j) res[j] = i;
        }
    }
    return res;
}

vector<ll> factor(ll n, const vector<ll> &min_factor){
    // min_factorはsieve()で得られたもの
    vector<ll> res;
    while(n > 1){
        res.push_back(min_factor[n]);
        n /= min_factor[n];
    }
    return res;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, k; cin >> n >> k;

    vector<ll> res = sieve(n);
    vecdbg(res);

    vector<ll> res2 = factor(n, res);
    vecdbg(res2);


}