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

    ll ans = 0;
    for(ll i = 0; i <= 999; i++){
        ll first = i / 10 / 10 % 10;
        ll second = i / 10 % 10;
        ll third = i % 10;
        vector<ll> vec{first, second, third};
        ll flag = 0;
        for(ll j = 0; j < s.size(); j++){
            if(vec[flag] == (int)s[j] - 48){
                flag++;
                if(flag == 3){
                    break;
                }
            }
        }
        if(flag == 3) ans++;
    }

    cout << ans << endl;

}