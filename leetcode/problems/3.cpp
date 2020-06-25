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
    int lengthOfLongestSubstring(string s) {
        int ans = 0;

        if(s.size() == 1){
            return 1;
        }

        int start = 0;
        map<char, int> mp;
        mp[s[0]] = 0;

        for(int i = 1; i < s.size(); i++){
            //cout << s[i]  << " " << mp.count(s[i]) << " " << mp[s[i]] << endl;
            if(mp.count(s[i]) > 0){
                start = max(start, mp[s[i]] + 1);
                ans = max(ans, i - start + 1);
                mp[s[i]] = i;
            }else{
                mp[s[i]] = i;
                ans = max(ans, i - start + 1);
            }
            //cout << ans << endl;
        }

        return ans;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    string s; cin >> s;

    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;

}

