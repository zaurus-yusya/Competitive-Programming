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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<long long> vec(n);
    ll flag = 0;
    map<ll, ll> tmp;
    for(long long i = 0; i < n; i ++){
        cin >> vec[i];
        if(vec[i] == 1){
            flag++;
        }
        tmp[vec[i]]++;
    }

    if(flag == 1){
        cout << 1 << endl;
        return 0;
    }
    if(flag > 2){
        cout << 0 << endl;
        return 0;
    }

    sort(all(vec));
    ll ans = 0;


    map<ll, ll> mp;
    rep(i, n){
        if(mp.count(vec[i]) == 0){
            if(tmp[vec[i]] == 1){
                mp[vec[i]]++;
                ans++;
            }
            for(ll j = vec[i]; j <= 1000000 ; j += vec[i]){
                mp[j]++;
            }
        }
    }
    cout << ans << endl;


    /*
    vector<ll> res;
    ll roop = 0;
    for(ll i = 0; i < n; i++){
        bool flag = true;
        for(ll j = 0; j < res.size(); j++){
            if(vec[i]%vec[j] == 0){
                flag = false;
            }
            roop++; 
        }
        if(flag){
            ans++;
            res.push_back(vec[i]);
        }
    }

    cout << ans << endl;
    cout << roop << endl;
    */

    


}