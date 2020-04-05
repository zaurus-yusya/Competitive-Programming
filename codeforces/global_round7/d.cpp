#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// res[i][c] := i 文字目以降で最初に文字 c が登場する index (存在しないときは n)


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t;
    cin >> t;
    
    rep(i, t){
        string s;
        cin >> s;

        deque<char> deq;

        //前だけ
        string ans_1 = "";

        rep(i, n){
            
        }

        ans_1 += 'b';


        cout << ans_1 << endl;
        cout << ans_1.at(ans_1.size() - 1) << endl;
        cout << ans_1.at(ans_1.size() - 2) << endl;
        //後ろだけ

        //前と後ろ
    }

}