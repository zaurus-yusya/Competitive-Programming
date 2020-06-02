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
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

ll n;
vector<ll> H;
vector<ll> S;

bool solve(ll value) {
    bool flag = true;
    vector<ll> check;
    rep(i, n){
        if(value - H[i] < 0){
            return false;
        }
        ll tmp = (value - H[i]) / S[i];
        check.push_back(tmp);
    }

    sort(all(check));

    rep(i, n){
        if(check[i] >= i){
            continue;
        }else{
            flag = false;
        }
    }

    return flag;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> n;
    H.resize(n);
    S.resize(n);
    rep(i, n){
        cin >> H[i] >> S[i];
    }

    if(n == 1){
        cout << H[0] << endl;
        return 0;
    }

    ll left = -1, right = 1e9 + (1e5 * (1e9-1));
    while(right - left > 1){
        ll mid = (right + left) / 2;
        if(solve(mid)){
            right = mid;
        }else{
            left = mid;
        }
    }

    cout << right << endl;

}