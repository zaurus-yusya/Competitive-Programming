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
ll ceilll(ll a, ll b) {return (a + b-1) / b;}
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll h, w, m; cin >> h >> w >> m;
    vector<ll> gyo(h);
    vector<ll> retsu(w);
    map<pair<ll, ll>, ll> mp;

    rep(i, m){
        ll x, y; cin >> x >> y;
        x--; y--;
        gyo[x] += 1;
        retsu[y] += 1;
        mp[make_pair(x, y)]++;
    }

    
    vector<ll> R;
    vector<ll> C;
    ll max_x = 0, max_y = 0;
    rep(i, h){
        if(max_x < gyo[i]){
            R.clear();
            max_x = gyo[i];
            R.push_back(i);
        }else if(max_x == gyo[i]){
            R.push_back(i);
        }
    }
    rep(i, w){
        if(max_y < retsu[i]){
            C.clear();
            max_y = retsu[i];
            C.push_back(i);
        }else if(max_y == retsu[i]){
            C.push_back(i);
        }
    }

    ll ans = max_x + max_y;
    bool flag = false;
    rep(i, R.size()){
        rep(j, C.size()){
            if(mp[make_pair(R[i], C[j])] == (ll)0){
                flag = true;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    
    if(flag){
        cout << ans << endl;
    }else{
        cout << ans -1 << endl;
    }
    /*
    if(mp[make_pair(max_x, max_y)] > (ll)0){
        ans -=1;
    }
    
    cout << ans << endl;
    */
    

}