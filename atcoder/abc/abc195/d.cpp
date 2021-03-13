#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;

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
    ll n, m, q; cin >> n >> m >> q;
    vector<ll> w(n);
    vector<ll> v(n);
    vector<P> p(n);
    vector<ll> x(m);
    rep(i, n){
        cin >> w[i] >> v[i];
        p[i] = {v[i], w[i]};
    }
    rep(i, m){
        cin >> x[i];
    }

    sort(all(p),greater<P>());

    /*
    rep(i, n){
        cout << p[i].first << " " << p[i].second << endl;
    }
    */

    rep(i, q){
        ll l, r; cin >> l >> r; l--, r--;

        vector<ll> hako;
        for(ll i = 0; i < m; i++){
            if(i < l || r < i){
                hako.push_back(x[i]);
            }
        }

        //vecdbg(hako);
        if(hako.size() == 0){
            cout << 0 << endl; continue;
        }

        sort(all(hako));

        ll ans = 0;

        map<ll, ll> in;
        for(ll i = 0; i < hako.size(); i++){ //箱
            //cout << "hako = " << hako[i] << endl;
            for(ll j = 0; j < n; j++){ //品物
                //すでに使ったか
                if(in[j] > 0) continue;
                //箱に入るか
                if(p[j].second <= hako[i]){
                    //入る
                    in[j] = 1;
                    ans += p[j].first;
                    //cout << "+ " << p[j].first << endl;
                    break;
                }else{
                    //入らない

                }
            }
        }

        cout << ans << endl;


    }

}