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

//他人のコピペ
int main() {
    vector<pair<int, int>> value;

    value.push_back(make_pair(1, 3));
    value.push_back(make_pair(2, 4));
    value.push_back(make_pair(0, 5));
    value.push_back(make_pair(5, 2));

    // vectorの表示
    for(pair<int, int> i: value){
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;

    // 昇順
    sort(value.begin(), value.end());

    // vectorの表示
    for(pair<int, int> i: value){
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;

    // 降順
    sort(value.begin(), value.end(), greater<pair<int, int>>());

    // vectorの表示
    for(pair<int, int> i: value){
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;

    return 0;

}