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
    ll t; cin >> t;
    rep(T, t){
        ll r, c, h, v; cin >> r >> c >> h >> v;
        vector<vector<char>> vec(r, vector<char>(c));
        ll choco = 0;
        rep(i, r){
            rep(j, c){
                cin >> vec[i][j];
                if(vec[i][j] == '@') choco++;
            }
        }

        if(choco % ((h+1)*(v+1)) != 0){
            cout << "Case #" << T+1 << ": " << "IMPOSSIBLE" << endl;
            continue;
        }

        bool f = true;
        //tate
        ll tate_cut = 0;
        ll tate_need = choco / (v+1);
        ll cnt = 0;

        vector<ll> tate_cutted;
        tate_cutted.push_back(0);
        for(ll j = 0; j < c; j++){
            for(ll i = 0; i < r; i++){
                if(vec[i][j] == '@') cnt++;
            }
            if(cnt == tate_need && tate_cut < v){
                //cerr << "tate_cut " << j << endl;
                tate_cutted.push_back(j+1);
                tate_cut++;
                cnt = 0;
            }
            if(cnt > tate_need){
                f = false;
            }
        }
        
        if(!f){
            cout << "Case #" << T+1 << ": " << "IMPOSSIBLE" << endl;
            continue;
        }

        tate_cutted.push_back(c);
        vector<ll> yoko_cnt;
        yoko_cnt.assign(tate_cutted.size() - 1, 0);
        ll yoko_cut = 0;
        ll yoko_need = choco / ((h+1)*(v+1));

        for(ll i = 0; i < r; i++){
            for(ll j = 0; j < tate_cutted.size() - 1; j++){
                for(ll k = tate_cutted[j]; k < tate_cutted[j+1]; k++){
                    if(vec[i][k] == '@'){
                        yoko_cnt[j]++;
                    }
                }
            }

            bool tmp = true;
            rep(j, yoko_cnt.size()){
                if(yoko_cnt[j] != yoko_need){
                    tmp = false;
                }
                if(yoko_cnt[j] > yoko_need){
                    tmp = false;
                    f = false;
                }
            }

            if(tmp){
                yoko_cut++;
                rep(j, yoko_cnt.size()){
                    yoko_cnt[j] = 0;
                }
            }

            if(!f) break;

        }

        if(f){
            cout << "Case #" << T+1 << ": " << "POSSIBLE" << endl;
        }else{
            cout << "Case #" << T+1 << ": " << "IMPOSSIBLE" << endl;
        }


    }

}