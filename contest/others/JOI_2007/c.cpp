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

//TLE
int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> vec(n);
    map<ll,ll> mp;
    map<ll,ll> mp_ans;

    rep(i,n){
        cin >> vec.at(i);
        mp[vec.at(i)]++;
        mp_ans[vec.at(i)]++;
    }

    rep(i,3){
        rep(j,n){
            for(auto k: mp){
                mp_ans[k.first + vec.at(j)]++;
            }
        }
        mp = mp_ans;
    }

    ll ans = 0;

    for(auto i: mp_ans){
        if(i.first > m){
            break;
        }else{
            ans = i.first;
        }
    }
    cout << ans << endl;
    
}
