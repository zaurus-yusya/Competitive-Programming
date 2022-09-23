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

/*
void dfs(string &s, ll l, ll r, ll now, bool is_migi){
    //今見てる文字はs[now]
    if(is_migi){
        // 反転
        if(s[now] == 'd'){
            if(ans[now] == 'p'){
                // 続ける
            }else{
                // 終わる
                return;
            }
        }else{
            if(ans[now] == 'd'){
                // 続ける
            }else{
                // 更新して続ける
                ans[now] = 'd';
            }
        }
    }else{

    }

    if(is_migi){

    }else{
        // Rを決める
        for(ll i = s.size() - 1; i > now; i++){
            dfs(s, now+1, i, i, true);
        }
        // 進む
        dfs(s, l, r, now+1, false);
    }
    

}
*/

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    string s; cin >> s;

    vector<ll> num;
    vector<char> mozi;

    char now = ' ';
    ll cnt = 0;
    
    rep(i, n){
        if(now != s[i]){
            if(now != ' '){
                num.push_back(cnt);
                mozi.push_back(now);
            }else{
                
            }
            now = s[i];
            cnt = 1;
        }else{
            cnt++;
        }
    }
    num.push_back(cnt);
    mozi.push_back(now);
    
    // vecdbg(num);
    // vecdbg(mozi);

    vector<pair<char, ll>> p;

    rep(i, num.size()){
        p.push_back({mozi[i], num[i]});
    }



    if(num.size() == 1){
        rep(i, s.size()){
            cout << 'd';
        }br;
        return 0;
    }

    if(mozi[0] == 'd'){
        // 左1固定
        for(ll r = 1; r < num.size(); r+=2){
            if(num[1] <= num[r]){
                // cerr << 1 << " " << r << endl;
                // 入れ替える
                vector<pair<char, ll>> tmp;

                for(ll k = 0; k < 1; k++){
                    tmp.push_back({mozi[k], num[k]});
                }
                for(ll k = r; k >= 1; k--){
                    if(mozi[k] == 'p'){
                        tmp.push_back({'d', num[k]});
                    }else{
                        tmp.push_back({'p', num[k]});
                    }
                }
                for(ll k = r+1; k < num.size(); k++){
                    tmp.push_back({mozi[k], num[k]});
                }

                string ans = "";
                rep(i, tmp.size()){
                    rep(j, tmp[i].second){
                        ans += tmp[i].first;
                    }
                }
                // cerr << ans << endl;
                if(ans < s){
                    s = ans;
                }
                /*
                if(tmp < p){
                    cerr << "in" << endl;
                    p = tmp;
                }
                */
                
            }
        }
    }else{
        //左0固定
        for(ll r = 0; r < num.size(); r+=2){
            if(num[0] <= num[r]){
                vector<pair<char, ll>> tmp;
                for(ll k = 0; k < 0; k++){
                    tmp.push_back({mozi[k], num[k]});
                }
                for(ll k = r; k >= 0; k--){
                    if(mozi[k] == 'p'){
                        tmp.push_back({'d', num[k]});
                    }else{
                        tmp.push_back({'p', num[k]});
                    }
                }
                for(ll k = r+1; k < num.size(); k++){
                    tmp.push_back({mozi[k], num[k]});
                }


                string ans = "";
                rep(i, tmp.size()){
                    rep(j, tmp[i].second){
                        ans += tmp[i].first;
                    }
                }
                // cerr << ans << endl;
                if(ans < s){
                    s = ans;
                }

            }
        }

    }

    cout << s << endl;
    /*
    string ans = "";
    rep(i, p.size()){
        rep(j, p[i].second){
            ans += p[i].first;
        }
    }

    cout << ans << endl;
    */

    /*
    for(ll l = 0; l < n; l++){
        for(ll r = l+1; r < n; r++){

            for(ll i = 0; i < n; i++){

                if(l <= i && i < r){

                }else{

                }

            }
            cerr << l << " " << r << endl;

            string t = s;
            for(ll j = )


        }
    }
    */


}