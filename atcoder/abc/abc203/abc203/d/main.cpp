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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, k; cin >> n >> k;
    ll X = k*k/2 + 1;

    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i, n)rep(j, n){
        cin >> a[i][j];
    }

    vector<vector<long long>> vec(n, vector<long long>(n));
    vector<vector<long long>> sum(n+1, vector<long long>(n+1));
    ll ok = 1e9+1, ng = -1;
    while(ok - ng > 1){
        ll mid = (ng + ok) / 2;

        rep(i, n){
            rep(j, n){
                if(a[i][j] > mid){
                    vec[i][j] = 1;
                }else{
                    vec[i][j] = 0;
                }
            }
        }
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < n; j++){
                sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + vec[i][j];
            }
        }

        bool flag = false;
        for(ll i = k; i <= n; i++){
            for(ll j = k; j <= n; j++){
                if(sum[i][j] - sum[i-k][j] - sum[i][j-k] + sum[i-k][j-k] < X){
                    flag = true; break;
                }
            }
            if(flag) break;
        }

        if(flag){
            ok = mid;
        }else{
            ng = mid;
        }


    }

    cout << ok << endl;


    /*
    long long h, w; cin >> h >> w;
    vector<vector<long long>> vec(h, vector<long long>(w));
    for(long long i = 0; i < h; i++){
        for(long long j = 0; j < w; j++){
            cin >> vec[i][j];
        }
    }
    
    vector<vector<long long>> sum(h+1, vector<long long>(w+1));
    for(long long i = 0; i < h; i++){
        for(long long j = 0; j < w; j++){
            sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + vec[i][j];
        }
    }
    
    long long q; cin >> q;
    // sum of [x1, y1) ~ [x2, y2)
    for(long long i = 0; i < q; i++){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1] << endl;
    }
    */
}