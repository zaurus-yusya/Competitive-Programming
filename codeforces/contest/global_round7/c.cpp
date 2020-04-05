#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const int INF = 1e9;
const int MOD = 998244353;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, k;
    cin >> n >> k;

    vector<long long> vec(n);
    vector<long long> tmp(n);
    rep(i, n){
        cin >> vec[i];
        if(vec[i] >= n - k + 1){
            tmp[i] = 1;
        }
    }

    if(k == 1){
        cout << n << " 1" << endl;
        return 0;
    }

    ll ans = 0;
    ll tmp2 = 0;
    ll flag = 0;
    rep(i, n){
        if(flag == 0 && tmp[i] == 1){
            flag = 1;
            tmp2 = i;
        }else{
            if(tmp[i] == 1){
                if(ans == 0){
                    ans = (i - tmp2) % MOD;
                    tmp2 = i;
                }else{
                    ans = ans * (i - tmp2) % MOD;
                    tmp2 = i;
                }
            }
        }
    }

    cout << (n + n - k + 1) * k / 2 << " " << ans % MOD<< endl;



}