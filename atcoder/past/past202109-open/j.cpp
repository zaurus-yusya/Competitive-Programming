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

//1-indexed only in the function
//O(log n)
//fenwick<ll> f(n)
template<typename T>
struct fenwick
{
    //constructor
    ll n;
    vector<T> bit;
    fenwick(ll n_) : n(n_ + 1), bit(n, 0) {}

    //method
    void add(ll i, T x){
        i += 1; //1-indexed
        for(ll idx = i; idx < n; idx += (idx & -idx)){
            bit[idx] += x;
        }
    }

    T sum(ll i){
        T s(0);
        //return sum[0, i)
        for(ll idx = i; idx > 0; idx -= (idx & -idx)){
            s += bit[idx];
        }
        return s;
    }

    T sum2(ll l, ll r){
        T L(0);
        T R(0);
        //return sum[l, r)
        for(ll idx = l; idx > 0; idx -= (idx & -idx)){
            L += bit[idx];
        }
        for(ll idx = r; idx > 0; idx -= (idx & -idx)){
            R += bit[idx];
        }
        return R - L;
    }

};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, q; cin >> n >> q;

    // t = 1 : output
    // t = 2 : reverse

    // 1 2 3 4 5 6
    // 2 -> 5 : 2 * n - x + 1

    // n = 3
    // 3 : k 1以上だった数
    // 2 : k 2以上だった数
    // 1 : k 3以上だった数

    fenwick<ll> fw(n + 1);
    rep(i, q){
        ll t, k; cin >> t >> k;
        if(t == 1){
            // output
            
            if(k > n){
                k = 2 * n - k + 1;
                ll tmp = fw.sum2(1, n+1);

                if(tmp % 2 == 1){
                    cout << k << endl;
                }else{
                    cout << 2 * n - k + 1 << endl;
                }

            }else{
                ll tmp = fw.sum2(1, n+1);
                if(tmp % 2 == 0){
                    cout << k << endl;
                }else{
                    cout << 2 * n - k + 1 << endl;
                }

            }
            
        }
        if(t == 2){
            // reverse
            fw.add(k, 1);

        }
    }


}