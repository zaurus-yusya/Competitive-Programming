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

template <typename T>
struct Compress {

    //元の座標のリスト 座圧前の座標群をsortして重複を削除する
    vector<T> zahyo_list; 
    ll si;

    //元の配列が座圧されたものに書き換わる O(n logn)
    Compress(vector<T> &vec){
        zahyo_list = vec;
        sort(zahyo_list.begin(), zahyo_list.end());
        zahyo_list.erase(unique(zahyo_list.begin(), zahyo_list.end()), zahyo_list.end());
        si = vec.size();
        for(ll i = 0; i < vec.size(); i++){
            vec[i] = lower_bound(zahyo_list.begin(), zahyo_list.end(), vec[i]) - zahyo_list.begin();
        }
    }

    //座圧後の配列の値の元の値を返す O(1)
    T moto_value(ll i){
        return zahyo_list[i];
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(15);

    ll n; cin >> n;
    vector<long long> c(n);
    for(long long i = 0; i < n; i ++){
        cin >> c[i]; c[i]--;
    }
    vector<long long> x(n);
    for(long long i = 0; i < n; i ++){
        cin >> x[i]; x[i]--;
    }

    vector<vector<ll>> vec(n);
    rep(i, n){
        vec[c[i]].push_back(x[i]);
    } 


    ll sub = 0;
    rep(i, vec.size()){
        if(vec[i].size() == 0) continue;
        Compress<ll> comp(vec[i]);

        fenwick<ll> tmpf(comp.si);
        ll tmp = 0;
        rep(j, vec[i].size()){
            tmp += j - tmpf.sum(vec[i][j] + 1);
            tmpf.add(vec[i][j], 1);
        }
        sub += tmp;
        
    }


    fenwick<ll> f(n);
    ll ans = 0;
    rep(i, n){
        ans += i - f.sum(x[i] + 1);
        f.add(x[i], 1);
    }

    cout << ans - sub << endl;

}