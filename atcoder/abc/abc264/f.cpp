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
    vector<long long> r(h);
    for(long long i = 0; i < h; i ++){
        cin >> r[i];
    }
    vector<long long> c(w);
    for(long long i = 0; i < w; i ++){
        cin >> c[i];
    }
    vector<vector<char>> vec(h, vector<char>(w));
    vector<vector<char>> vec_r(h, vector<char>(w));
    rep(i, h){
        rep(j, w){
            cin >> vec[i][j];
            if(vec[i][j] == '0'){
                vec_r[i][j] = '1';
            }else{
                vec_r[i][j] = '0';
            }
        }
    }

    ll ans = INF;
    // 0で行きたい
    vector<vector<ll>> dp_n_uekara(2010, vector<ll>(2010, INF));
    vector<vector<ll>> dp_n_hidarikara(2010, vector<ll>(2010, INF));
    vector<vector<ll>> dp_r_uekara(2010, vector<ll>(2010, INF));
    vector<vector<ll>> dp_r_hidarikara(2010, vector<ll>(2010, INF));

    if(vec[0][0] == '0'){
        dp_n_uekara[0][0] = 0;
        dp_n_hidarikara[0][0] = 0;
        dp_r_uekara[0][0] = r[0];
        dp_r_hidarikara[0][0] = c[0];
    }else{
        dp_n_uekara[0][0] = r[0];
        dp_n_hidarikara[0][0] = c[0];
        dp_r_uekara[0][0] = 0;
        dp_r_hidarikara[0][0] = 0;
    }
    
    for(ll i = 0; i < h; i++){
        for(ll j = 0; j < w; j++){
            // dp_u[i][j]とdp_r[i][j]の更新
            // 下に移動
            if(i != h-1){
                if(vec[i+1][j] == '1'){
                    dp_r_uekara[i+1][j] = min(dp_r_uekara[i+1][j], dp_n_hidarikara[i][j] + r[i+1]);
                    dp_r_uekara[i+1][j] = min(dp_r_uekara[i+1][j], dp_r_hidarikara[i][j]);
                    
                }else{
                    dp_n_uekara[i+1][j] = min(dp_n_uekara[i+1][j], dp_n_uekara[i][j]);
                    dp_r_uekara[i+1][j] = min(dp_r_uekara[i+1][j], dp_r_uekara[i][j]);
                }
            }

            // 右に移動
            if(j != w-1){
                if(vec[i][j+1] == '1'){
                    dp_r_hidarikara[i][j+1] = min(dp_r_hidarikara[i][j+1], dp_n_uekara[i][j] + c[j+1]);
                    dp_r_hidarikara[i][j+1] = min(dp_r_hidarikara[i][j+1], dp_r_uekara[i][j]);

                }else{
                    dp_n_hidarikara[i][j+1] = min(dp_n_hidarikara[i][j+1], dp_n_hidarikara[i][j]);
                    dp_r_hidarikara[i][j+1] = min(dp_r_hidarikara[i][j+1], dp_r_hidarikara[i][j]);
                    
                }
            }
        }
    }

    cout << dp_n_uekara[h][w] << endl;
    cout << dp_n_hidarikara[h][w] << endl;
    cout << dp_r_uekara[h][w] << endl;
    cout << dp_r_hidarikara[h][w] << endl;

    cerr << "---" << endl;
    cout << dp_n_uekara[0][0] << endl;
    cout << dp_n_hidarikara[0][0] << endl;
    cout << dp_r_uekara[0][0] << endl;
    cout << dp_r_hidarikara[0][0] << endl;
    cerr << "---" << endl;
    cout << dp_n_uekara[0][1] << endl;
    cout << dp_n_hidarikara[0][1] << endl;
    cout << dp_r_uekara[0][1] << endl;
    cout << dp_r_hidarikara[0][1] << endl;

}