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
    double n, k;
    cin >> n >> k;
    vector<double> vec(n);
    rep(i, n) cin >> vec.at(i);

    vector<double> dice(n);
    rep(i,n){
        dice.at(i) = ((1+vec.at(i)) * vec.at(i) / 2) / vec.at(i);
    }
    
    /*
    rep(i,n){
        cout << dice.at(i) << " ";
    }
    cout << endl;
    cout << "----" << endl;
    */
    
   ll flag = 0;
   double ans = 0;
   double tmp = 0;
   rep(i,n){
       if(i >= k-1){
           if(flag == 0){
                rep(j, k){
                    tmp += dice.at(j);
                }
                flag = 1;
           }else{
               tmp -= dice.at(i - k);
               tmp += dice.at(i);
           }
       }

       if(ans < tmp){
           ans = tmp;
       }
   }

    /*
    double ans = 0;
    rep(i, n-k+1){
        double tmp = 0;
        rep(j, k){
            tmp += dice.at(i+j);
        }

        if(ans < tmp){
            ans = tmp;
        }
    }
    */

    cout << fixed << setprecision(6) << ans << endl;;
}