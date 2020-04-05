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
    ll t;
    cin >> t;
    rep(i,t){
        ll n, m;
        cin >> n >> m;
        vector<long long> vec(n);
        rep(i, n){
            cin >> vec[i];
            vec[i]--;
        }

        vector<long long> swa(m);
        rep(i, m){
            cin >> swa[i];
            swa[i]--;
        }
        sort(all(swa));

        while(true){
            ll flag = 0;
            rep(j,swa.size()){
                if(vec[swa[j]] > vec[swa[j] + 1]){
                    flag = 1;
                    swap(vec[swa[j]], vec[swa[j] + 1]);
                }
            }
            if(flag == 0){
                break;
            }
        }

        string ans = "YES";
        rep(j,n-1){
            if(vec[j] > vec[j+1]){
                ans = "NO";
            }
        }
        cout << ans << endl;
    }

}