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
    ll H, W, n, h, w; cin >> H >> W >> n >> h >> w;
    vector<vector<ll>> vec(H, vector<ll>(W));

    map<ll, ll> mp;
    rep(i, H){
        rep(j, W){
            cin >> vec[i][j];
            mp[vec[i][j]]++;
        }
    }

    // 横幅 w
    // 縦幅 h
    for(ll k = 0; k <= H - h; k++){
        map<ll, ll> tmp;
        tmp = mp;
        for(ll l = 0; l <= W - w; l++){
            // cerr << "l = " << l << " " << k << " " << k + h << endl;
            // l=0の時に計算しなおす
            if(l == 0){
                for(ll i = k; i < k + h; i++){
                    for(ll j = 0; j < w; j++){
                        tmp[vec[i][j]]--;
                        if(tmp[vec[i][j]] == 0){
                            tmp.erase(vec[i][j]);
                        }
                    }
                }
            }else{
                // 差分計算
                // 増やす
                
                for(ll i = k; i < k + h; i++){
                    // cerr << "huyasu " << i << " " << l << " " << vec[i][l- 1] << endl;
                    tmp[vec[i][l- 1]]++;
                }

                // 減らす
                for(ll i = k; i < k + h; i++){
                    tmp[vec[i][l + w - 1]]--;
                    if(tmp[vec[i][l + w - 1]] == 0){
                            tmp.erase(vec[i][l + w - 1]);
                        }
                }
            }

            cout << tmp.size() << " ";
        }br;

        // break;
    }



}