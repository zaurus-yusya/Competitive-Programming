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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> vec(n);
    rep(i,s.size()){
        vec[i] = (ll)s[i];
    }

    

    ll count = 0;
    for(ll i = 0; i < n-1; i++){
        if(abs(vec[i]-vec[i+1]) == 2){
            count += 2;
        }
        if(abs(vec[i]-vec[i+1]) == 1){
            count += 1;
        }
        if(abs(vec[i]-vec[i+1]) == 0){
            count += 0;
        }
    }

    cout <<  count % 3 << endl;

}