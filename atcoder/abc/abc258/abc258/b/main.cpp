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

vector<ll> dy = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<ll> dx = {-1, 0, 1, -1, 1, -1, 0, 1};

ll n;
ll ans = -1;
// void calc(vector<vector<ll>> &vec, ll y, ll x, ll now, ll cnt){
//     ll now = now * 10 + vec[y][x];
//     if(cnt == n){
//         ans = max(ans, now);
//     }else{
//         rep(i, 8){
//             ll nexty = y + dy[i];
//             ll nextx = x + dy[i];

//             if(nexty == -1) nexty = n-1;
//             if(nexty == n) nexty = 0;
//             if(nextx == -1) nextx = n-1;
//             if(nextx == n) nextx = 0;

//             calc(vec, nexty, nextx, )


//         }


//     }

// }

int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> n;
    vector<vector<ll>> vec(n, vector<ll>(n));

    rep(i, n){
        string s; cin >> s;
        rep(j, n){
            ll num = s[j] - '0';
            vec[i][j] = num;
        }
    }

    vecvecdbg(vec);

    rep(i, n){
        rep(j, n){

            ll nowy = i;
            ll nowx = j;

            // ll now = vec[i][j];
            
            rep(k, 8){ //方向を決める
                ll res = 0;
                for(ll l = 0; l < n; l++){
                    res = res * 10 + vec[nowy][nowx];
                    ll nexty = nowy + dy[k];
                    ll nextx = nowx + dx[k];

                    if(nexty == -1) nexty = n-1;
                    if(nexty == n) nexty = 0;
                    if(nextx == -1) nextx = n-1;
                    if(nextx == n) nextx = 0;

                    nowy = nexty;
                    nowx = nextx;
                }

                ans = max(ans, res);
            }

            // calc(vec, i, j, 0, 0);
        }
    }
    cout << ans << endl;

}