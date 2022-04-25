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
        ll n, p; cin >> n >> p;

        vector<map<ll, ll>> dp(n+10);
        vector<vector<ll>> x(n, vector<ll>(p));

        rep(i, n){
            rep(j, p){
                cin >> x[i][j];
            }
            sort(all(x[i]));
        }

        dp[0][0] = 0;

        for(ll i = 0; i < n; i++){
            // cerr << "i = " << i << endl;
            for(ll k = 0; k < p; k++){
                ll end = x[i][k];
                dp[i+1][end] = INF;
            }
            for(auto& j : dp[i]){
                ll start = j.first;
                ll mi = x[i][0];
                ll ma = x[i][p-1];

                

                for(ll k = 0; k < p; k++){
                    ll end = x[i][k];
                    ll dis = abs(start - mi) + abs(ma - mi) + abs(ma - end);
                    ll dis2 = abs(start - ma) + abs(ma - mi) + abs(mi - end);
                    ll bef = dp[i+1][end];
                    ll aft = dp[i][start] + min(dis, dis2);
                    dp[i+1][end] = min(bef, aft);
                    //cerr << "start = " << start << " end = " << end << " " << dp[i][start] << " " << min(dis, dis2) << endl;
                }
                //cerr << j.first << " " << j.second << endl;
            }

            //cerr << "result" << endl;
            /*
            for(auto&i: dp[i+1]){
                cout << i.first << " " << i.second << endl;
            }
            */
        }

        // cerr << "--" << endl;
        ll ans = INF;
        for(auto&i: dp[n]){
            // cerr << i.first << " " << i.second << endl;
            ans = min(ans, i.second);
        }
        // cerr << "--" << endl;

        cout << "Case #" << T+1 << ": " << ans << '\n';

    }

}