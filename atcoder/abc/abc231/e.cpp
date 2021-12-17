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
ll ans = INF;

/*
void calc(ll res, ll nowind, ll nowx){
    //cout << nowx << " " << nowind << " " << res <<endl;
    if(res > ans){
        return;
    }
    if(nowx == 0){
        ans = min(ans, res);
    }else{
        //nowindの金を何枚使うか
        ll dis = lower_bound(a.begin(), a.end(), nowx) - a.begin();
        nowind = min(nowind, dis);

        // if( (nowx % a[nowind]) == 0){
        //     ans = min(ans, res + nowx/a[nowind]);
        //     return;
        // }
        // if(nowind != 0 && (nowx % a[nowind-1]) == 0){
        //     ans = min(ans, res + nowx/a[nowind-1]);
        // }
        //cerr << "dis = " << dis << endl;

        ll mai = nowx / a[nowind];
        if(nowind == 0){
            calc(res+mai, nowind-1, nowx - a[nowind] * mai);
        }else{

            if(abs(nowx - a[nowind] * (mai+1)) > (nowx - a[nowind] * mai)){
                if(nowx >= (nowx - a[nowind] * mai) && res + mai < ans){
                    calc(res+mai, nowind-1, nowx - a[nowind] * mai);
                }
                if(nowx >= abs(nowx - a[nowind] * (mai+1)) && res + mai + 1 < ans){
                    calc(res+mai+1, nowind-1, abs(nowx - a[nowind] * (mai+1)));
                }
            }else{
                if(nowx >= abs(nowx - a[nowind] * (mai+1)) && res + mai + 1 < ans){
                    calc(res+mai+1, nowind-1, abs(nowx - a[nowind] * (mai+1)));
                }
                if(nowx >= (nowx - a[nowind] * mai) && res + mai < ans){
                    calc(res+mai, nowind-1, nowx - a[nowind] * mai);
                }
            }
            
            // if(res + mai < ans){
            //     if(nowx >= (nowx - a[nowind] * mai)){
            //         calc(res+mai, nowind-1, nowx - a[nowind] * mai);
            //     }
            // }
            // if(res + mai + 1 < ans){
            //     if(nowx >= abs(nowx - a[nowind] * (mai+1))){
            //         calc(res+mai+1, nowind-1, abs(nowx - a[nowind] * (mai+1)));
            //     }
            // }
            
        }
        //calc(a, res+mai, nowind-1, nowx - a[nowind] * mai);
        //calc(a, res+mai+1, nowind-1, abs(nowx - a[nowind] * (mai+1)));
    }

}
*/

map<ll, ll> memo;
ll calc2(vector<ll> &a, ll ind, ll x, ll mai){
    
    if(ind == a.size() - 1){
        return x / a[ind];
    }
    if(x == 0) return 0;

    ll tmp = x % a[ind+1];
    ll ans = calc2(a, ind+1, x - tmp, mai + tmp/a[ind]);
    ans = min(ans, calc2(a, ind+1, x + a[ind+1] - tmp, mai + (a[ind+1] - tmp) / a[ind]));
    return memo[x] = ans;
    
    if(memo.count(x) > 0) return memo[x];
    cout << "ind = " << ind << " x = " << x << " " << " mai = " << mai << endl;
    if(x == 0){
        ans = min(ans, mai); return mai;
    }
    if(ind == a.size() - 1){
        mai += x / a[ind];
        ans = min(ans, mai); return mai;
    }
    if(x % a[ind+1] == 0){
        //割り切れる場合次に進める
        calc2(a, ind+1, x, mai);
    }else{
        //割り切れない場合2パターン
        ll tmp = x % a[ind+1];
        calc2(a, ind+1, x - tmp , mai + tmp/a[ind]);
        calc2(a, ind+1, x + a[ind+1] - tmp, mai + (a[ind+1] - tmp) / a[ind]);
    }
    return memo[x] = mai;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
    }

    

    // ll dis = lower_bound(a.begin(), a.end(), x) - a.begin();
    // ll nowind = min(n-1, dis);

    // calc(0, nowind, x);

    cout << calc2(a, 0, x, 0) << endl;


}