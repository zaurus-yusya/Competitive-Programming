#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;}
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, q; cin >> n >> q;
    vector<long long> a(n);
    vector<ll> sum(n+1);
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
        sum[i+1] = sum[i] + a[i];
    }
    vector<long long> x(q);
    for(long long i = 0; i < q; i ++){
        cin >> x[i];
    }

    rep(i, q){
        ll ans = 0, l = 0;
        for(ll j = 1; j <= n; j++){
            while(true){
                if(sum[j] - sum[l] > x[i]){
                    l++;
                }else{
                    ans += j - l;
                    break;
                }
                if(l == j){
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    

}