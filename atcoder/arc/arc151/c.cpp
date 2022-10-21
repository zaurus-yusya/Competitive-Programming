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
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> p;

    rep(i, m){
        ll x, y; cin >> x >> y;
        p.push_back({x, y});
    }

    sort(all(p));

    // 壁と隣接 偶数, 奇数
    // 0 0 か 1 1の間 偶数, 奇数
    // 0 1 か 1 0の間 偶数, 奇数

    // ない場合 奇数, 偶数
    if(m == 0){
        if(n % 2 == 0){
            cout << "Aoki" << endl;
        }else{
            cout << "Takahashi" << endl;
        }
        return 0;
    }

    ll score = 0;

    vector<ll> kabe;
    if(p[0].first != 1){
        kabe.push_back(p[0].first - 1);
    }
    if(p[m-1].first != n){
        kabe.push_back(n - p[m-1].first);
    }

    vector<ll> sam;
    vector<ll> dif;

    for(ll i = 0; i < m-1; i++){
        if(p[i].second == p[i+1].second){
            // sam
            if(p[i+1].first - p[i].first >= 2){
                sam.push_back(p[i+1].first - p[i].first - 1);
            }
        }else{
            // dif
            if(p[i+1].first - p[i].first >= 2){
                dif.push_back(p[i+1].first - p[i].first - 1);
            }
        }
    }

    // cerr << "kabe" << endl;
    // vecdbg(kabe);
    // cerr << "sam" << endl;
    // vecdbg(sam);
    // cerr << "dif" << endl;
    // vecdbg(dif);


    rep(i, kabe.size()){
        if(kabe[i] % 2 == 1){
            score += 1;
        }else{
            score += 0;
        }
    }

    rep(i, sam.size()){
        if(sam[i] % 2 == 0){
            score += 1;
        }else{
            score += 0;
        }
    }

    rep(i, dif.size()){
        if(dif[i] % 2 == 1){
            score += 1;
        }else{
            score += 0;
        }
    }



    if(score % 2 == 1){
        cout << "Takahashi" << endl;
    }else{
        cout << "Aoki" << endl;
    }

}