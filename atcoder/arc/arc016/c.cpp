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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;

    vector<ll> kuji_cost(m);
    vector<vector<pair<ll, ll>>> kuji_nakami(m);

    vector<vector<ll>> idol_included(n);

    rep(i, m){ // kuji i
        ll c, cost; cin >> c >> cost;
        kuji_cost[i] = cost;

        rep(j, c){ // kuji_nakami
            ll x, y; cin >> x >> y; x--;
            kuji_nakami[i].push_back({x, y}); // x: アイドル, y: 確率
            idol_included[x].push_back(i);
        }
    }

    rep(i, n){
        cout << "i = " << i << " ";
        rep(j, idol_included[i].size()){
            cout << idol_included[i][j] << " ";
        }br;
    }

    
    // //hinagata 引数は適宜追加する
    // //https://atcoder.jp/contests/past201912-open/submissions/18980789
    vector<ld> dp(1050, 0);
    
    for(ll i = (1<<n) - 1; i >= 0; i--){ // 1024
        // 1111111111 のときはcontinue
        if(i == (1<<n) - 1) continue;
        
        // アイドル j を当てる場合
        for(ll j = 0; j < n; j++){
            // すでにそのアイドルを当てていたらcontinue
            if((i & (1<<j)) != 0) continue;

            // くじをひく。最も加算される期待値が少なくなるものを採用
            ld tmp = INF;
            for(ll k = 0; k < idol_included[j].size(); k++){
                ll kuji = idol_included[j][k];
                ll cost = kuji_cost[kuji];

                
                for(ll ind = 0; ind < kuji_nakami[kuji].size(); ind++){
                    if((i | (1 << kuji_nakami[kuji][ind].first)) == i){
                        // 既に持ってる
                    }else{
                        // 持ってない
                    }
                }
            }
        }

    }
    
        
}

    /*
    // それぞれのアイドルを引きたい時に最も確率が高いものを調べる
    vector<vector<ll>> hiku_kuji(n);
    for(ll i = 0; i < n; i++){
        // アイドル i を引くのに最適なもの
        vector<ll> tmp;
        ll now = 0;
        rep(j, m){ // kuji j
            rep(k, idol[j].size()){
                if(idol[j][k].first == i){
                    if(now < idol[j][k].second){
                        now = idol[j][k].second;
                        tmp.clear();
                        tmp.push_back(j);
                    }else if(now == idol[j][k].second){
                        now = idol[j][k].second;
                        tmp.push_back(j);
                    }
                }
            }
        }
        hiku_kuji[i] = tmp;
    }

    //くじデバッグ
    rep(i, n){
        cout << "i = " << i << " :";
        rep(j, hiku_kuji[i].size()){
            cout << hiku_kuji[i][j] << " ";
        }br;
    }
    */