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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, k; cin >> n >> k;
    vector<long long> a(n);
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
    }

    ll ans = 0;
    ll now = 0;
    map<ll, ll> mp;
    vector<ll> ind;
    vector<ll> res;
    ll kaburi = -1;
    while(true){
        if(mp[now] > 0){
            kaburi = now;
            break;
        }else{
            //cerr << "added " << a[now % n] << endl;
            ind.push_back(now % n);
            res.push_back(a[now % n]);
            ans += a[now % n];
            mp[now % n]++;

            now += a[now % n];
            now = now % n;
        }
        //cout << "now = " << now << endl;
        k--;
        if(k == 0){
            break;
        }
    }
    cerr<< kaburi << endl;
    vecdbg(ind);
    vecdbg(res);

    ll start = -1;
    for(ll i = 0; i < ind.size(); i++){
        if(ind[i] == kaburi){
            start = i; break;
        }
    }
    cerr << start << endl;
    ll syuki = res.size() - start;


    ll sum = 0;
    for(ll i = start; i < res.size(); i++){
        sum += res[i];
    }
    cerr << sum << endl;

    ll x = k / syuki;
    ll nokori = k % syuki;

    ans += sum * x;
    for(ll i = start; i < start + nokori; i++){
        ans += res[i];
    }
    cout << ans << endl;


    /*
    ll x = k / res.size();
    ll sum = 0;
    rep(i, res.size()){
        sum += res[i];
    }
    





    ans += sum * x;
    k = k % n;

    for(ll i = 0; i < k; i++){
        ans += res[i];
    }

    cout << ans << endl;
    */


    /*
    vector<vector<ll>> vec(35, vector<ll>(n));
    rep(i, n){
        vec[0][i] = a[i];
    }

    for(ll i = 0; i <= 30; i++){
        rep(j, n){
            vec[i+1][j] = vec[i][vec[i][j]];
        }
    }
    vecdbg(vec[0]);
    ll ans = 0, now = 0, cnt = 0;

    while(k > 0){
        if(k & 1){
            ans += vec[cnt][now];
            now = vec[0][now];
            cerr << vec[cnt][now] << endl;
        }
        k= k >> 1; cnt++;
    }

    cout << ans << endl;
    */

}