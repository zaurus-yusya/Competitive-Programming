#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        vector<vector<char>> res(numRows);
        bool posi = true;
        int num = 0;
        rep(i, s.size()){
            if(posi){
                res[num].push_back(s[i]);
                if(num == numRows - 1){
                    posi = false;
                    num--;
                }else{
                    num++;
                }
            }else{
                res[num].push_back(s[i]);
                if(num == 0){
                    posi = true;
                    num++;
                }else{
                    num--;
                }
            }
        }

        string ans = "";
        
        rep(i, numRows){
            rep(j, res[i].size()){
                ans += res[i][j];
            }
        }
        
        //cout << ans << endl;
        return ans;
    }
};

/*
int main() {
    std::cout << std::fixed << std::setprecision(15);
    string s; cin >> s;
    int num; cin >> num;
    Solution sol;
    sol.convert(s, num);
}
*/