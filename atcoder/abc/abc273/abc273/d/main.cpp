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
    ll h, w; cin >> h >> w;
    ll rs, cs; cin >> rs >> cs;
    ll n; cin >> n;

    map<ll, vector<ll>> tate;
    map<ll, vector<ll>> yoko;

    rep(i, n){
        ll r, c; cin >> r >> c;
        tate[c].push_back(r);
        yoko[r].push_back(c);
    }

    // sort
    for(auto&i: tate){
        // 端追加
        tate[i.first].push_back(0);
        tate[i.first].push_back(h+1);

        sort(all(tate[i.first]));
    }
    for(auto&i: yoko){
        // 端追加
        yoko[i.first].push_back(0);
        yoko[i.first].push_back(w+1);

        sort(all(yoko[i.first]));
    }


    ll q; cin >> q;
    // rs, cs
    rep(i, q){
        char c; cin >> c;
        ll move_; cin >> move_;

        if(c == 'L'){
            if(yoko.count(rs) > 0){
                ll dis = upper_bound(yoko[rs].begin(), yoko[rs].end(), cs) - yoko[rs].begin();
                ll kabe = yoko[rs][dis - 1];

                cs = max(kabe + 1, cs - move_);
            }else{
                cs = max(1LL, cs - move_);
            }
        }else if(c == 'R'){
            if(yoko.count(rs) > 0){
                ll dis = upper_bound(yoko[rs].begin(), yoko[rs].end(), cs) - yoko[rs].begin();
                ll kabe = yoko[rs][dis];

                cs = min(kabe - 1, cs + move_);
            }else{
                cs = min(w, cs + move_);
            }
        }else if(c == 'U'){
            if(tate.count(cs) > 0){
                ll dis = upper_bound(tate[cs].begin(), tate[cs].end(), rs) - tate[cs].begin();
                ll kabe = tate[cs][dis - 1];

                rs = max(kabe + 1, rs - move_);
            }else{
                rs = max(1LL, rs - move_);
            }
        }else if(c == 'D'){
            if(tate.count(cs) > 0){
                ll dis = upper_bound(tate[cs].begin(), tate[cs].end(), rs) - tate[cs].begin();
                ll kabe = tate[cs][dis];

                rs = min(kabe - 1, rs + move_);
            }else{
                rs = min(h, rs + move_);
            }
        }

        cout << rs << " " << cs << '\n';

    }




}