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
const long long INF = 9e18;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1

template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << ' ';} cerr << '\n';}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << ' ';} cerr << '\n';}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;
const double PI = acos(-1);

ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0

// (a * b)over flow?   if(a > INF / b){ /* overflow */}
ll n;
ll ans = INF;
void calc(ll now, ll cnt){
    if(get_digit(now) > n){
        return;
    }else if(get_digit(now) == n){
        ans = min(ans, cnt);
        return;
    }

    
    map<ll, ll> mp;
    ll x = now;
    while(x > 0){
        mp[(x % 10)]++;
        x /= 10;
    }

    ll y = get_digit(now);
    if(n - y >= ans - cnt){
        return;
    }

    for(ll i = 9; i >= 2; i--){
        if(mp[i] > 0){
            if(cnt + 1 >= ans) continue;
            if(now > INF / i){
                string s = to_string(now);
                char c = s[0];
                ll fi = c - '0';
                if(fi * i >= 10){
                    ans = min(ans, cnt + 1);
                }else{
                    ans = min(ans, cnt + 2);
                }
            }else{
                calc(now * i, cnt + 1);
            }
        }
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> n;
    ll x; cin >> x;

    // 2, 4, 6, 6, 6, 6, 6
    // 3, 9, 7, 1, 1, 1, 1,
    // 5, 5, 5, 5, 
    // 8, 4, 6, 6, 6, 6

    // 10^n乗以上を作る？

    if(get_digit(x) > n){
        cout << -1 << endl; return 0;
    }
    if(get_digit(x) == n){
        cout << 0 << endl;
    }
    calc(x, 0);

    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

    // string s = "187821878218782187821878218782";
    // __int128 y = parse(s);
    // y *= 2;
    // cout << y << endl;

    // cout << get_digit(y) << endl;







}