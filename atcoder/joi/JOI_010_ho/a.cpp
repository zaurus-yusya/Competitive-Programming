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

    vector<vector<ll>> j_sum(m+1, vector<ll>(n+1));
    vector<vector<ll>> o_sum(m+1, vector<ll>(n+1));
    vector<vector<ll>> i_sum(m+1, vector<ll>(n+1));

    rep(i, m){
        rep(j, n){
            if(vec[i][j] == "J"){
                j_sum[i+1][j+1] = j_sum[i][j+1] + j_sum[i+1][j] - j_sum[i][j] + 1;
                o_sum[i+1][j+1] = o_sum[i][j+1] + o_sum[i+1][j] - o_sum[i][j];
                i_sum[i+1][j+1] = i_sum[i][j+1] + i_sum[i+1][j] - i_sum[i][j];
            }

            if(vec[i][j] == "O"){
                j_sum[i+1][j+1] = j_sum[i][j+1] + j_sum[i+1][j] - j_sum[i][j];
                o_sum[i+1][j+1] = o_sum[i][j+1] + o_sum[i+1][j] - o_sum[i][j] + 1;
                i_sum[i+1][j+1] = i_sum[i][j+1] + i_sum[i+1][j] - i_sum[i][j];
            }

            if(vec[i][j] == "I"){
                j_sum[i+1][j+1] = j_sum[i][j+1] + j_sum[i+1][j] - j_sum[i][j];
                o_sum[i+1][j+1] = o_sum[i][j+1] + o_sum[i+1][j] - o_sum[i][j];
                i_sum[i+1][j+1] = i_sum[i][j+1] + i_sum[i+1][j] - i_sum[i][j] + 1;
            }
        }
    }

    rep(i, k){
        ll a, b, c, d; cin >> a >> b >> c >> d;
        a--; b--;
        cout << j_sum[c][d] - j_sum[a][d] - j_sum[c][b] + j_sum[a][b] << " ";
        cout << o_sum[c][d] - o_sum[a][d] - o_sum[c][b] + o_sum[a][b] << " ";
        cout << i_sum[c][d] - i_sum[a][d] - i_sum[c][b] + i_sum[a][b] << endl;
    }

}