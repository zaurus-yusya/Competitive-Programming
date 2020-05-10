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
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, k;
    cin >> n >> k;

    vector<long long> vec(n);
    for(long long i = 0; i < n; i ++){
        ll a;
        cin >> a;
        a--;
        vec[i] = a;
    }

    ll count = 1;

    /*
    rep(i,n){
        cout << vec[i] << " ";
    }
    br;
    */
    

    vector<ll> ans;
    ans.push_back(0);
    map<ll,ll> mp;

    ll tmp = 0;
    count = 0;
    mp[0] = 0;
    while(true){
        if(mp.count(vec[tmp]) != 0){
            count++;
            break;
        }else{
            count++;
            tmp = vec[tmp];
            ans.push_back(tmp);
            mp[tmp] = count;
        }
    }

    /*
    rep(i,ans.size()){
        cout << "ans[" << i << "] = " << ans[i] << endl;
    }
    */
    
    //cout << count << endl;
    //cout << mp[vec[tmp]] << endl;

    ll mod = count - mp[vec[tmp]];
    //cout << "mod = " << mod << endl;
    //cout << "count = " << count << endl;
    k -= mp[vec[tmp]];
    if(k < 0){
        k += mp[vec[tmp]];
        cout << ans[k] + 1 << endl;
    }else{
        ll tmp2 = k % mod;
        cout << ans[tmp2 + mp[vec[tmp]]] + 1 << endl;
    }
    
    

}