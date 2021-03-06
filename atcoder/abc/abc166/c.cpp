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
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp




int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n,m;
    cin >> n >> m;
    vector<long long> vec(n);
    for(long long i = 0; i < n; i ++){
        cin >> vec[i];
    }

    vector<ll> ans(n);
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        if(vec[a] > vec[b]){
            ans[b] = 1;
        }else if(vec[a] == vec[b]){
            ans[a] = 1;
            ans[b] = 1;
        }else{
            ans[a] = 1;
        }
    }
    ll count = 0;
    rep(i,n){
        if(ans[i] == 0){
            count++;
        }
    }
    cout << count << endl;

}