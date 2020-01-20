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
    string s;
    cin >> s;
    int n = stoi(s);
    int size = s.size();

    vector<ll> vec(100);

    rep(i,n){
        string tmp = to_string(i+1);
        ll first = tmp.at(0) - 48;
        ll last = tmp.at(tmp.size()-1) - 48;
        vec.at(10*first + last)++;
    }

    ll ans = 0;
    for(ll i = 1; i < 10; i++){
        for(ll j = 1; j < 10; j++){
            ans += vec.at(i*10 + j) * vec.at(j*10 + i);
        }
    }

    cout << ans << endl;
}
