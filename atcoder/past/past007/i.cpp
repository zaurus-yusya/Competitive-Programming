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
vector<vector<T>> mat_mul(vector<vector<T>> a, vector<vector<T>> b){
    ll I = a.size(), J = b[0].size(), K = b.size();
    vector<vector<T>> res(I, vector<T>(J));

    rep(i, I){
        rep(j, J){
            T tmp = 0;
            rep(k, K){
                tmp += a[i][k] * b[k][j];
            }
            res[i][j] = tmp;
        }
    }

    return res;
}

//二次元平面での回転行列
template <typename T>
pair<T, T> mat_rot(T rad, T y, T x){ //回転角(rad), y座標, x座標
    vector<vector<T>> rot = {
        {cos(rad), -sin(rad), (T)0},
        {sin(rad), cos(rad), (T)0},
        {(T)0, (T)0, (T)1}
    };
    vector<vector<T>> posi = {
        {x},
        {y},
        {(T)1}
    };
    vector<vector<T>> res = mat_mul(rot, posi);
    return {res[1][0], res[0][0]}; //pair({y座標, x座標})
}

template <typename T>
vector<vector<T>> mat_pow(vector<vector<T>> a, ll n){
    vector<vector<T>> res(a.size(), vector<T>(a[0].size()));
    rep(i, a.size()) res[i][i] = 1;

    while(n > 0){
        if(n & 1 == 1){
            res = mat_mul(a, res);
        }
        a = mat_mul(a, a);
        n >>= 1;
    }

    return res;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    ld x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    vector<pair<ld, ld>> vec(n);
    rep(i, n){
        cin >> vec[i].first >> vec[i].second;
    }

    ld midx = (x1 + x2) / (ld)2;
    ld midy = (y1 + y2) / (ld)2;

    ld X2 = x2 - midx, Y2 = y2 - midy;
    
    ld kaku = atan2(Y2, X2);

    vector<vector<ld>> rot = {
        {cos(-kaku), -sin(-kaku), (ld)0},
        {sin(-kaku), cos(-kaku), (ld)0},
        {(ld)0, (ld)0, (ld)1}
    };

    rep(i, n){
        //mid引く
        ld tmpx = vec[i].first - midx;
        ld tmpy = vec[i].second - midy;
        /*
        //回転させる
        vector<vector<ld>> zahyo = {
            {tmpx},
            {tmpy},
            {(ld)1}
        };
        vector<vector<ld>> res = mat_mul(rot, zahyo);
        //mid足す
        ld resx = res[0][0];
        ld resy = res[1][0];
        */

        pair<ld, ld> p = mat_rot(-kaku, tmpy, tmpx);
        cout << p.second << " " << p.first << endl;
        //出力する
        //cout << resx << " " << resy << endl;
    }

}