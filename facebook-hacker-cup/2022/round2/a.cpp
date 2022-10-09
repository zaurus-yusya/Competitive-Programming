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
    ll t; cin >> t;
    rep(T, t){
        string s; cin >> s; // sum 4000000 
        ll n = s.size();
        vector<vector<ll>> sum(26, vector<ll>(n + 1));
        // singingbanana
        // a 0 0 0 0 0 0 0 0 0 1 1 2 2 3 
        rep(i, 26){
            char mozi = 'a' + i;
            // cerr << "mozi " << mozi << endl;
            rep(j, n){
                if(s[j] == mozi){
                    sum[i][j+1] = sum[i][j] + 1;
                }else{
                    sum[i][j+1] = sum[i][j];
                }
            }
        }
        /*
        rep(i, n){
            ll num = s[i] - 'a';
            // cerr << s[i] << " " << num << endl;
            rep(j, 26){
                if(j == num){
                    sum[j][i + 1] = sum[j][i] + 1;
                }else{
                    sum[j][i + 1] = sum[j][i];
                }
            }
        }
        */

        // rep(i, 26){
        //     cout << (char)('a' + i) << " ";
        //     rep(j, n+1){
        //         cout << sum[i][j] << " ";
        //     }br;
        // }

        ll q; cin >> q; // sum 4000000
        ll ans = 0;
        rep(i, q){
            ll l, r; cin >> l >> r; l--;
            if((l % 2) == (r % 2)){
                // ぐうき不一致
                // cerr << "con" << endl;
                continue;
            }

            // singingbanana
            ll mid = (l + r) / 2;
            // cerr << "l = " << l << " r = " << r << " mid = " << mid << endl;

            map<char, ll> left;
            map<char, ll> right;
            rep(j, 26){
                char mozi = 'a' + j;
                ll L = sum[j][mid] - sum[j][l];
                ll R = sum[j][r] - sum[j][mid];

                // cerr << mozi << " " << L << " " << R << endl;

                left[mozi] = L;
                right[mozi] = R;
            }

            ll cnt = 0;
            bool f = true;
            rep(j, 26){
                char mozi = 'a' + j;
                if(left[mozi] != right[mozi]){
                    cnt++;
                    if(abs(left[mozi] - right[mozi]) != 1){
                        f = false;
                    }
                }
            }

            if(f && (cnt == 1)){
                ans++;
                continue;
            }

            // cerr << "----kouhan" << endl;
            mid += 1;
            map<char, ll> left2;
            map<char, ll> right2;
            rep(j, 26){
                char mozi = 'a' + j;
                ll L = sum[j][mid] - sum[j][l];
                ll R = sum[j][r] - sum[j][mid];
                // cerr << mozi << " " << L << " " << R << endl;
                left2[mozi] = L;
                right2[mozi] = R;
            }

            cnt = 0;
            f = true;
            rep(j, 26){
                char mozi = 'a' + j;
                // cerr << mozi << " " << left2[mozi] << " " << right2[mozi] << endl;
                if(left2[mozi] != right2[mozi]){
                    cnt++;
                    if(abs(left2[mozi] - right2[mozi]) != 1){
                        f = false;
                    }
                }
            }
            // cerr << cnt << endl;
            if(f && (cnt == 1)){
                ans++;
                continue;
            }


        }

        cout << "Case #" << T+1 << ": " << ans << '\n';

    }

}