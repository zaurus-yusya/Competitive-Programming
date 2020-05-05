#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<char> ans;

    if(a + b + c == 0){
        cout << "No" << endl;
        return 0;
    }else if(a + b + c == 1){
        rep(i,n){
            string s;
            cin >> s;
            if(s == "AB"){
                if(a == 0 && b == 0){
                    cout << "No" << endl;
                    return 0;
                }else{
                    if(a == 1){
                        ans.push_back('B');
                    }else{
                        ans.push_back('A');
                    }
                    swap(a,b);
                }
            }else if(s == "BC"){
                if(b == 0 && c == 0){
                    cout << "No" << endl;
                    return 0;
                }else{
                    if(b == 1){
                        ans.push_back('C');
                    }else{
                        ans.push_back('B');
                    }
                    swap(b,c);
                }
            }else{
                if(a == 0 && c == 0){
                    cout << "No" << endl;
                    return 0;
                }else{
                    if(c == 1){
                        ans.push_back('A');
                    }else{
                        ans.push_back('C');
                    }
                    swap(a,c);
                }
            }
        }
    }else{
        vector<string> s(n);
        rep(i,n){
            string tmp;
            cin >> tmp;
            s[i] = tmp;
        }
        rep(i,n){
            if(s[i] == "AB"){
                if(a == 0 && b == 0){
                    cout << "No" << endl;
                    return 0;
                }else if(a == 1 && b == 1 && i != n-1){
                    if(s[i+1] == "AB"){
                        cout << "No" << endl;
                        return 0;
                    }else{
                        rep(j,2){
                            if(s[i+1][j] == 'C') continue;
                            if(s[i+1][j] == 'A'){
                                a += 1; b -= 1;
                                ans.push_back('A');
                            } 
                            if(s[i+1][j] == 'B'){
                                b += 1; a -= 1;
                                ans.push_back('B');
                            }
                        }
                    }
                }else{
                    if(a == 0){
                        a += 1; b -= 1;
                        ans.push_back('A');
                    }else if(b == 0){
                        b += 1; a -= 1;
                        ans.push_back('B');
                    }else{
                        if(a < b){
                            a += 1; b -= 1;
                            ans.push_back('A');
                        }else{
                            b += 1; a -= 1;
                            ans.push_back('B');
                        }
                    }
                }
            }else if(s[i] == "BC"){
                if(b == 0 && c == 0){
                    cout << "No" << endl;
                    return 0;
                }else if(b == 1 && c == 1 && i != n-1){
                    if(s[i+1] == "BC"){
                        cout << "No" << endl;
                        return 0;
                    }else{
                        rep(j,2){
                            if(s[i+1][j] == 'A') continue;
                            if(s[i+1][j] == 'B'){
                                b += 1; c -= 1;
                                ans.push_back('B');
                            } 
                            if(s[i+1][j] == 'C'){
                                c += 1; b -= 1;
                                ans.push_back('C');
                            }
                        }
                    }
                }else{
                    if(b == 0){
                        b += 1; c -= 1;
                        ans.push_back('B');
                    }else if(c == 0){
                        c += 1; b -= 1;
                        ans.push_back('C');
                    }else{
                        if(b < c){
                            b += 1; c -= 1;
                            ans.push_back('B');
                        }else{
                            c += 1; b -= 1;
                            ans.push_back('C');
                        }
                    }
                }
            }else{
                if(a == 0 && c == 0){
                    cout << "No" << endl;
                    return 0;
                }else if(a == 1 && c == 1 && i != n-1){
                    if(s[i+1] == "AC"){
                        cout << "No" << endl;
                        return 0;
                    }else{
                        rep(j,2){
                            if(s[i+1][j] == 'B') continue;
                            if(s[i+1][j] == 'A'){
                                a += 1; c -= 1;
                                ans.push_back('A');
                            } 
                            if(s[i+1][j] == 'C'){
                                c += 1; a -= 1;
                                ans.push_back('C');
                            }
                        }
                    }
                }else{
                    if(a == 0){
                        a += 1; c -= 1;
                        ans.push_back('A');
                    }else if(c == 0){
                        c += 1; a -= 1;
                        ans.push_back('C');
                    }else{
                        if(a < c){
                            a += 1; c -= 1;
                            ans.push_back('A');
                        }else{
                            c += 1; a -= 1;
                            ans.push_back('C');
                        }
                    }
                }

            }
        }
    }

    cout << "Yes" << endl;
    rep(i,n){
        cout << ans[i] << endl;
    }

}