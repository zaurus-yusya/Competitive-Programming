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


bool is_palindrome(string s){
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}


int main() {
    std::cout << std::fixed << std::setprecision(15);
    string s;
    cin >> s;
    ll n = s.size();

    if(n == 3){
        if(s[0] == s[2]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
        return 0;
    }

    string ans = "Yes";
    for(ll i = 0; i <= n/2; i++){
        if(s[i] == s[n-1-i]){
            continue;
        }else{
            ans = "No";
        }
    }

    //cout << "1 = " << ans << endl;

    ll tmp = (n-1)/2;
    tmp--;
    //cout << "tmp = " << tmp << endl;
    for(ll i = 0; i <= tmp / 2; i++){
        if(s[i] == s[tmp-i]){
            continue;
        }else{
            ans = "No";
        }
    }

    //cout << "2 = " << ans << endl;

    ll tmp2 = (n+3) / 2;
    tmp2--;
    ll j = 0;
    //cout << "tmp2 = " << tmp2 << endl;
    //for(ll i = tmp2-1; i <= (n+1-tmp2)/2; i++){
    for(ll i = tmp2; i < n; i++){
        //cout << i << " " << n-1-j << endl;
        if(s[i] == s[n-1-i+tmp2]){
            continue;
        }else{
            
            //cout << s[i] << " " << s[n-1-j] << endl;
            //cout << "i = " << i << endl;
            ans = "No";
        }
        j++;
    }


    cout << ans << endl;
}