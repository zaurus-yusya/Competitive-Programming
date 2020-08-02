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
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

ll n, k;
vector<ll> vec(n);

//return the number of ng
//left always ng. right always ok
long long nibun_search(ll val) {
    long long left = -1;
    long long right = val;
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        if(mid == 0){
            return 1;
        }
        ll count = 0;
        rep(i, n){
            if(vec[i] % mid == 0){
                count += ((vec[i] / mid) - 1);
                
            }else{
                count += (vec[i] / mid);
            }
        }
        if(count <= k){
            right = mid;
        }else{
            left = mid;
        }
    }
    return right;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> n >> k;
    vec.resize(n);
    
    for(long long i = 0; i < n; i ++){
        cin >> vec[i];
    }
    cout << nibun_search(1000000000) << endl;

}