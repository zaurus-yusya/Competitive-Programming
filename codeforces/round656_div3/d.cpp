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

//return the number of ng
ll n; string s;
ll countt;

void f(ll l, ll r, ll mozi, ll cnt);
void g(ll l, ll r, ll mozi, ll cnt);

void f(ll l, ll r, ll mozi, ll cnt){
    
    if(r - l == 1){
        cout << "ok " << cnt << " " << r << " " << l << endl;
        countt++;
    }else{
        for(ll i = l; i < (l+r)/2; i++){
            if((ll)s[i] - 97 != mozi){
                cnt++;
            }
        }
        f((l+r)/2, r, mozi+1, cnt);
        g((l+r)/2, r, mozi+1, cnt);
    }
    
}
void g(ll l, ll r, ll mozi, ll cnt){
    
    if(r - l == 1){
        cout << "ok " << cnt << " " << r << " " << l << endl;
        countt++;
    }else{
        for(ll i = r-1; i >= (l+r)/2; i--){
            if((ll)s[i] - 97 != mozi){
                cnt++;
            }
        }
        f(l, (l+r)/2, mozi+1, cnt);
        g(l, (l+r)/2, mozi+1, cnt);
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    rep(T, t){
        countt = 0;
        cin >> n;
        cin >> s;
        ll ans = 0;
        f(0, n, 0, ans);
        g(0, n, 0, ans);

        cout << "count = " << countt << endl;

        /*
        vector<vector<ll>> vec(n+1, vector<ll>(26));
        rep(i, n){
            ll tmp = s[i] - 97;
            rep(j, 26){
                if(j == tmp){
                    vec[i+1][j] = vec[i][j] + 1;
                }else{
                    vec[i+1][j] = vec[i][j];
                }
            } 
        }

        ll div = n / 2;
        ll r = n, l = 0;
        ll ans = 0;
        ll mozi = 'a' - 97;
        cout << mozi << endl;
        
        ll roop_cnt = 0;
        while(true){
            if(div == 0){
                break;
            }
            ll dai = vec[r][mozi] - vec[(r - l) / 2][mozi];
            ll sho = vec[(r - l) / 2][mozi] - vec[l][mozi];

            if(dai > sho){
                ans += div - dai;
                r = (r + l) / 2;
            }
            if(dai < sho){
                ans += div - sho;
                l = (r + l) / 2;
            }
            if(dai == sho){
                ans += 
            }

            div /= 2;
            mozi++;
            roop_cnt = 1;
            
        }
        rep(i, n+1){
            rep(j, 26){
                cout << vec[i][j] << " ";
            }
            br;
        }
        */

    }

}