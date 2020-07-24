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
    ll t; cin >> t;
    rep(T, t){
        ll n; cin >> n;
        vector<long long> vec(n);
        for(long long i = 0; i < n; i ++){
            cin >> vec[i];
        }
        char c = 'a';
        string s = "";
        vector<string> ans(n + 1);
        for(ll i = 0; i < n+1; i++){
            c = 'a' + (i % 26);
            //cout << "i = " << i << endl;
            if(i == 0){
                if(i == 0){
                    s += c;
                }
                for(ll j = 0; j < vec[i]; j++){
                    s += c;
                }
                ans[i] = s;
                continue;
            }

            if(i < n + 1 - 2){
                ll len = max(vec[i-1], vec[i]); len = max(len, vec[i+1]);
                string tmp = "";
                //cout << "vec[i] = " << vec[i] << endl; 
                for(ll j = 0; j < vec[i-1]; j++){
                    tmp += ans[i-1][j];
                }
                //cout << "len = " << len << endl;
                //cout << "tmp = " << tmp << endl;
                //cout << "tmpsize = " << tmp.size() << endl;
                /*
                if(tmp.size()>= len){
                    ans[i] = tmp;
                    continue;
                }
                */
                //cout << len - tmp.size()<< endl;
                ll size = len - tmp.size();
                for(ll j = 0; j <= size; j++){
                    tmp += c;
                    //cout << "t = " << tmp << endl;
                }
                ans[i] = tmp;
                //cout << "tmp2 = " << tmp << endl;
                continue;
            }

            if(i == n - 1){
                ll len = max(vec[i-1], vec[i]);
                string tmp = "";
                for(ll j = 0; j < vec[i-1]; j++){
                    tmp += ans[i-1][j];
                }
                /*
                if(tmp.size() >= len){
                    ans[i] = tmp;
                    continue;
                } 
                */
                ll size = len - tmp.size() ;
                for(ll j = 0; j <= size; j++){
                    tmp += c;
                }
                ans[i] = tmp;
                continue;
            }

            if(i == n){
                string tmp;
                if(vec[i-1] == 0){
                    tmp += c;
                }
                for(ll j = 0; j < vec[i-1]; j++){
                    tmp += ans[i-1][j];
                }
                ans[i] = tmp;
                continue;
            }
            
            /*
            if(i == 0){
                for(ll j = 0; j < vec[i]; j++){
                    s += 'a';
                    //cout << "a";
                }
                s += 'b';
                cout << s << endl;
                //cout << c << endl;
                c = c + 1;
                continue;
            }
            if(i == n){
                for(ll j = 0; j < vec[i-1]; j++){
                    cout << "a";
                }
                cout << c << endl;
                continue;
            }
            for(ll j = 0; j < vec[i-1]; j++){
                cout << "a";
            }
            cout << c << endl;
            if(c == 'c'){
                c = 'b';
            }else{
                c = 'c';
            }
            */
        }

        rep(i, n+1){
            cout << ans[i] << endl;
        }


    }

}