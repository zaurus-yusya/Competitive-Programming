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

void bit_full_search(int n, vector<ll> vec, ll* ans)
{
    //2^n回ループ
    for (int bit = 0; bit < (1<<n); ++bit) {
        //cout << "{";
        ll t1 = 0;
        ll t2 = 0;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) {
                //cout << " " << i << " ";
                t1 += vec.at(i);
            }else{
                t2 += vec.at(i);
            } 
        }
        //cout << "}" << endl;
        chmin(*ans, max(t1,t2));
    }

    
}

int main() {
    ll n;
    cin >> n;
    ll ans = INF;
    vector<ll> vec(n);
    rep(i,n){
        cin >> vec.at(i);
    }


    bit_full_search(n, vec, &ans);

    cout << ans << endl;


}
