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
    ll m, n;
    cin >> m >> n;
    ll k;
    cin >> k;
    vector<vector<string>> vec(m, vector<string>(n));

    rep(i, m){
        string s;
        cin >> s;
        rep(j, n){
            vec[i][j] = s[j];
        }
    }


    vector<vector<ll>> sumsum(m+1, vector<ll>(n+1));
    rep(i, m){
        rep(j, n){
            
        }
    }

    vector<vector<ll>> j_yoko(m, vector<ll>(n+1));
    vector<vector<ll>> o_yoko(m, vector<ll>(n+1));
    vector<vector<ll>> i_yoko(m, vector<ll>(n+1));

    rep(i, m){
        rep(j, n){
            if(vec[i][j] == "J"){
                j_yoko[i][j+1] = j_yoko[i][j] + 1;
            }else{
                j_yoko[i][j+1] = j_yoko[i][j];
            }
            if(vec[i][j] == "O"){
                o_yoko[i][j+1] = o_yoko[i][j] + 1;
            }else{
                o_yoko[i][j+1] = o_yoko[i][j];
            }
            if(vec[i][j] == "I"){
                i_yoko[i][j+1] = i_yoko[i][j] + 1;
            }else{
                i_yoko[i][j+1] = i_yoko[i][j];
            }
            
        }
    }

    vector<pair<ll,ll>> northwest(k);
    vector<pair<ll,ll>> southeast(k);
    rep(i,k){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; c--;
        northwest[i] = make_pair(a, b);
        southeast[i] = make_pair(c, d);
        ll j_count = 0, o_count = 0, i_count = 0;
        for(ll j = a; j <= c; j++){
            j_count += j_yoko[j][d] - j_yoko[j][b-1];
            o_count += o_yoko[j][d] - o_yoko[j][b-1];
            i_count += i_yoko[j][d] - i_yoko[j][b-1];
        }
        cout << j_count << " " << o_count << " " << i_count << endl;
    }

}