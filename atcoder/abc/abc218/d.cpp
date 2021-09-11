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

template <typename T>
vector<T> compress(vector<T> &X) {
    // ソートした結果を vals に
    vector<T> vals = X;
    sort(vals.begin(), vals.end());
    // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    // 各要素ごとに二分探索で位置を求める
    for (int i = 0; i < (int)X.size(); i++) {
        X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
    }
    return vals;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;

    vector<P> vec;
    vector<ll> x;
    vector<ll> y;
    rep(i, n){
        ll X, Y; cin >> X >> Y;
        vec.push_back({X, Y});
        x.push_back(X);
        y.push_back(Y);
    }

    map<P, ll> mp;
    for(ll i = 0; i < x.size(); i++){
        for(ll j = 0; j< x.size(); j++){
            if(i == j) continue;
            if(x[i] == x[j]){
                mp[{y[i], y[j]}]++;
            }
        }
    }
    ll ans = 0;
    for(auto i : mp){
        ans += (i.second) * (i.second-1) / 2;
    }
    cout << ans / 2 << endl;

    return 0;

    /*
    vector<ll> x_vals = compress(x);
    vector<ll> y_vals = compress(y);

    rep(i, x_vals.size()){
        cout << x_vals[i] << " ";
    }br;
    rep(i, y_vals.size()){
        cout << y_vals[i] << " ";
    }br;

    rep(i, x.size()){
        cout << x[i] << " ";
    }br;
    rep(i, y.size()){
        cout << y[i] << " ";
    }br;

    for(ll i = 0; i < x.size(); i++){
        for(ll j = i+1; j< x.size(); j++){

        }
    }

    

    vector<vector<ll>> x_num(2010);
    vector<vector<ll>> y_num(2010);

    rep(i, x.size()){
        x_num[x[i]].push_back(i);
    }
    rep(i, y.size()){
        y_num[y[i]].push_back(i);
    }

    ll ans = 0;

    for(ll i = 0; i < x_num.size(); i++){
        for(ll j = i+1; j < x_num.size(); j++){

            for(ll I = )


        }
    }

    rep(i, x_num.size()){
        if(i > 10) break;
        for(ll j = 0; j < x_num[i].size(); j++){
            for(ll k = j+1; k < x_num[i].size(); k++){

                ll l_val = x_vals[x[x_num[i][j]]];
                ll r_val = x_vals[x[x_num[i][k]]];
                //cout << x_num[i][j] << " " << x_num[i][k] << endl;
                cout << "x = " << l_val << " " << r_val << endl;

                ll yl_val = y_vals[y[x_num[i][j]]];
                ll yr_val = y_vals[y[x_num[i][k]]];
                cout << "y = " << yl_val << " " << yr_val << endl;

            }
        }
    }
    */



}