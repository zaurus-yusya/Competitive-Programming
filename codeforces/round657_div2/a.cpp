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


int main() {
    std::cout << std::fixed << std::setprecision(15);
    string X = "abacaba";
    ll t; cin >> t;
    rep(T, t){
        ll n; cin >> n; string s; cin >> s;
        //already
        ll cnt = 0;
        rep(i, n-6){
            if(s[i] == 'a'){
                //cout << i  << " start" << endl;
                bool flag = true;
                ll num = 0;
                for(ll j = i; j < i+7; j++){
                    if(s[j] != X[num]){
                        flag = false;
                    }
                    //cout << s[j] << " " << X[num] << endl;
                    num++;
                }
                if(flag){
                    //cout << i  << " true" << endl;
                    cnt++;
                }
            }
        }

        //cout << "cnt = " << cnt << endl;

        if(cnt >= 2){
            cout << "NO" << endl;
        }else if(cnt == 1){
            cout << "YES" << endl;
            rep(i, n){
                if(s[i] != '?'){
                    cout << s[i];
                }else{
                    cout << 'z';
                }
            }
            br;
        }else{
            if(cnt == 0){
                rep(i, n-6){
                    if(s[i] == 'a' || s[i] == '?'){
                        bool flag = true;
                        ll num = 0;
                        for(ll j = i; j < i + 7; j++){
                            if(s[j] == '?'){
                                //s[j] = X[num];
                                
                            }else if(s[j] != X[num]){
                                flag = false;
                            }
                            num++;
                        }

                        if(flag){
                            ll flag2 = 0;
                            if(i + 4 < n - 6){
                                ll num2 = 0;
                                for(ll k = i+4; k < i + 11; k++){
                                    if(s[k] == X[num2] || s[k] == '?'){
                                        
                                    }else{
                                        flag2++;
                                    }
                                    num2++;
                                }
                            }else{
                                flag2 = 1;
                            }
                            if(flag2 == 0){
                                ll num = 0;
                                for(ll j = i; j < i + 7; j++){
                                    if(num < 4){
                                        s[j] = 'z';
                                    }else if(s[j] == '?'){
                                        s[j] = X[num];
                                    }
                                    num++;
                                }
                                cnt++;
                                break;
                            }else{
                                ll num = 0;
                                for(ll j = i; j < i + 7; j++){
                                    if(s[j] == '?'){
                                        s[j] = X[num];
                                    }
                                    num++;
                                }
                                cnt++;
                                break;
                            }
                            
                        }
                    }
                }
            }

            if(cnt == 1){
                cout << "YES" << endl;
                rep(i, n){
                    if(s[i] != '?'){
                        cout << s[i];
                    }else{
                        cout << 'z';
                    }
                }
                br;
            }else{
                cout << "NO" << endl;
            }
            
        }

    }

}