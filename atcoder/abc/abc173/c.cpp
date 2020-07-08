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
void bit_full_search(int n)
{

    //2^n回ループ
    for (int bit = 0; bit < (1<<n); ++bit) {
        cout << "{";
        for (int i = 0; i < n; ++i) {
            //if (bit & (1<<i)) {
            if(bit >> i&1){
                cout << " " << i << " ";
            }
        }
        cout << "}" << endl;
    }
    
}



int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll h, w, k; cin >> h >> w >> k;
    vector<vector<string>> vec(h, vector<string>(w));
    rep(i, h){
        string s; cin >> s;
        rep(j, w){
            vec[i][j] = s[j];
        }
    }

    

    ll ans = 0;
    vector<vector<string>> tmp(h, vector<string>(w));
    for (int bit = 0; bit < (1<<h); ++bit) {
        
        
        vector<ll> gyo;
        
        //cout << "{";
        for (int i = 0; i < h; ++i) {
            if (bit & (1<<i)) {
                //cout << " " << i << " ";
                gyo.push_back(i);
            }
        }
        //cout << "}" << endl;

        for (int bit2 = 0; bit2 < (1<<w); ++bit2) {
            vector<ll> retsu;
            tmp = vec;
            //cout << "[";
            for (int i = 0; i < w; ++i) {
                if (bit2 & (1<<i)) {
                    //cout << " " << i << " ";
                    retsu.push_back(i);
                }
            }
            //cout << "]" << endl;

            //ここ
            
            rep(i, gyo.size()){
                rep(j, w){
                    tmp[gyo[i]][j] = "r";
                }
                //cout << gyo[i] << " ";
            }

            rep(i, retsu.size()){
                rep(j, h){
                    tmp[j][retsu[i]] = "r";
                }
                //cout << retsu[i] << " ";
            }
            

            ll count = 0;
            rep(i, h){
                rep(j, w){
                    //cout << tmp[i][j] << " ";
                    if(tmp[i][j] == "#"){
                        count++;
                    }
                }
            }
            //cout << "count = " << count << endl;
            if(count == k){
                ans++;
            }

        }

        



    }

    cout << ans << endl;

}