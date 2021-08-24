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
const long long INF = 8e18;
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
    rep(T, t){ //1000
        ll a, b; cin >> a >> b; // 0 <= a, b <= 10^5 // sum <= 2*10^5
        //1ゲーム　サーブかレシーブか決まってる
        //k回ブレイク
        
        //試合数
        ll x = a+b;
        ll as = (x+1) / 2;
        ll bs = (x) / 2;

        map<ll, ll> ans;
        for(ll i = 0; i <= a; i++){
            ll cnt = 0;

            //AのゲームでAが勝つ
            ll anum = i;
            //BのゲームでAが勝つ
            ll bnum = a - i;
            
            //「AのゲームでAが勝つ」がAのゲーム数より多い
            if(as < anum) continue;
            //「BのゲームでAが勝つ」がBのゲーム数より多い
            if(bs < bnum) continue;

            cnt += bnum;
            //Bの勝利数 - (Bの試合数 - BのゲームでAが勝つ)
            cnt += b - (bs - bnum);

            ans[cnt]++;
            //cout << "anum = " << anum << " bnum = bnum"
        }
        as = (x) / 2;
        bs = (x+1) / 2;
        for(ll i = 0; i <= a; i++){
            ll cnt = 0;

            //AのゲームでAが勝つ
            ll anum = i;
            //BのゲームでAが勝つ
            ll bnum = a - i;
            
            //「AのゲームでAが勝つ」がAのゲーム数より多い
            if(as < anum) continue;
            //「BのゲームでAが勝つ」がBのゲーム数より多い
            if(bs < bnum) continue;

            cnt += bnum;
            //Bの勝利数 - (Bの試合数 - BのゲームでAが勝つ)
            cnt += b - (bs - bnum);

            ans[cnt]++;

        }

        cout << ans.size() << '\n';
        ll flag = true;
        for(auto i : ans){
            if(flag){
                flag = false;
                cout << i.first;
            }else{
                cout << ' ' << i.first;
            }
        }br;
        /*
        cout << "---" << endl;
        for(auto i : ans){
            cout << i.first << " " << i.second << endl;
        }
        cout << "------" << endl;
        */

        // AAB
        // BBA
        // 0, 1, 2, 3

        // AB
        // BA
        // 0, 1, 2

        // AAABB
        // BBBAA
        // A B A B A
        // B A B A B
        // 0, 1, 2, 3, 4, 5
        // 4
        // 3, 1

    }

}