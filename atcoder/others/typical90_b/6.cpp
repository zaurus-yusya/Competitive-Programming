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
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    vector<queue<ll>> alphabet(26);

    rep(i, s.size()){
        ll posiex = s[i] - 'a';
        alphabet[posiex].push(i);
    }

    string ans = "";

    ll cnt = 0;
    ll lastchoice = -1;

    while(cnt < k){
        //cout << "cnt = " << cnt << endl;
        for(ll i = 0; i < 26; i++){
            bool flag = false;

            while(!alphabet[i].empty()){
                ll posi = alphabet[i].front();
                if(lastchoice < posi && posi <= s.size() - k + cnt){
                    //取れた
                    ans += i + 'a';
                    lastchoice = posi;
                    //cout << lastchoice << endl;
                    cnt++;
                    alphabet[i].pop();
                    flag = true;
                    break;
                }else{
                    //取れなかった
                    if(lastchoice >= posi){
                        //すでに見てるところがlastchoiceより左だったらpopして次を見る
                        alphabet[i].pop(); //この処理は全体を通してs.size()回
                    }else{
                        break;
                    }
                }
            }

            if(flag) break; //文字取れてたらbreak
        }

    }

    cout << ans << endl;

}