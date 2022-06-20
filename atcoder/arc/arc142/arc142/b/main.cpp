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
vector<ll> dy = {0, 1, 0, -1};
vector<ll> dx = {1, 0, -1, 0};

vector<ll> dyy = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<ll> dxx = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<vector<ll>> vec(n, vector<ll>(n));


    ll dir = 0;
    ll now_y = 0, now_x = 0;
    ll cnt = 0;
    ll hikui = 1;
    ll takai = n*n;
    for(ll i = 1; i <= n*n; i++){
        // cerr << "i = " << i << endl;
        if(cnt % 2 == 0){
            vec[now_y][now_x] = hikui;
            hikui++;
        }else{
            vec[now_y][now_x] = takai;
            takai--;
        }
        // vec[now_y][now_x] = i;

        //進める
        ll next_y = now_y + dy[dir];
        ll next_x = now_x + dx[dir];
        // cerr << "next_y = " << next_y << " next_x = " << next_x << endl;

        bool f = false;
        if(next_y < 0 || next_y >= n || next_x < 0 || next_x >= n){
            //壁なら向き替える
            f = true;
        }else if(vec[next_y][next_x] != 0){
            //既に設置済みなら向き替える
            f = true;
        }

        if(f){
            dir++;
            if(dir == 4){
                dir = 0;
                cnt++;
                now_y = cnt, now_x = cnt;
            }else{
                next_y = now_y + dy[dir];
                next_x = now_x + dx[dir];
                now_y = next_y;
                now_x = next_x;
            }
        }else{
            now_y = next_y;
            now_x = next_x;
        }

    }

    rep(i, n){
        rep(j, n){
            if(j == n-1){
                cout << vec[i][j];
            }else{
                cout << vec[i][j] << " ";
            }
            // vec[i][j] = 1;
        }br;
    }

    ////
    /*
    map<ll, ll> xxx;
    rep(i, n){
        rep(j, n){
            xxx[vec[i][j]]++;
            for(ll k = 0; k < 8; k++){
                ll ny = i + dyy[k];
                ll nx = j + dxx[k];

                if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

                ll a = 0, b = 0;
                if(vec[i][j] > vec[ny][nx]){
                    a++;
                }else{
                    b++;
                }
                
                if(a == b){
                    cerr << "hit " << i << " " << j << " " << vec[i][j] << endl;
                }
            }

        }
    }
    if(xxx.size() != n*n){
        cerr << "size " << endl;
    }
    */



    return 0;

}