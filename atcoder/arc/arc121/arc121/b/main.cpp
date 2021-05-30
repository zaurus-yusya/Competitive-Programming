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
const long long INF = 1e18;
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

void calc(const vector<ll> &x, const vector<ll> &y, const vector<ll> &z)
{
    ll ans = INF;

    //奇数1 * 奇数2
    for(ll i = 0; i < x.size(); i++){
        ll dis = lower_bound(y.begin(), y.end(), x[i]) - y.begin();
        ll tmp;
        if(dis == 0){
            tmp = abs(x[i] - y[0]);
        }else if(dis == y.size()){
            tmp = abs(x[i] - y[y.size() - 1]);
        }else{
            tmp = min( abs(x[i] - y[dis]), abs(x[i] - y[dis - 1]));
        }
        ans = min(ans, tmp);
    }

    //奇数1 * 偶数, 奇数2 * 偶数
    if(z.size() != 0){
        ll xxx = INF;
        for(ll i = 0; i < x.size(); i++){
            ll dis = lower_bound(z.begin(), z.end(), x[i]) - z.begin();
            ll tmp;
            if(dis == 0){
                tmp = abs(x[i] - z[0]);
            }else if(dis == z.size()){
                tmp = abs(x[i] - z[z.size() - 1]);
            }else{
                tmp = min( abs(x[i] - z[dis]), abs(x[i] - z[dis - 1]));
            }
            xxx = min(xxx, tmp);
        }
        
        ll yyy = INF;
        for(ll i = 0; i < y.size(); i++){
            ll dis = lower_bound(z.begin(), z.end(), y[i]) - z.begin();
            ll tmp;
            if(dis == 0){
                tmp = abs(y[i] - z[0]);
            }else if(dis == z.size()){
                tmp = abs(y[i] - z[z.size() - 1]);
            }else{
                tmp = min( abs(y[i] - z[dis]), abs(y[i] - z[dis - 1]));
            }
            yyy = min(yyy, tmp);
        }
        ans = min(ans, xxx+yyy);
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<ll> r;
    vector<ll> g;
    vector<ll> b;
    rep(i, 2*n){
        ll a; char c; cin >> a >> c;
        if(c == 'R') r.push_back(a);
        if(c == 'G') g.push_back(a);
        if(c == 'B') b.push_back(a);
    }
    sort(all(r)); sort(all(g)); sort(all(b));

    if(r.size() % 2 == 0 && g.size() % 2 == 0 && b.size() % 2 == 0){
        cout << 0 << endl; return 0;
    }

    
    if(r.size() % 2 == 1 && g.size() % 2 == 1){
        calc(r, g, b);
    }
    if(r.size() % 2 == 1 && b.size() % 2 == 1){
        calc(r, b, g);
    }
    if(g.size() % 2 == 1 && b.size() % 2 == 1){
        calc(g, b, r);
    }

}