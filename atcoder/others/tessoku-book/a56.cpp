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

// 乱数生成部分
std::random_device rd;
std::default_random_engine eng(rd());
std::uniform_int_distribution<int> distr(2, 998244353 - 2); // [l, r]の乱数生成

struct RollingHash // 衝突されるかも。注意
{
    ll mod_rh = 998244353;
    ll base1 = distr(eng);
    ll base2 = distr(eng);
    vector<ll> hash1;
    vector<ll> hash2;
    vector<ll> pow1;
    vector<ll> pow2;

    RollingHash(string s){
        ll n = s.size();
        hash1.assign(n+1, 0);
        hash2.assign(n+1, 0);
        pow1.assign(n+1, 1);
        pow2.assign(n+1, 1);    

        for(ll i = 0; i < n; i++){
            hash1[i+1] = (hash1[i] * base1 + s[i]) % mod_rh;
            hash2[i+1] = (hash2[i] * base2 + s[i]) % mod_rh;
            pow1[i+1] = (pow1[i] * base1) % mod_rh;
            pow2[i+1] = (pow2[i] * base2) % mod_rh;
        }
    }

    // 文字列sの [l, r) のハッシュ値を返す
    pair<ll, ll> get(ll l, ll r){
        ll res1 = hash1[r] - hash1[l] * pow1[r - l] % mod_rh;
        if(res1 < 0) res1 += mod_rh;
        ll res2 = hash2[r] - hash2[l] * pow2[r - l] % mod_rh;
        if(res2 < 0) res2 += mod_rh;
        return {res1, res2};
    }

};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, q; cin >> n >> q;
    string s; cin >> s;

    RollingHash rh(s);

    rep(i, q){
        ll a, b, c, d; cin >> a >> b >> c >> d;
        a--; c--;
        pair<ll, ll> p1 = rh.get(a, b);
        pair<ll, ll> p2 = rh.get(c, d);
        if(p1 == p2){
            cout << "Yes" << '\n';
        }else{
            cout << "No" << '\n';
        }
    }

}