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
    vector<long long> c(9);
    for(long long i = 0; i < 9; i ++){
        cin >> c[i];
    }

    bool ff = false;
    for(long long i = 0; i < 9; i ++){
        if(n >= c[i]){
            ff = true;
        }
    }
    if(!ff){
        cout << 0 << endl; return 0;
    }


    vector<vector<ll>> dp(1000010, vector<ll>(10)); // cost i円で最大の要素

    // 配るdp
    dp[0] = {0,0,0,0,0,0,0,0,0,1};
    for(ll i = 0; i <= n; i++){

        if(dp[i][9] == 0){
            continue;
        }

        for(ll j = 0; j < 9; j++){
            ll cost = c[j];
            if(i + c[j] > n) continue;

            vector<ll> now = dp[i];

            vector<ll> next = dp[i + cost];
            vector<ll> tmp = dp[i];
            tmp[j] += 1;

            //tmpとnextの大小関係の比較
            ll tmp_keta = 0, next_keta = 0;
            for(ll i = 0; i <= 8; i++){
                tmp_keta += tmp[i];
                next_keta += next[i];
            }

            if(tmp_keta > next_keta){
                dp[i + c[j]] = tmp;
                dp[i + c[j]][9] = 1;
            }else if(tmp_keta < next_keta){

            }else{
                bool f = true;
                for(ll i = 8; i >= 0; i--){
                    if(tmp[i] > next[i]){
                        f = true; break;
                    }else if(tmp[i] < next[i]){
                        f = false; break;
                    }else{
                        continue;
                    }
                }

                if(f){
                    dp[i + c[j]] = tmp;
                    dp[i + c[j]][9] = 1;
                }
            }
        }

    }

    vector<ll> res = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

    for(ll i = 0; i <= n; i++){
        vector<ll> tmp = dp[i];

        if(tmp[9] == 0) continue;

        ll tmp_keta = 0, res_keta = 0;
        for(ll i = 0; i <= 8; i++){
            tmp_keta += tmp[i];
            res_keta += res[i];
        }

        if(tmp_keta > res_keta){
            res = tmp;
        }else if(tmp_keta < res_keta){

        }else{
            bool f = true;
            for(ll i = 8; i >= 0; i--){
                if(tmp[i] > res[i]){
                    f = true; break;
                }else if(tmp[i] < res[i]){
                    f = false; break;
                }else{
                    continue;
                }
            }

            if(f){
                res = tmp;
            }
        }
    }

    map<ll, char> mp;
    mp[0] = '1';
    mp[1] = '2';
    mp[2] = '3';
    mp[3] = '4';
    mp[4] = '5';
    mp[5] = '6';
    mp[6] = '7';
    mp[7] = '8';
    mp[8] = '9';

    string ans = "";
    for(ll i = 8; i >= 0; i--){
        for(ll j = 0; j < res[i]; j++){
            ans += mp[i];
        }
    }
    cout << ans << endl;




    // for(ll i = 0; i < 10; i++){
    //     cout << dp[20][i] << " "; 
    // }br;

    return 0;
    /*
    // 1がある場合
    vector<ll> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};


    vector<ll> res(10, 0);

    ll cnt = 0;
    do{ // 362880
        
        ll yosan = n;
        vector<ll> num_times(10);

        for(ll i = 0; i < vec.size(); i++){
            ll now = vec[i];
            ll tmp_num = vec[i];
            ll kane = c[now-1];

            num_times[tmp_num] = yosan / kane;

            yosan -= kane * num_times[tmp_num];
        }

        // num_timesとresの大小関係
        ll num_times_keta = 0, res_keta = 0;
        for(ll i = 1; i <= 9; i++){
            num_times_keta += num_times[i];
            res_keta += res[i];
        }

        if(num_times_keta > res_keta){
            res = num_times;
        }else if(num_times_keta < res_keta){
            continue;
        }else{
            // 桁数同じ
            bool f = true;
            for(ll i = 9; i >= 1; i++){
                if(num_times[i] > res[i]){
                    f = true; break;
                }else if(num_times[i] < res[i]){
                    f = false; break;
                }else{
                    continue;
                }
            }

            if(f){
                res = num_times;
            }
        }

    }while(next_permutation(vec.begin(), vec.end()));

    // vecdbg(res);

    map<ll, char> mp;
    mp[1] = '1';
    mp[2] = '2';
    mp[3] = '3';
    mp[4] = '4';
    mp[5] = '5';
    mp[6] = '6';
    mp[7] = '7';
    mp[8] = '8';
    mp[9] = '9';

    string ans = "";
    for(ll i = 9; i >= 1; i--){
        for(ll j = 0; j < res[i]; j++){
            ans += mp[i];
        }
    }

    cout << ans << endl;
    */


}