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

int main() {
    ll n, p;
    cin >> n >> p;
    vector<ll> vec(n);
    rep(i, n) cin >> vec.at(i);
    sort(all(vec),greater<ll>());
    ll flag = 0;
    rep(i,n){
        if(vec.at(i) <= p){
            flag = 1;
            cout << p - vec.at(i) << endl;
            break;
        }
    }
    if(flag == 0){
        cout << p << endl;
    }
}