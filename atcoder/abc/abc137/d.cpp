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
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> vec(n);
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        vec[i] = make_pair(a, b);
    }

    sort(all(vec));

    priority_queue<ll> que;

    ll ans = 0;
    ll tmp = 0;
    rep(i,m){

        for(ll j = tmp; j < n; j++){
            if(vec[j].first == (i+1)){
                que.push(vec[j].second);
            }else{
                tmp = j;
                break;
            }
        }
        
        if(!que.empty()){
            ans += que.top();
            que.pop();
        } 
    }

    cout << ans << endl;

}