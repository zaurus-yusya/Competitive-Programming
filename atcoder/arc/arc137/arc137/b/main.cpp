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
    vector<long long> a(n);
    map<ll, ll> mp;

    ll tmp = 0;
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
        if(a[i] == 1) tmp++;
    }
    mp[tmp]++;

    ll now = -1, cnt = 0;
    vector<ll> num;
    vector<ll> kosu;
    ll res = 0;

    rep(i, n){
        if(now != a[i]){
            num.push_back(now);
            kosu.push_back(cnt);

            now = a[i];
            cnt = 1;
            res += 1;
        }else{
            cnt++;
        }
    }

    /*
    if(res == 1){
        cout << n+1 << endl; return 0;
    }
 
    cout << n+1 - (res-2) << endl;
    */

    //cout << "tmp = " << tmp << endl;
    num.push_back(now);
    kosu.push_back(cnt);

    vector<ll> sum;
    sum.push_back(0);
    rep(i, num.size()){
        //cout << "num = " << num[i] << endl;
        if(num[i] == -1) continue;
        if(num[i] == 1){
            sum.push_back(sum[sum.size() - 1] - kosu[i]);
        }else{
            sum.push_back(sum[sum.size() - 1] + kosu[i]);
        }
    }
    // vecdbg(num);
    // vecdbg(kosu);
    // vecdbg(sum);

    
    ll rmi = 0, rma = 0;
    ll mi = tmp, ma = tmp;

    //3区間
    rep(i, num.size()){
        if(num[i] == -1) continue;
        if(num[i] == 1){
            ll x = min(mi, tmp - kosu[i]);
            ll y = min(mi, sum[i-1] + tmp - kosu[i]);
            mi = min(mi, x);
            mi = min(mi, y);
            //mi = min(mi, mi - kosu[i]);
            //mi = min(mi, sum[i-1] + mi - kosu[i]);

            
            for(ll j = 1; j <= kosu[i]; j++){
                mp[tmp - j]++;
            }
            
            if(i + 2 < num.size()){
                ll one = kosu[i] + kosu[i+2];
                ll zero = kosu[i+1];
                for(ll j = 1; j <= one; j++){
                    mp[tmp + zero - j]++;
                }
            }

            if(i + 4 < num.size()){
                ll one = kosu[i] + kosu[i+2] + kosu[i+4];
                ll zero = kosu[i+1] + kosu[i+3];
                for(ll j = kosu[i+2]+1; j <= one; j++){
                    mp[tmp + zero - j]++;
                }
            }
            
            
        }else{
            ll x = max(ma, tmp + kosu[i]);
            ll y = max(ma, sum[i - 1] + tmp + kosu[i]);
            ma = max(ma, x);
            ma = max(ma, y);
            /*
            ma = max(ma, ma + kosu[i]);
            cout << "s" << sum[i-1] << " " << ma << " " << kosu[i] << endl;
            ma = max(ma, sum[i - 1] + ma + kosu[i]);
            */
            
            for(ll j = 1; j <= kosu[i]; j++){
                mp[tmp + j]++;
            }
            
            if(i + 2 < num.size()){
                ll zero = kosu[i] + kosu[i+2];
                ll one = kosu[i+1];
                for(ll j = 1; j <= zero; j++){
                    mp[tmp - one + j]++;
              }
            } 

            if(i + 4 < num.size()){
                ll zero = kosu[i] + kosu[i+2] + kosu[i+4];
                ll one = kosu[i+1] + kosu[i+3];
                for(ll j = kosu[i+2]+1; j <= zero; j++){
                    mp[tmp - one + j]++;
              }
            } 

        }

        //cout <<"res" << mi << " " << ma << endl;
    }

    //cout << ma - mi + 1 << endl;

    // ll x = n - tmp;
    // mp[x]++;
    // rep(i, n){
    //     if(a[i] == 0){
    //         x--;
    //         mp[x]++;
    //     }else{
    //         x++;
    //         mp[x]++;
    //     }
    // }
    // x = n - tmp;
    // rep(i, n){
    //     if(a[n-1-i] == 0){
    //         x--;
    //         mp[x]++;
    //     }else{
    //         x++;
    //         mp[x]++;
    //     }
    // }

    
    ll y = tmp;
    mp[y]++;
    rep(i, n){
        if(a[i] == 1){
            y--;
            mp[y]++;
        }else{
            y++;
            mp[y]++;
        }
    }
    y = tmp;
    rep(i, n){
        if(a[n-1-i] == 1){
            y--;
            mp[y]++;
        }else{
            y++;
            mp[y]++;
        }
    }
    

    //cerr <<"--" << endl;
    ll xmi = tmp, xma = tmp;
    for(auto&i: mp){
        xmi = min(xmi, i.first);
        xma = max(xmi, i.first);
        //cerr << i.first << " " << i.second << endl;
    }
    //cerr <<"--" << endl;

    mi = max(mi, xmi);
    ma = max(ma, xma);
    cout << ma - mi + 1 << endl;
    
    //cout << mp.size() << endl;


}