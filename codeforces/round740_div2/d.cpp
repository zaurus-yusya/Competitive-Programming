#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 8e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << " ";} br;}}
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
    

    ll n, m; cin >> n >> m; // 2 <= n <= 2*10^5, 10^8 < m < 10^9

    vector<ll> dp(200010);
    vector<ll> sum(200010);
    //ll ruisekiseki = 1;
    dp[1] = 1;
    sum[1+1] = dp[1] + sum[1];// [l, r)

    for(ll i = 2; i <= n; i++){
        //Y
        //dp[i] = (dp[i] + ruisekiseki) % m;
        dp[i] = (dp[i] + sum[i]) % m;
        //if(i == 3) cout << "rui " << ruisekiseki << endl;
        //if(i == 3) cout << dp[i] << endl;
        //Z
        ll tmp = 0;
        ll r = i/2;
        for(ll j = 2; j <= i / 2; j++){
            //if(i == 42) cout << j << " "  << i/j << endl;

            
            
            dp[i] = (dp[i] + dp[i / j]) % m;

            //if(i == 42) cout << i/j << " done " << endl;
            if(j > (i/j)) break;
            

            
            
            if(j != 2){
                dp[i] = (dp[i] + ((dp[j-1] * (r - i/j)) % m) ) % m;
                //if(i == 42) cout << j-1 << " done " << r - i/j << endl;
                r = i/j;
            }
            

            
            if(j == (i/j)){
                //if(i == 100) cout << "koko" << endl;
                break;
            }
            
            // 998244353
            
        }
        dp[i] = (dp[i] + i - ((i/2)+1) + 1) % m;
        //if(i == 3) cout << dp[i] << endl;

        //諸々更新
        sum[i+1] = (sum[i] + dp[i]) % m;
        //ruisekiseki = (ruisekiseki * dp[i]) % m;
    }
    /*
    rep(i, n+1){
        cout << "dp[" << i << "] = " << dp[i] << endl;
    }
    */
    
    cout << dp[n] << endl;
    // 1, 2, 3, 4, 5, 6
    // 1, 0, 0
    //    +1
    //    +1 
    //       2 -> 1 2通り
    //       Y
    //       2 -> 1 y = 1
    //       Z
    //       2 -> 1 z = 2
    //       Y
    //       3 -> 1, 3 -> 2
    //       Z
    //       3 -> 1 z = 2, z = 3
    //       3 -> 2 1通り
    //       3 -> 1 3通り
    //       Y
    //       4 -> 1 1  y = 3
    //       4 -> 2 1  y = 2
    //       4 -> 3 1  y = 1
    //       Z
    //       4 -> 2  z = 2
    //       4 -> 1  z = 3, 4
    //       Y
    //       5 -> 1, 5 -> 2, 5 -> 3, 5 -> 4
    //       Z
    //       5 -> 2 z = 2,
    //       5 -> 1 z = 3, 4, 5
    //       Y
    //       6 -> 1, 6->2, 6->3, 6->4, 6->5
    //       Z
    //       6 -> 3 z = 2
    //       6 -> 2 z = 3
    //       6 -> 1 z = 4, 5, 6
    //       7 -> 3 z = 2
    //       7 -> 2 z = 3
    //       7 -> 1 z = 4, 5, 6, 7
    //      100 -> 50 z = 2
    //      100 -> 33 z = 3
    //      100 -> 25 z = 4
    //      100 -> 20 z = 5
    //      100 -> 
    //nから1にする
}