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

int main() {
    ll n;
    cin >> n;

    vector<ll> vec_posi;
    vector<ll> vec_zero;
    vector<ll> vec_nega;

    

    vector<long long> vec_a(n);
    rep(i, n){
        cin >> vec_a[i];
    } 
    vector<long long> vec_b(n);
    vector<long long> vec_c(n);
    rep(i, n){
        cin >> vec_b[i];
        ll tmp = vec_a[i] - vec_b[i];
        vec_c[i] = tmp;
        if(tmp > 0){
            vec_posi.push_back(tmp);
        }else if(tmp == 0){
            vec_zero.push_back(tmp);
        }else{
            vec_nega.push_back(tmp);
        }
    }
    
    sort(all(vec_posi));
    sort(all(vec_zero));
    sort(all(vec_nega));

    ll ans = 0;
    rep(i,vec_nega.size()){
        auto itr = upper_bound(all(vec_posi), -vec_nega[i]);
        ans += vec_posi.end() - itr;
    }

    ans += vec_zero.size() * vec_posi.size();

    ans += (vec_posi.size() * (vec_posi.size() - 1) / 2);

    cout << ans << endl;

    return 0;
}