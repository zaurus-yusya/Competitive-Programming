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
    ll t; cin >> t;
    rep(T, t){
        ll n; cin >> n;
        vector<long long> vec(n);
        for(long long i = 0; i < n; i ++){
            cin >> vec[i];
        }
        ll ans = 0;
        vector<ll> res;
        if(n == 1 || n == 2){
            cout << 0 << endl;
        }else{
            bool flag = false;
            ll ans = 0;
            for(ll i = n-1; i >= 0; i--){
                if(i == n-1) continue;
                if(i == n-2){
                    if(vec[i] < vec[i+1]){
                        flag = true;
                    }else{
                        flag = false;
                    }
                }else{
                    if(vec[i] > vec[i+1] && flag == true){
                        ans = i + 1;
                        break;
                    }else if(vec[i] < vec[i+1] && flag == false){
                        flag = true;
                    }
                }
            }
            if(ans == 0){
                cout << 0 << endl;
            }else{
                cout << ans << endl;
            }
        }

        

        /*
        rep(i, n){
            if(i == 0) continue;
            if(vec[i-1] > vec[i]){
                ans++;
                res.push_back(i);
            }
        }

        if(res.size() <= 1){
            cout << 0 << endl;
        }else{
            cout << res[res.size() - 2] << endl;
        }
        */

    }    

}