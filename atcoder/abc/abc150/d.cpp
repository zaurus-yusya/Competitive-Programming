#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
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
    ll n, m; cin >> n >> m;
    vector<long long> vec(n);
    ll num = 0;
    ll LC = 1;
    for(long long i = 0; i < n; i ++){
        cin >> vec[i];
        vec[i] = vec[i] / 2;

        ll tmp = vec[i], count = 0;
        while(tmp % 2 == 0){
            count++;
            tmp = tmp / 2;
        }
        if(i == 0){
            num = count;
        }else{
            if(num != count){
                cout << 0 << endl;
                return 0;
            }
        }

        LC = lcm(LC, vec[i]);
    }

    cout << (m / LC + 1) / 2 << endl;

}
