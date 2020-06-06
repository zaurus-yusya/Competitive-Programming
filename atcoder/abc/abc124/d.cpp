#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e9;
const long long MOD = 1e9+7;
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
    ll n, k;
    cin >> n >> k;
    string s; cin >> s;
    vector<long long> vec(n);
    for(long long i = 0; i < n; i ++){
        vec[i] = (ll)(s[i] - 48);
    }
    vector<ll> vec2;
    vector<ll> vec2_sum;
    vec2_sum.push_back(0);
    ll now = vec[0];
    ll count = 0;
    for(ll i = 0; i < n; i++){
        if(vec[i] == now){
            count++;
        }else{
            vec2.push_back(count);
            vec2_sum.push_back(vec2_sum[vec2_sum.size() - 1] + count);
            now = vec[i];
            count = 1;
        }
    }
    vec2.push_back(count);
    vec2_sum.push_back(vec2_sum[vec2_sum.size() - 1] + count);

    

    /*
    rep(i, vec2.size()){
        cout << vec2[i];
        (i == vec2.size() - 1) ? cout << endl : cout << " ";
    }
    cout << vec2.size() << endl;
    rep(i, vec2_sum.size()){
        cout << vec2_sum[i];
        (i == vec2_sum.size() - 1) ? cout << endl : cout << " ";
    }
    */
    

    ll ans = 0;
    
    if(vec[0] == 1){
        if(vec2.size() / 2 <= k){
            cout << n << endl;
            return 0;
        }
        ll seq = (k * 2) + 1;
        for(ll i = 0; i + seq < vec2_sum.size(); i+=2){
            ans = max(ans, vec2_sum[i + seq] - vec2_sum[i]);
        }
        if(vec[n-1] == 0 && vec2_sum.size() - 1 - (k*2) >= 0){
            ans = max(ans, vec2_sum[vec2_sum.size() - 1] - vec2_sum[vec2_sum.size() - 1 - (k*2)]);
        }
    }

    if(vec[0] == 0){
        if((vec2.size() + 1) / 2 <= k){
            cout << n << endl;
            return 0;
        }
        ll seq = (k * 2) + 1;
        for(ll i = 1; i + seq < vec2_sum.size(); i+=2){
            ans = max(ans, vec2_sum[i + seq] - vec2_sum[i]);
        }

        ans = max(ans, vec2_sum[k * 2] - vec2_sum[0]);
        if(vec[n-1] == 0 && vec2_sum.size() - 1 - (k*2) >= 0){
            ans = max(ans, vec2_sum[vec2_sum.size() - 1] - vec2_sum[vec2_sum.size() - 1 - (k*2)]);
        }
    }
    

    cout << ans << endl;

}