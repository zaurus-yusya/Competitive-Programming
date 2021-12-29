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
const long long MOD = 1e9+7;
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
    ll p, q; cin >> p >> q;
    vector<vector<char>> vec(p, vector<char>(q));
    rep(i, p){
        rep(j, q){
            cin >> vec[i][j];
        }
    }

    vector<P> osu(p);
    vector<P> mesu(q);
    rep(i, p){
        ll a, b; cin >> a >> b; osu[i] = {a, b};
    }
    rep(i, q){
        ll c, d; cin >> c >> d; mesu[i] = {c, d};
    }

    //クイーン問題 8!通り
    // 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1


    //マスの数　100*100 = 10000
    //つがいにできる数は最大でも100個

    

    return 0;

    

    // 100 * 100 * 4
    // 下に進む時 オスiの値加算
    // 右に進む時 メスjの値加算

    vector<vector<ll>> dp0(p, vector<ll>(q, 0)); // オスok, メスok
    vector<vector<ll>> dp1(p, vector<ll>(q, 0)); // オスok, メスng
    vector<vector<ll>> dp2(p, vector<ll>(q, 0)); // オスng, メスok
    vector<vector<ll>> dp3(p, vector<ll>(q, 0)); // オスng, メスng

    //だめかも
    rep(i, p){
        rep(j, q){
            ll num = vec[i][j] - '0';
            if(i == p-1){
                //右移動　つがいにする
                if(num == 1){
                    
                }

                //右移動　つがいにしない
                

                continue;
            }
            if(j == q-1){
                //下移動 つがいにする
                if(num == 1){
                    
                }

                //下移動　つがいにしない

                continue;
            }

            rep(k, 4){
                //下移動　つがいにする
                if(num == 1){
                    dp3[i+1][j] = max(dp2[i+1][j], dp0[i][j])
                }
                
                //下移動　つがいにしない

                //右移動　つがいにする
                if(num == 1){
                    
                }

                //右移動　つがいにしない

            }

        }
    }


}