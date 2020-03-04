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
// コンパイル　g++ -std=c++17 a.cpp

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> s(m);
    vector<ll> c(m);
    rep(i, m){
        cin >> s.at(i) >> c.at(i);
    } 
    
    vector<ll> vec(3);
    rep(i,3){
        vec.at(i) = -1;
    }

    ll ans = -1;

    rep(i,m){
        if(vec.at(s.at(i) - 1) == -1){
            vec.at(s.at(i) - 1) = c.at(i);
        }else{
            if(c.at(i) == vec.at(s.at(i) - 1)){
                continue;
            }else{
                cout << -1 << endl;
                return 0;
            }
        }
    }

    if(vec.at(0) == 0 && n != 1){
        cout << -1 << endl;
        return 0;
    }



    rep(i,n){
        if(vec.at(i) == -1 && n == 1){
            vec.at(i) = 0;
        }
        if(vec.at(i) == -1 && n != 1 && i == 0){
            vec.at(i) = 1;
        }
        if(vec.at(i) == -1 && n != 1 && i != 0){
            vec.at(i) = 0;
        }
        cout << vec.at(i);
    }
    cout << endl;

}