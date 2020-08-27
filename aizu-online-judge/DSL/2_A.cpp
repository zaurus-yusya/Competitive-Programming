#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = pow(2, 31) - 1;
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
// global vector -> 0 initialization

//segment tree
//init O(N)  update query O(logN)
ll n;
ll dat[1<<18];

void init(ll n_){
    n = 1;
    while(n < n_) n *= 2;
    for(ll i = 0; i < 2*n - 1; i++) dat[i] = INF;
}
// RMQ min [a, b)
// index k value to a
void update(ll k, ll a){
    k += n - 1;
    dat[k] = a;
    while(k > 0){
        k = (k-1) / 2;
        dat[k] = min(dat[k*2 + 1], dat[k*2 + 2]);
    }
}
ll query(ll a, ll b, ll k=0, ll l=0, ll r=n){
    if(r <= a || b <= l) return INF;

    if(a <= l && r <= b) return dat[k];
    else{
        ll vl = query(a, b, k*2 + 1, l, (l+r) / 2);
        ll vr = query(a, b, k*2 + 2, (l+r) / 2, r);
        return min(vl, vr);
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> n;
    ll q; cin >> q;

    init(n);

    rep(i, q){
        ll t; cin >> t;
        ll x, y; cin >> x >> y;
        if(t == 0){
            update(x, y);
        }
        if(t == 1){
            cout << query(x, y+1, 0, 0, n) << endl;
        }
    }
    
}