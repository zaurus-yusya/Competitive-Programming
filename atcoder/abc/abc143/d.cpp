#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << endl;
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

//return the number of ng
long long binary_search(vector<long long> vec, long long value) {
    long long left = -1;
    long long right = (long long)vec.size();
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        if(vec[mid] >= value){
            right = mid;
        }else{
            left = mid;
        }
    }
    return right;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> vec(n);
    rep(i, n) cin >> vec[i];
    sort(all(vec));

    // 1 2 3 4
    ll ans = 0;
    for(ll i = 0; i < n-1; i++){
        for(ll j = i+1; j < n; j++){
            ll tmp = vec[i] + vec[j];
            ll c = binary_search(vec, tmp);
            ans = ans + (c - (j+1)) ;
        }
    }

    cout << ans << endl;

}