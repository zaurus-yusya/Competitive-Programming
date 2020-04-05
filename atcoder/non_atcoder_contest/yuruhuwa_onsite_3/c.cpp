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
    ll a, b, c;
    cin >> a >> b >> c;

    vector<string> vec_a(a);
    rep(i, a) cin >> vec_a.at(i);
    vector<string> vec_b(b);
    rep(i, b) cin >> vec_b.at(i);
    vector<string> vec_c(c);
    rep(i, c) cin >> vec_c.at(i);

    map<string, ll> map;

    rep(i,a){
        map[vec_a.at(i)]++;
    }
    rep(i,b){
        map[vec_b.at(i)]++;
    }
    ll ans = 0;
    rep(i,c){
        if(map.count(vec_c.at(i)) == 0){
            ans++;
            //cout << vec_c.at(i) << endl;
        }
    }

    cout << ans << endl;

}