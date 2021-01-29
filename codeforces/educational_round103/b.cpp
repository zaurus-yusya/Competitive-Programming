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
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
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
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        ll n, k; cin >> n >> k;
        vector<long long> p(n);
        vector<ll> sum(n+1);
        for(long long i = 0; i < n; i ++){
            cin >> p[i];
            sum[i+1] = sum[i] + p[i];
        }


        ll now = p[0];
        ll ans = 0;

        
        for(ll i = 0; i < n-1; i++){
            //cout << 100 * p[i+1] << " " << k * now << endl;
            if(100 * p[i+1] > k * now){

                ans += ceilll((100 * p[i+1] - k * now) , k);

                //cout << "----" << endl;
                //cout << 100 * p[i+1] - k * now << endl;
                now += ceilll((100 * p[i+1] - k * now) , k);
                //cout << 100 * p[i+1] << " " << k * now << endl;
                //cout << "----" << endl;

                now += p[i+1];
            }else{
                now += p[i+1];
            }
        }

        cout << ans << endl;


    }

}