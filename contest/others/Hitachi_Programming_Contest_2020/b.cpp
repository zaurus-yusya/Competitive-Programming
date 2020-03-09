#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << endl;
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    ll a, b, m;
    cin >> a >> b >> m;

    vector<long long> vec_a(a);
    ll a_min = INF;
    rep(i, a){
        cin >> vec_a[i];
        a_min = min(a_min, vec_a[i]);
    } 
    vector<long long> vec_b(b);
    ll b_min = INF;
    rep(i, b){
        cin >> vec_b[i];
        b_min = min(b_min, vec_b[i]);
    } 

    ll ans = a_min + b_min;

    vector<ll> x(m);
    vector<ll> y(m);
    vector<ll> c(m);
    rep(i,m){
        cin >> x[i] >> y[i] >> c[i];
        ans = min(ans, vec_a[x[i]-1] + vec_b[y[i]-1] - c[i]);
    }

    cout << ans << endl;
}