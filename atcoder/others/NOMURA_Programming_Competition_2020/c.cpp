#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
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
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<ll> vec(n+1);
    rep(i, n+1){
        cin >> vec[i];
    }

    if(n == 0){
        if(vec[0] == 1){
            cout << 1 << endl;
            return 0;
        }else{
            cout << -1 << endl;
            return 0;
        }
    }

    vector<ll> vec_reverse(n+1);
    vec_reverse = vec;
    reverse(all(vec_reverse));

    
    vector<pair<ll,ll>> node_num(n+1);

    rep(i, n+1){
        if(i == 0){
            node_num[n-i] = make_pair(vec_reverse[i], vec_reverse[i]);
            continue;
        }
        ll saisyo = vec_reverse[i] + (node_num[n-i+1].first + 1) / 2;
        ll saidai = vec_reverse[i] + node_num[n-i+1].second;
        node_num[n-i] = make_pair(saisyo, saidai);
    }

    if(node_num[0].first > 1){
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0;
    ll now_node = 0;
    rep(i, n+1){
        if(i == 0){
            ans += 1;
            now_node = 1;
            continue;
        }
        ll tmp = min((now_node - vec[i-1]) * 2, node_num[i].second);
        ans += tmp;
        now_node = tmp;
    }

    cout << ans << endl;
    
    

}