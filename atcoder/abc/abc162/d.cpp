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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    map<char,ll> mp;

    rep(i,s.size()){
        //cout << s[i] << endl;
        mp[s[i]]++;
    }


    ll ans = 0;

    ans = mp['R'] * mp['G'] * mp['B'];

    rep(i,n){
        char tmp = s[i];
        ll itr = i;
        ll left = i-1;
        ll right = i+1;

        while(true){
            if(left < 0){
                break;
            }
            if(right >= s.size()){
                break;
            }
            if(s[i] != s[left] && s[i] != s[right] && s[left] != s[right]){
                ans--;
            }
            left--;
            right++;
        }
    }

    cout << ans << endl;



}