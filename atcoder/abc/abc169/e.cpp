#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
typedef pair<int,int> pint;
bool cmp(pint a, pint b) { return a.second < b.second; }

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<ll> A(n);
    vector<ll> B(n);

    vector<pair<ll,ll>> vec(n);

    vector<ll> test;

    rep(i, n){
        ll x, y; cin >> x >> y;
        vec[i] = make_pair(x, y);
        test.push_back(x);
        test.push_back(y);
    }

    sort(vec.begin(), vec.end(), cmp);
    sort(all(test));

    ll ans = 0;
    if(n % 2 == 0){
        ans += test[1] - test[0];
        ans += test[test.size() - 1] - test[test.size() - 2];

        cout << ((test[test.size() - 2] - test[1]) * 2) + 1 + ans << endl;
    }

    if(n % 2 == 1){
        cout << test[test.size() - 2] - test[1] + 1 << endl;
    }


}