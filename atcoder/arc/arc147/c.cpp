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

bool cmp_r(pair<ll, ll> a, pair<ll, ll> b){
    if(a.first != b.first){
        return a.first < b.first;
    }else{
        return a.second < b.second;
    }
}

bool cmp_l(pair<ll, ll> a, pair<ll, ll> b){
    if(a.first != b.first){
        return a.first > b.first;
    }else{
        return a.second < b.second;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<pair<ll, ll>> vec(n);
    vector<pair<ll, ll>> vec2(n);
    vector<ll> l(n);
    vector<ll> r(n);
    vector<pair<ll, ll>> L(n);
    vector<pair<ll, ll>> R(n);
    rep(i, n){
        cin >> l[i] >> r[i];
        L[i] = {l[i], i};
        R[i] = {r[i], i};
        vec[i] = {l[i], r[i]};
        vec2[i] = {l[i], r[i]};
    }

    sort(all(L), cmp_l);
    sort(all(R), cmp_r);
    map<ll, ll> mp;
    vector<ll> X;

    // cerr << "L" << endl;
    // rep(i, L.size()){
    //     cerr << L[i].first << " " << L[i].second << endl;
    // }
    // cerr << "R" << endl;
    // rep(i, R.size()){
    //     cerr << R[i].first << " " << R[i].second << endl;
    // }

    ll l_now = 0;
    ll l_dis = INF;
    ll r_now = 0;
    ll r_dis = -INF;
    while(X.size() < n){
        
        // 右端
        for(ll i = l_now; i < L.size(); i++){
            if(mp[L[i].second] == 0){
                l_now = i;
                mp[L[i].second]++;
                

                // 間でなるべく小さいとこ
                ll x = max(L[i].first, r_dis);
                X.push_back(x); l_dis = x;

                // cerr << "PUSH " << L[i].first << endl;
                // X.push_back(L[i].first);
                break;
            }else{

            }
        }

        for(ll i = r_now; i < R.size(); i++){
            if(mp[R[i].second] == 0){
                r_now = i;
                mp[R[i].second]++;
                

                // 間でなるべくでかいとこ
                ll x = min(R[i].first, l_dis);
                X.push_back(x); r_dis = x;

                // cerr << "PUSH " << R[i].first << endl;
                // X.push_back(R[i].first);
                break;
            }else{

            }
        }
    }

    ll ans = 0;
    sort(all(X));
    // vecdbg(X);
    for(ll i = 0; i < n-1; i++){
        ll x = abs(X[i+1] - X[i]);
        ll kaisu = n - 1 - i;
        ans += x * kaisu * (1+i);
    }
    cout << ans << endl;


    /*
    vecdbg(X);
    sort(all(X));
    ll cnt = 0;
    for(ll i = 0; i < X.size() - 1; i++){
        for(ll j = i+1; j < X.size(); j++){
            cnt += abs(X[j] - X[i]);
        }
    }
    cout << cnt << endl;
    */


    







    /*
    vector<ll> x(5);
    x[0] = 0;
    x[1] = 2;
    x[2] = 4;
    x[3] = 6;
    x[4] = 8;
    ll cnt = 0;
    for(ll i = 0; i < 4; i++){
        for(ll j = i+1; j < 5; j++){
            cnt += abs(x[j] - x[i]);
        }
    }
    cout << cnt << endl;
    */


}