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

//a^n % mod
long long modpow(long long a, long long n, long long mod){
    long long res = 1;
    while(n > 0){
        if(n & 1){
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    string s; cin >> s;
    ll count = 0;
    rep(i, s.size()){
        if(s[i] == '1'){
            count++;
        }
    }

    bool flag = true;
    if(count == 1){
        flag = false;
    }

    if(count == 0){
        rep(i, n){
            cout << 1 << endl;
        }
        return 0;
    }

    vector<ll> vecplus(n);
    vector<ll> vecmai(n);
    ll modplus = 0;
    ll modmai = 0;
    rep(i, n){
        vecplus[i] = modpow(2, n-1-i, count + 1);
        if(count - 1 != 1){
            if(flag){
                vecmai[i] = modpow(2, n-1-i, count - 1);
            } 
        }

        if(s[i] == '1'){
            modplus = (modplus + vecplus[i]) % (count+1);
            if(flag){
                modmai = (modmai + vecmai[i]) % (count-1);
            }
            
        }

    }

    ll tmp = 0;
    rep(i, n){
        ll ans = 0;
        ll tmpmodplus = modplus;
        ll tmpmodmai = modmai;


        if(s[i] == '0'){
            tmpmodplus = tmpmodplus + vecplus[i];
            ll num = tmpmodplus % (count+1);
            ans++;
            
            while(num != 0){
                ll cnt = 0;
                ll tmp = num;
                while(tmp != 0){
                    if(tmp & 1){
                        cnt++;
                    }
                    tmp = tmp >> 1;
                }
                num = num % cnt;
                ans++;
            }
        }else{

            if(flag == false){
                ans = 0;
            }else{
                tmpmodmai = tmpmodmai - vecmai[i];
                if(tmpmodmai < 0){
                    tmpmodmai += (count-1);
                }
                ll num = tmpmodmai % (count-1);
                ans++;
                while(num != 0){
                    ll cnt = 0;
                    ll tmp = num;
                    while(tmp != 0){
                        if(tmp & 1){
                            cnt++;
                        }
                        tmp = tmp >> 1;
                    }
                    num = num % cnt;
                    ans++;
                }
            }
        }

        cout << ans << endl;

    }

}