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

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<long long> vec(n);
    for(long long i = 0; i < n; i ++){
        cin >> vec[i];
    }

    vector<ll> first(n+1);
    vector<ll> second(n+1);
    vector<ll> third(n+1);

    bool ans_flag = false;
    for(ll i = 1; i <= n; i++){
        if(vec[i-1] == first[i-1]){
            first[i] = first[i-1] + 1;
            second[i] = second[i-1];
            third[i] = third[i-1];
        }else if(vec[i-1] == second[i-1]){
            first[i] = first[i-1];
            second[i] = second[i-1] + 1;
            third[i] = third[i-1];
        }else if(vec[i-1] == third[i-1]){
            first[i] = first[i-1];
            second[i] = second[i-1];
            third[i] = third[i-1] + 1;
        }else{
            ans_flag = true;
            break;
        }
    }

    /*
    rep(i, n+1){
        cout << first[i] << " ";
    }
    br;
    rep(i, n+1){
        cout << second[i] << " ";
    }
    br;
    rep(i, n+1){
        cout << third[i] << " ";
    }
    br;
    */

    if(ans_flag){
        cout << 0 << endl; return 0;
    }
    ll ans = 1;
    for(ll i = 1; i <= n; i++){
        map<ll, ll> mp;
        mp[first[i-1]]++; mp[second[i-1]]++; mp[third[i-1]]++;
        if(first[i] != first[i-1]){
            ans = (ans * mp[first[i-1]]) % MOD;
        }else if(second[i] != second[i-1]){
            ans = (ans * mp[second[i-1]]) % MOD;
        }else if(third[i] != third[i-1]){
            ans = (ans * mp[third[i-1]]) % MOD;
        }
    }
    cout << ans << endl;

}