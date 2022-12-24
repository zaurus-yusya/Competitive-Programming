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
    vector<vector<char>> vec(9, vector<char>(9));
    rep(i, 9){
        rep(j, 9){
            cin >> vec[i][j];
        }
    }

    ll ans = 0;
    map<pair<pair<ll, ll>, pair<ll, ll>>, ll> memo;
    for(ll i = 0; i < 9; i++){ // y
        for(ll j = 0; j < 9; j++){ // x

            for(ll k = 0; k < 9; k++){ // y
                for(ll l = 0; l < 9; l++){ // x
                    if(memo.count({{i, j}, {k, l}}) > 0) continue;
                    if(memo.count({{k, l}, {i, j}}) > 0) continue;
                    
                    ll ydis = k - i;
                    ll xdis = l - j;

                    ll yy = k - xdis;
                    ll xx = l + ydis;

                    ll yyy = i - xdis;
                    ll xxx = j + ydis;

                    if(yy < 0 || yy >= 9) continue;
                    if(xx < 0 || xx >= 9) continue;
                    if(yyy < 0 || yyy >= 9) continue;
                    if(xxx < 0 || xxx >= 9) continue;

                    map<pair<ll, ll>, ll> mp;
                    mp[{i, j}]++;
                    mp[{k, l}]++;
                    mp[{yy, xx}]++;
                    mp[{yyy, xxx}]++;
                    if(mp.size() != 4) continue;

                    if(vec[i][j] == '#' && vec[k][l] == '#' && vec[yy][xx] == '#' && vec[yyy][xxx] == '#'){
                        // cerr << "(" << i << " " << j << ")" << endl;
                        // cerr << "(" << k << " " << l << ")" << endl;
                        // cerr << "(" << yy << " " << xx << ")" << endl;
                        // cerr << "(" << yyy << " " << xxx << ")" << endl;
                        // cerr << "---" << endl;
                        memo[{{yy, xx}, {yyy, xxx}}]++;
                        ans++;
                    }


                }
            }
        }
    } 

    cout << ans/2 << endl;

}