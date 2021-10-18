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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    ll x = 1;
    ld t = 0;
    rep(i, n){
        cin >> a[i] >> b[i];
        x = lcm(x, b[i]);
        t += (ld)a[i] / (ld)b[i];
    }
    //cout << t << endl;

    t = t / (ld)2;
    ld ans = 0;
    rep(i, n){
        ld x = (ld)a[i] / (ld)b[i];
        if(t - x <= 0){
            ans += (ld)b[i] * t;
            break;
        }else{
            ans += a[i];
            t -= x;
        }
    }
    cout << ans << endl;


    /*
    vector<ll> aa(n);
    vector<ll> bb(n);

    ld sum = 0;
    //cerr << "x = " << x << endl;
    rep(i, n){
        aa[i] = a[i] * (x / b[i]);
        bb[i] = x;
        sum += aa[i];
    }
    //cerr << "sum = " << sum << endl;

    sum = sum / (ld)2;
    //cout << "sum = " << sum << endl;

    ll now = 0;

    rep(i, n){
        //cerr << "summ = " << sum << " " << aa[i] << endl;
        if(sum - (ld)aa[i] <= (ld)0){
            //全部使わない
            break;
        }
        //全部つかう
        sum -= (ld)aa[i];
        now += 1;
        //cerr << "summm = " << sum << " " << aa[i] << endl;
    }


    ld ans = 0;
    rep(i, now){
        ans += (ld)a[i];
        cout << ans << endl;
    }

    // cout << "in2 "<< endl;
    // cerr << "ans = " << ans << endl;
    // cerr << "now = " << now << endl;
    //cout << sum << " " << x << " " << a[now] << endl;
    cout << sum << endl;
    cout << aa[now] / a[now] << endl;
    ld tmp = aa[now] / a[now];
    //ans += (ld)sum / (ld)((ld)aa[now] / (ld)a[now]);

    ans += sum / aa[now] * a[now];
    // cout << "in3 "<< endl;
    cout << ans << endl;
    */


}