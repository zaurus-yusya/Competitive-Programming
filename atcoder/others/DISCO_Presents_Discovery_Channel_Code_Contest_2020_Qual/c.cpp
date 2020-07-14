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
    ll h, w, k; cin >> h >> w >> k;
    vector<vector<string>> vec(h, vector<string>(w));
    map<ll, ll> mp;
    ll last_s = -1;
    rep(i, h){
        string s; cin >> s;
        bool flag = true;
        rep(j, w){
            vec[i][j] = s[j];
            if(vec[i][j] == "#"){
                flag = false;
            }
        }
        if(flag){
            mp[i]++;
        }else{
            last_s = i;
        }
    }

    ll num = 1;
    vector<ll> tmp;
    vector<vector<ll>> ans(h, vector<ll>(w, 0));

    rep(i, h){

        if(mp[i] == 1){
            tmp.push_back(i);
        }else{
            //printする
            bool first_flag = true;
            rep(j, w){
                if(vec[i][j] == "#"){
                    if(first_flag){
                        first_flag = false;
                    }else{
                        num++;
                    }
                }
                for(ll k = 0; k < tmp.size(); k++){
                    ans[tmp[k]][j] = num;
                }
                ans[i][j] = num;
            }
            num++;
            tmp.clear();
        }
    }

    if(last_s != h-1){
        for(ll i = last_s + 1; i < h; i++){
            rep(j, w){
                ans[i][j] = ans[last_s][j];
            }
        }
    }


    rep(i, h){
        rep(j, w){
            cout << ans[i][j] << " ";
        }
        br;
    }

}