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

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

ll tmp = 1000000000000001;

vector<ll> vec;
vector<ll> vec2;

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;

    vector<char> res;
    while(n != 0){
        n--;
        res.push_back((char)('a' + (n % 26)));
        n /= 26;
    }

    rep(i, res.size()){
        cout << res[res.size() - 1 - i];
    }
    br;




}