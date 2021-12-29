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
// for(auto& i: mp) &&&&&&&&&&&&&

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<long long> p(n);
    ll oneind = -1;
    for(long long i = 0; i < n; i ++){
        cin >> p[i];
        if(p[i] == 1){
            oneind = i;
        }
    }

    bool f = true;
    if(p[oneind] + 1 == p[(oneind+1) % n]){

    }else{
        f = false;
    }

    ll ans = INF;

    if(n == 2){
        if(oneind == 0){
            cout << 0 << endl;
        }else{
            cout << 1 << endl;
        }
        return 0;
    }

    // 5 - 4 - 1
    // 5 - 2 - 1
    // 0 1 2 3 4
    // 4 3 2 1 0
    if(f){
        //しない, しない
        ans = min(ans, max(oneind, 0LL));
        cerr << max(oneind, 0LL) << endl;

        //する, する
        ll tmp = n - oneind - 1;
        ll x = (tmp+1) != n ? tmp + 1 : 0;
        ans = min(ans, 1 + x + 1);
        cerr << 1 + tmp + 1 << endl;

    }else{
        //しない, する
        ll x = (oneind+1) != n ? oneind + 1 : 0;
        ans = min(ans, x + 1);
        cerr << n - oneind - 1 + 1 << endl;

        //する, しない
        ll tmp = n - oneind - 1;
        ans = min(ans, 1 + max(tmp, 0LL));
        //ans = min(ans, 1 + max((n - oneind - 1) - 1, 0LL));
        cerr << 1 + max((n - oneind - 1) - 1, 0LL) << endl;
    }

    cout << ans << endl;



    



    


}