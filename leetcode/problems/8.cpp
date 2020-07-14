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
    int myAtoi(string str) {
        
        bool posi = true;
        bool flag = false;
        vector<char> vec;
        rep(i, str.size()){

            if(flag && (str[i] < '0' || str[i] > '9')){
                break;
            }

            if(str[i] == ' '){
                continue;
            }

            if(str[i] == '-' || str[i] == '+'){
                if(i != str.size() - 1 && (str[i+1] < '0' || str[i+1] > '9')){
                    return 0;
                }else{
                    continue;
                }
            }

            if(str[i] >= '0' && str[i] <= '9'){
                if(flag == false){
                    flag = true;
                    if(i > 0 && str[i-1] == '-'){
                        posi = false;
                    }
                } 
                vec.push_back(str[i]);
            }else{
                if(flag){
                    break;
                }else{
                    cout << 0 << endl;
                    return 0;
                }
            }
        }

        ll res = 0;
        int ans = 0;
        ll tre = 2147483648;
        ll mul = 1;
        for(ll i = vec.size() - 1; i >= 0; i--){
            res += mul * (vec[i] - '0');
            if(posi){
                if(res > tre - 1){
                    ans = tre - 1;
                    return ans;
                }
            }else{
                if(res > tre){
                    ans = tre;
                    cout << ans << endl;
                    return ans;
                }
            }
            if(mul >= 1000000000000000000){
                if(vec[i] - '0' > 0){
                    res = 2147483648;
                    break;
                }
                continue;
            }
            mul *= 10;
        }
        if(res >= 2147483648){
            if(posi){
                ans = 2147483647;
            }else{
                ans = -2147483648;
            }
        }else{
            ans = res;
            if(!posi){
                ans *= (-1);
            } 
        }
        
        cout << "ans = " << ans << endl;
        return ans;
    }
};

/*
int main() {
    std::cout << std::fixed << std::setprecision(15);
    string s; getline(cin, s);
    Solution sol;
    sol.myAtoi(s);
}
*/