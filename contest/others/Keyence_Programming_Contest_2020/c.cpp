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
// stringの数字をint型にしてアスキーコードになったら -48する
// 切り上げ　ceil(a)


int main() {
    ll n, k, s;
    cin >> n >> k >> s;

    if(s == INF){
        rep(i,n){
            if(i < k){
                cout << INF << " ";
            }else{
                cout << INF -1<< " ";
            }
        }
    }else{
        rep(i,n){
            if(i < k){
                cout << s << " ";
            }else{
                cout << INF << " ";
            }
            
        }
        cout << endl;
    }    

}
