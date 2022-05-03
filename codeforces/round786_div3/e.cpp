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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<long long> a(n);
    map<ll, ll> mp;
    vector<ll> se(n);
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
        se[i] = ceilll(a[i], 2);
        mp[se[i]]++;
    }

    
    ll ans = INF;
    rep(i, n){
        ll tmp = 0;

        // 該当箇所を0になるまで実行
        tmp += se[i];
        // cerr << "tmp = " << tmp << endl;

        ll l = INF, r = INF;
        // 両サイドの回数
        if(i == 0){ // 右サイドだけ
            ll tmp_r = max(0LL, a[i+1] - se[i]);
            mp[se[i]]--;
            if(mp[se[i]] == 0){
                mp.erase(se[i]);
            }
            mp[se[i+1]]--;
            if(mp[se[i+1]] == 0){
                mp.erase(se[i+1]);
            }

            ll new_se_r = ceilll(tmp_r, 2);
            mp[new_se_r]++;


            for(auto&i: mp){
                // cerr << i.first << " " << i.second << endl;
                tmp += i.first;
                break;
            }

            ans = min(ans, tmp);
            // cerr << ans << endl;

            mp[se[i]]++;
            mp[se[i+1]]++;
            mp[new_se_r]--;
            if(mp[new_se_r] == 0){
                // cerr << "in" << endl;
                mp.erase(new_se_r);
            }
            
        }else if(i == n-1){ // 左サイドだけ
            ll tmp_l = max(0LL, a[i-1] - se[i]);
            mp[se[i]]--;
            if(mp[se[i]] == 0){
                mp.erase(se[i]);
            }
            mp[se[i-1]]--;
            if(mp[se[i-1]] == 0){
                mp.erase(se[i-1]);
            }

            ll new_se_l = ceilll(tmp_l, 2);
            mp[new_se_l]++;

            for(auto&i: mp){
                tmp += i.first;
                break;
            }

            ans = min(ans, tmp);
            // cerr << ans << endl;

            mp[se[i]]++;
            mp[se[i-1]]++;
            mp[new_se_l]--;
            if(mp[new_se_l] == 0){
                mp.erase(new_se_l);
            }
            
        }else{ // 両サイド
            ll tmp_l = max(0LL, a[i-1] - se[i]);
            ll tmp_r = max(0LL, a[i+1] - se[i]);
            // cerr << tmp_l << " " << tmp_r << endl;

            mp[se[i]]--;
            if(mp[se[i]] == 0){
                mp.erase(se[i]);
            }
            mp[se[i+1]]--;
            if(mp[se[i+1]] == 0){
                mp.erase(se[i+1]);
            }
            ll new_se_r = ceilll(tmp_r, 2);
            mp[new_se_r]++;
            mp[se[i-1]]--;
            if(mp[se[i-1]] == 0){
                mp.erase(se[i-1]);
            }

            ll new_se_l = ceilll(tmp_l, 2);
            mp[new_se_l]++;

            // cerr << new_se_l << " " << new_se_r << endl;
            for(auto&i: mp){
                // cerr << i.first << endl;
                tmp += i.first;
                break;
            }

            ans = min(ans, tmp);
            // cerr << ans << endl;

            mp[se[i]]++;
            mp[se[i+1]]++;
            mp[new_se_r]--;
            if(mp[new_se_r] == 0){
                mp.erase(new_se_r);
            }
            mp[se[i-1]]++;
            mp[new_se_l]--;
            if(mp[new_se_l] == 0){
                mp.erase(new_se_l);
            }

        }

        


    }
    cout << ans << endl;


}