#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << '\n';
using namespace std;
const long long INF = 8e18;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << ' ';} cerr << '\n';}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << ' ';} cerr << '\n';}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;
const double PI = acos(-1);

// 0 false, 1 true 
// string number to int : -48 or - '0'
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!
// (a * b)over flow?   if(a > INF / b){ /* overflow */}
// for(auto& i: mp) &&&&&&&&&&&&&

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<string> vec(n);
    vector<char> fi(n);
    vector<char> la(n);
    rep(i, n){
        cin >> vec[i];
        fi[i] = vec[i][0];
        la[i] = vec[i][vec[i].size() - 1];
    }

    if(n == 1){
        cout << "First" << endl;
        return 0;
    }


    vector<vector<ll>> dp((1<<n) + 1, vector<ll>(n + 1, 0)); // 状態, 最後に選ばれたやつ
    // 0まだ選んでない, 1選んだ
    // 最後に選ばれたものは1である必要がある。0はだめ
    // 全部選ばれている時は負け

    for(ll i = ((1<<n) - 1); i >= 0; i--){

        for(ll j = 0; j < n; j++){
            if(i != 0 && (i >> j) & 1 == 0){
                // 最後に選ばれたものは1である必要がある。0はだめ
                continue;
            }else{
                // しりとりの頭
                char last_word = la[j];

                map<ll, ll> mex;
                // 行けるとこ調べる
                for(ll k = 0; k < n; k++){ // k番目が行けるか
                    //　既に行っていたらcontinue
                    if((i >> k) & 1 == 1){
                        continue;
                    }else{
                        // 行っていなかったら行けるか調べる

                        if(i == 0){
                            // i=0のときは全部いける
                            mex[dp[i | (1<<k)][k]]++;
                        }
                        else if(fi[k] == last_word){
                            // 行ける場合
                            mex[dp[i | (1<<k)][k]]++;
                        }

                    }
                }

                // MEX求める
                ll res = 0;
                while(true){
                    if(mex.count(res) == 0){
                        break;
                    }else{
                        res++;
                    }
                }
                dp[i][j] = res;
            }
        }
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++){
        // どれか1個でも勝ち状態あればFirst
        ans = max(ans, dp[0][i]);
    }
    if(ans == 0){
        cout << "Second" << endl;
    }else{
        cout << "First" << endl;
    }

}