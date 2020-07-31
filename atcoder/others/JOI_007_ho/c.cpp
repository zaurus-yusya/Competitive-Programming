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
// stringの数字をint型にしてアスキーコードになったら -48する
// 切り上げ　ceil(a)
// コンパイル　g++ -std=c++17 a.cpp

ll binary_search(vector<ll> vec, ll x){
    ll left = -1, right = vec.size();
    while(right - left > 1){
        ll mid = (left + right) / 2;
        if(vec[mid] >= x){
            right = mid;
        }else{
            left = mid;
        }
    }
    return right;
}

//TLE
int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> vec;
    vec.push_back(0);
    map<ll, ll> mp;
    rep(i,n){
        ll tmp; cin >> tmp;
        if(mp[tmp] == 0){
            vec.push_back(tmp);
            mp[tmp]++;
        }
    }

    vector<ll> half;
    rep(i, n+1){
        for(ll j = i; j < n+1; j++){
            if(vec[i] + vec[j] < m)
            half.push_back(vec[i] + vec[j]);
        }
    }
    sort(all(half));
    
    ll ans = 0;
    rep(i, half.size()){
        ll x = half[i];
        if(x > m) break;
        ll res = upper_bound(all(half), m-x) - 1 - half.begin();
        ans = max(ans, x + half[res]);
    }
    cout << ans << endl;
}
