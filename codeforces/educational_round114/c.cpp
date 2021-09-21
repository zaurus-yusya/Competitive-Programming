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
const long long INF = 8e18;
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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<long long> a(n); ll sum = 0;
    for(long long i = 0; i < n; i ++){
        cin >> a[i]; sum += a[i];
    }
    sort(all(a));

    ll m; cin >> m;
    vector<ll> x(m);
    vector<ll> y(m);
    rep(i, m){
        cin >> x[i] >> y[i];
    }

    rep(i, m){
        ll cnt = 0;
        ll dis = lower_bound(a.begin(), a.end(), x[i]) - a.begin();

        if(dis == 0){
            //一番左が攻撃
            cnt += max((ll)0, x[i] - a[0]);
            //それ以外で防御
            ll tmp = sum - a[0];
            cnt += max((ll)0, y[i] - tmp);
        }else if(dis == n){
            //一番右が攻撃
            cnt += max((ll)0, x[i] - a[n-1]);
            //それ以外で防御
            ll tmp = sum - a[n-1];
            cnt += max((ll)0, y[i] - tmp);
        }else{
            //左のやつが攻撃
            ll cnt2 = 0;
            cnt2 += max((ll)0, x[i] - a[dis-1]);
            ll tmp2 = sum - a[dis-1];
            cnt2 += max((ll)0, y[i] - tmp2);

            ///右のやつが攻撃
            ll cnt3 = 0;
            cnt3 += max((ll)0, x[i] - a[dis]);
            ll tmp3 = sum - a[dis];
            cnt3 += max((ll)0, y[i] - tmp3);

            cnt = min(cnt2, cnt3);

        }

        cout << cnt << '\n';
    }

}