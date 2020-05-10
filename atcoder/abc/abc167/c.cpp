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

ll n, m, x;
vector<ll> c(n);
vector<vector<ll>> vec(n, vector<ll>(m));
vector<ll> res(m);
ll ans = -1;


void bit_full_search(int n)
{

    //2^n回ループ
    
    
    for (int bit = 0; bit < (1<<n); ++bit) {
        //cout << "{";
        ll count = 0;
        rep(j,m){
            res[j] = 0;
        }

        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) {
                //cout << " " << i << " ";
                count += c[i];
                rep(j,m){
                    res[j] += vec[i][j];
                }
            }
        }
        //cout << "}" << endl;
        ll flag = 0;
        rep(j,m){
            if(res[j] >= x){
                continue;
            }else{
                flag = 1;
            }
        }

        if(flag == 0){
            if(ans == -1){
                ans = count;
            }else{
                ans = min(ans, count);
            }
        }

    }
    
}


int main() {
    std::cout << std::fixed << std::setprecision(15);
    
    cin >> n >> m >> x;

    c.resize(n);
    vec.resize(n, vector<ll>(m));
    res.resize(m);

    rep(i,n){
        ll tmp;
        cin >> tmp;
        c[i] = tmp;
        rep(j,m){
            ll tmp2;
            cin >> tmp2;
            vec[i][j] = tmp2;
        }
    }

    bit_full_search(n);
    cout << ans << endl;
}