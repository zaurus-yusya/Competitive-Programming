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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m;
    cin >> n >> m;

    vector<long long> vec(n);
    vector<long long> sum(n + 1);
    map<long long, long long> mp;
    rep(i, n){
        cin >> vec[i];
        vec[i] = vec[i] % m;
        sum[i+1] = vec[i] + sum[i];
        sum[i+1] = sum[i+1] % m;
        mp[sum[i+1]]++;
    }

    ll ans = 0;
    ll tmp = 0;
    for(ll i = 1; i <  n/2; i++){
        ll count = 0;
        for(ll j = i; j < n/2; j++){
            if((sum[j] - sum[count]) % m > ans){
                ans = (sum[j] - sum[count]) % m;
            }
            count++;
        }
        tmp += sum[i];
    }

    cout << ans << endl;
    
    

}