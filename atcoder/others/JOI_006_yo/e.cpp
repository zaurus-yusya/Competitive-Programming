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
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll a, b, c; cin >> a >> b >> c;
    ll n; cin >> n;
    vector<ll> res(a+b+c, -1);
    vector<tuple<ll, ll, ll>> vec; 
    rep(i, n){
        ll x, y, z, w;
        cin >> x >> y >> z >> w; x--; y--; z--;
        if(w == 1){
            res[x] = 1; res[y] = 1; res[z] = 1;
        }else{
            vec.emplace_back(x, y, z);
        }
    }

    rep(j, vec.size()){
        rep(i, vec.size()){
            map<ll, ll> mp;
            ll x = get<0>(vec[i]);
            ll y = get<1>(vec[i]);
            ll z = get<2>(vec[i]);
            if(res[x] == 1 && res[y] == 1 && res[z] != 1) res[z] = 0;
            if(res[y] == 1 && res[z] == 1 && res[x] != 1) res[x] = 0;
            if(res[z] == 1 && res[x] == 1 && res[y] != 1) res[y] = 0;
        }
    }

    rep(i, a+b+c){
        if(res[i] == -1){
            cout << 2 << endl;
        }else{
            cout << res[i] << endl;
        }
    }

}