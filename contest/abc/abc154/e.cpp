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

long nCr(int n, int r) {
    long ans = 1;
    for (int i = n; i > n - r; --i) {
        ans = ans*i;
    }
    for (int i = 1 ; i < r + 1; ++i) {
        ans = ans / i;
    }
    return ans;
}

int main() {
    string n;
    ll x;
    cin >> n;
    cin >> x;

    ll size = n.size(); //最大101 最小1

    ll ans = 0;
    //桁数でループ
    /*
    
    for(ll i = 1; i <= size; i++){
        if(i < k) continue;
        if(i == k){
            ll tmp = 1;
            rep(i,k){
                tmp*=9;
            }
            ans += tmp;
        }

        if(i == size){
            for(ll j = 1; j <= (int)n.at(0) -48; j++){
                if(j == (int)n.at(0) -48){
                    if(k == 1){
                        ans++; //kが1のとき、最初の1ケタで残り全部0
                    }else{

                    }
                    nCr(size-1, k-1);
                }
            }
        }else{
            ll tmp = nCr(i, k);

        }
    }
    */


    long long dp[ size+1 ][ 2 ][2][ x+1 ]; //桁数,未満フラグ,数字入ったかフラグ,kの数
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;

    for(int i = 0; i < size; i++){
        const int D = (int)n.at(i) - 48;
        for(int j = 0; j < 2; j++){
            for(int y = 0; y < 2; y++){

                for(int k = 0; k < x; k++){
                    for(int d = 0; d <= ( j ? 9 : D ); ++d  ){

                        if(y == 0){
                            if(d != 0){
                                dp[ i + 1 ][ j || ( d < D ) ][y+1][k+1] += dp[ i ][ j ][y][k];
                            }else{
                                dp[ i + 1 ][ j || ( d < D ) ][y][k] += dp[ i ][ j ][y][k];
                            }
                        }else{
                            if(d != 0){
                                dp[ i + 1 ][ j || ( d < D ) ][y][k+1] += dp[ i ][ j ][y][k];
                            }else{
                                dp[ i + 1 ][ j || ( d < D ) ][y][k] += dp[ i ][ j ][y][k];
                            }
                        }

                    }
                }

            }
        }
    }

    cout << dp[size][0][1][x] + dp[size][1][1][x] << endl;
    


}