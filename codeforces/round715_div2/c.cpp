#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;

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
    vector<long long> s(n);
    map<ll, ll> mp;
    for(long long i = 0; i < n; i ++){
        cin >> s[i];
        mp[s[i]]++;
    }

    
    vector<P> vec;
    for(auto i : mp){
        cout << i.first << " " << i.second << endl;
        vec.push_back({i.first, i.second});
    }
    sort(all(vec));

    ll ans = INF;
    rep(i, vec.size()){
        //始点を決める
        cout << "i = " << i << endl; 
        ll mi = vec[i].first, ma = vec[i].first;
        ll tmp = 0;
        ll l = i, r = i;
        while(!(l == 0 && r == vec.size()-1)){
            if(l == 0){
                //絶対右
                chmin(mi, vec[r+1].first);
                chmax(ma, vec[r+1].first);
                tmp += (ma - mi) * vec[r+1].second;
                r += 1;
            }else if(r == vec.size()-1){
                //絶対左
                chmin(mi, vec[l-1].first);
                chmax(ma, vec[l-1].first);
                tmp += (ma - mi) * vec[l-1].second;
                l -= 1;
            }else{
                //小さい方を選ぶ
                ll tmp_ma = max(ma, vec[r+1].first);
                ll tmp_mi = min(mi, vec[l-1].first);
                cout << tmp_ma << " " << tmp_mi << endl;
                cout << (mi - tmp_mi) * vec[l-1].second << " " << (tmp_ma - ma) * vec[r+1].second << endl;

                if(  (mi - tmp_mi) * vec[l-1].second > (tmp_ma - ma) * vec[r+1].second){
                    chmin(mi, vec[r+1].first);
                    chmax(ma, vec[r+1].first);
                    tmp += (ma - mi) * vec[r+1].second;
                    r += 1;
                }else{
                    chmin(mi, vec[l-1].first);
                    chmax(ma, vec[l-1].first);
                    tmp += (ma - mi) * vec[l-1].second;
                    l -= 1;
                }
            }
        }
        chmin(ans, tmp);
    }
    cout << ans << endl;



    /*
    sort(all(s));
    ll ans = INF;
    rep(i, n){
        //始点を決める
        ll start_ind = i;

        
        //左に行って右に行く
        ll mi = s[i], ma = s[i];
        ll tmp = 0;
        
        for(ll j = start_ind - 1; j >= 0; j--){
            chmin(mi, s[j]);
            chmax(ma, s[j]);
            tmp += ma - mi;
        }
        for(ll j = start_ind + 1; j < n; j++){
            chmin(mi, s[j]);
            chmax(ma, s[j]);
            tmp += ma - mi;
        }
        chmin(ans, tmp);

        //右に行って左に行く
        mi = s[i]; ma = s[i];
        tmp = 0;
        for(ll j = start_ind + 1; j < n; j++){
            chmin(mi, s[j]);
            chmax(ma, s[j]);
            tmp += ma - mi;
        }
        for(ll j = start_ind - 1; j >= 0; j--){
            chmin(mi, s[j]);
            chmax(ma, s[j]);
            tmp += ma - mi;
        }
        chmin(ans, tmp);
        

        mi = s[i]; ma = s[i];
        tmp = 0;
        //左か右小さい方を選ぶ
        ll l = i, r = i;
        while(!(l == 0 && r == n-1)){
            if(l == 0){
                //絶対右
                chmax(ma, s[r+1]);
                tmp += ma - mi;
                r += 1;
            }else if(r == n-1){
                //絶対左
                chmin(mi, s[l-1]);
                tmp += ma - mi;
                l -= 1;
            }else{
                //小さい方を選ぶ
                if(  (mi - s[l - 1]) > (s[r + 1] - ma)){
                    chmax(ma, s[r+1]);
                    tmp += ma - mi;
                    r += 1;
                }else{
                    chmin(mi, s[l-1]);
                    tmp += ma - mi;
                    l -= 1;
                }
            }
        }
        chmin(ans, tmp);
        

    }
    

    cout << ans << endl;
    */



}