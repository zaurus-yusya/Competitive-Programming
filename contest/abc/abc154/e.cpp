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
    ll k;
    cin >> n;
    cin >> k;

    ll size = n.size(); //最大101 最小1

    ll ans = 0;


    long long dp[ size+1 ][ 2 ][k+1]; //桁数,未満フラグ,kの数
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    for(int i = 0; i < size; i++){
        const int D = (int)n.at(i) - 48;
        for(int j = 0; j < 2; j++){
            for(int x = 0; x < k+1; x++){
                for(int y = 0; y < 10; y++){
                    if(j == 0){
                        dp[i+1][j][x] += 
                    }
                }



                /*
                if(D == 0){
                    dp[i+1][0][x]  += dp[i][0][x];
                    dp[i+1][1][x+1] += (dp[i][1][x] * 9);    
                    dp[i+1][1][x] += dp[i][1][x] + dp[i][0][x];
                }
                if(D != 0){
                    dp[i+1][0][x+1] += dp[i][0][x];
                    dp[i+1][1][x+1] += (dp[i][1][x] * 9) + (dp[i][0][x] * (D-1));                  
                    dp[i+1][1][x] += dp[i][1][x] + dp[i][0][x];
                }
                
                    cout << "i=" << i << "x=" << x <<endl;//100 1
                    cout << dp[i+1][0][0] << endl;  //未満フラグあり0以外0つ
                    cout << dp[i+1][0][1] << endl;  //未満フラグあり0以外1つ
                    cout << dp[i+1][1][0] << endl;  //未満フラグなし0以外0つ
                    cout << dp[i+1][1][1] << endl;  //未満フラグなし0以外1つ
                    cout << "------------" << endl;
                */
            }
        }
    }

    cout << "------------" << endl;
    cout << dp[1][0][0] << endl;
    cout << dp[1][0][1] << endl;
    cout << dp[1][1][0] << endl;
    cout << dp[1][1][1] << endl;
    cout << "------------" << endl;

    cout << dp[size][0][k] << endl;
    cout << dp[size][1][k] << endl;

    cout << dp[size][0][k] + dp[size][1][k] << endl;

}