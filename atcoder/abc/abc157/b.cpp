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
    vector<vector<ll>> bingo(3, vector<ll>(3));
    rep(i,3){
        rep(j,3){
            cin >> bingo.at(i).at(j);
        }
    }
    ll n;
    cin >> n;
    vector<ll> vec(n);
    rep(i, n) cin >> vec.at(i);

    vector<vector<ll>> res(3, vector<ll>(3));

    rep(i,n){
        rep(j,3){
            rep(k,3){
                if(vec.at(i) == bingo.at(j).at(k)){
                    res.at(j).at(k)++;
                }
            }
        }
    }

    string ans = "No";
    //横
    rep(i,3){
        if(res.at(i).at(0) == 1 && res.at(i).at(1) == 1 && res.at(i).at(2) == 1){
            ans = "Yes";
        }
    }
    //縦
    rep(i,3){
        if(res.at(0).at(i) == 1 && res.at(1).at(i) == 1 && res.at(2).at(i) == 1){
            ans = "Yes";
        }
    }
    //ななめ
    if(res.at(0).at(0) == 1 && res.at(1).at(1) == 1 && res.at(2).at(2) == 1){
        ans = "Yes";
    }
    if(res.at(0).at(2) == 1 && res.at(1).at(1) == 1 && res.at(2).at(0) == 1){
        ans = "Yes";
    }

    cout << ans << endl;





}