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

ll h, w;
vector<vector<string>> vec(h, vector<string>(w));

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll h, w, k;
    cin >> h >> w >> k;
    vec.resize(h, vector<string>(w));

    //グリッドの読み込み
    string s;
    ll white = 0;
    rep(i,h){
        cin >> s;
        rep(j,w){
            vec.at(i).at(j) = s[j];
            if(s[j] == '1'){
                white++;
            }
        }
    }

    vector<ll> yoko(h+1);
    vector<ll> tate(w+1);

    
    rep(i,h){
        ll count = 0;
        rep(j,w){
            if(vec[i][j] == "1"){
                count++;
            }
        }
        yoko[i+1] = count;
    }

    rep(j,w){
        ll count = 0;
        rep(i,h){
            if(vec[i][j] == "1"){
                count++;
            }
        }
        tate[j+1] = count;
    }

    rep(i, h+1){
        cout << yoko[i];
    }
    cout << endl;

    rep(j, w+1){
        cout << tate[j];
    }
    cout << endl;


    cout << white << endl;


}