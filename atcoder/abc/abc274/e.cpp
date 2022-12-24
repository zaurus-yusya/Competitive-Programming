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
    vector<ld> x(n+1 + m);
    vector<ld> y(n+1 + m);
    for(ll i = 1; i <= n + m; i++){
        cin >> x[i] >> y[i];
    }

    vector<vector<ld>> dp((1<< (n+1 + m)), vector<ld>( n+1 + m, INF));
    dp[0][0] = 0;
    
    for(ll i = 0; i < (1<< (n+1+m)); i++){
        
        // 速度
        ll cnt = 0;
        for(ll j = 0; j < m; j++){
            if( (i >> (n+1 + j)) & 1){
                cnt++;
            }
        }

        // j: 今の街
        for(ll j = 0; j < n+1+m; j++){
            // k: 次の街
            for(ll k = 0; k < n+1+m; k++){
                if(i != 0 && !(i & (1 << j))) continue;
                if((i & (1 << k)) == 0){
                    ld dis = sqrt( abs(x[j] - x[k]) * abs(x[j] - x[k]) + abs(y[j] - y[k]) * abs(y[j] - y[k]) ) / (ld)POW(2, cnt);
                    dp[i | (1<<k)][k] = min( dp[i | (1<<k)][k], dp[i][j] + dis);
                }
            }
        }
    }

    ld ans = INF;

    ll tmp = (1<< (n+1)) - 1;
    for(ll i = 0; i < (1 << m); i++){
        ans = min(ans, dp[(i << (n+1)) + tmp][0]);
    }
    cout << ans << endl;

}