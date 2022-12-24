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

vector<ll> kouho;
map<ll, ll> memo;
void calc(ll x){
    if(memo.count(x) > 0){
        return;
    }else{
        kouho.push_back(x);
        memo[x]++;
        if(x % 2 == 0){
            calc(x / 2);
        }
        if(x % 3 == 0){
            calc(x / 3);
        }
    } 
}

map<ll, ll> memo2;
ll res = INF;
void calc2(ll x, ll cnt, ll y){
    if(x == y){
        res = min(res, cnt);
    }

    if(memo2.count(x) > 0){
        return;
    }else{
        memo2[x]++;
        if(x % 2 == 0){
            calc2(x / 2, cnt+1, y);
        }
        if(x % 3 == 0){
            calc2(x / 3, cnt+1, y);
        }
    } 
}




int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<long long> a(n);
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
    }

    calc(a[0]);


    ll ans = INF;
    rep(i, kouho.size()){
        ll tmp = 0;
        // cerr << kouho[i] << endl;
        
        bool f = true;
        rep(j, n){
            res = INF;
            memo2.clear();

            calc2(a[j], 0, kouho[i]);
            if(res == INF){
                f = false; break;
            }else{
                tmp += res;
            }

        }

        if(f){
            ans = min(ans, tmp);
        }
    }

    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

}