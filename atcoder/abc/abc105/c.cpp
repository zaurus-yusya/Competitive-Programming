#include <bits/stdc++.h>
#include <atcoder/all>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
using namespace atcoder;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!

vector<ll> binary(ll bina){
    ll ans = 0;
    vector<ll> res;
    for (ll i = 0; abs(bina)>0 ; i++)
    {
        res.push_back(bina % (-2));
        ans = ans+(bina%2)*pow(10,i);
        bina = bina/2;
    }
    return res;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    
    if(n == 0){
        cout << 0 << endl; return 0;
    }
    if(n == 1){
        cout << 1 << endl; return 0;
    }
    if(n == -1){
        cout << 11 << endl; return 0;
    }

    bool flag;
    if(n > 0) flag = true;
    else flag = false;

    n = abs(n);
    vector<ll> ans;
    ll now = 1;
    ll cnt = 0;
    while(true){
        if(n / now == 1 && n % now == 0){
            //cout << "ok" << endl;
            if(flag){
                if(cnt % 2 == 0){
                    ans.push_back(1); 
                }else{
                    ans.push_back(1); ans.push_back(1);
                }
            }else{
                if(cnt % 2 == 0){
                    ans.push_back(1); ans.push_back(1);
                }else{
                    ans.push_back(1); 
                }
            }
            break;
        }
        if(n / (now*2) == 0) break;
        if(n % (now*2) != 0){
            ans.push_back(1);
            if(flag){
                if(cnt % 2 == 0) n -= now;
                else n += now;
            }else{
                if(cnt % 2 == 0) n += now;
                else n -= now;
            }
        }else{
            ans.push_back(0);
        }

        //cout << "now = " << now << " n = " << n << " cnt = " << cnt << endl;
        now = now*2;
        cnt++;

        
    }

    rep(i, ans.size()){
        cout << ans[ans.size() - 1 - i];
    }br;
    

}