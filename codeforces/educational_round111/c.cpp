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

ll calc(ll x1, ll y1, ll x2, ll y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll n; cin >> n;
        vector<long long> a(n);
        vector<long long> x(n);
        vector<long long> y(n);
        for(long long i = 0; i < n; i ++){
            cin >> a[i];
            x[i] = a[i]; y[i] = i;

        }
        //vecdbg(x);
        //vecdbg(y);

        ll ans = 0;
        //1個はOK
        ans += n;
        //2個はOK
        ans += n-1;
        //3個検証
        vector<ll> vec = {0, 1, 2};
        for(ll i = 0; i < n-2; i++){
            bool flag = true;
            do{

                if(calc(x[i + vec[0]], y[i + vec[0]], x[i + vec[1]], y[i + vec[1]]) == calc(x[i + vec[0]], y[i + vec[0]], x[i + vec[2]], y[i + vec[2]]) + calc(x[i + vec[2]], y[i + vec[2]], x[i + vec[1]], y[i + vec[1]])){
                    flag = false;
                }

            }while(next_permutation(vec.begin(), vec.end()));

            if(flag){
                //cout << "3i = " << i << endl;
                ans++;
            }

        }
        //4個検証
        vec.push_back(3);
        for(ll i = 0; i < n-3; i++){
            bool flag = true;
            do{

                if(calc(x[i + vec[0]], y[i + vec[0]], x[i + vec[1]], y[i + vec[1]]) == calc(x[i + vec[0]], y[i + vec[0]], x[i + vec[2]], y[i + vec[2]]) + calc(x[i + vec[2]], y[i + vec[2]], x[i + vec[1]], y[i + vec[1]])){
                    flag = false;
                }

            }while(next_permutation(vec.begin(), vec.end()));
            if(flag){
                //cout << "4i = " << i << endl;
                ans++;
            }
        }
        //5個以上はダメ
        cout << ans << endl;


    }

}