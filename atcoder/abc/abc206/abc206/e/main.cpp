#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;

// 0 false, 1 true 
// string number to int : -48 or - '0'
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!
// (a * b)over flow?   if(a > INF / b){ /* overflow */}

struct PrimeNumber
{
    //O(sqrt(n))
    //sosu hantei
    bool is_prime(long long n){
        for(long long i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return n != 1;
    }

    //O(sqrt(n))  isn't sorted
    //yakusu rekkyo
    vector<long long> divisor(long long n){
        vector<long long> res;
        for(long long i = 1; i * i <= n; i++){
            if(n % i == 0){
                res.push_back(i);
                if(i != n / i) res.push_back(n / i);
            }
        }
        return res;
    }

    //O(sqrt(n))
    //soinsu bunkai
    map<long long, long long> prime_factor(long long n){
        map<long long, long long> res;
        for(long long i = 2; i * i <= n; i++){
            while(n % i == 0){
                n /= i;
                res[i]++;
            }
        }
        if(n != 1) res[n] = 1;
        return res;
    }

    //O(n log log n)
    //n madeno sosu rekkyo
    vector<long long> eratosthenes(long long n){
        vector<long long> prime;
        vector<bool> is_prime(n + 1, true);
        long long p = 0;
        is_prime[0] = false; is_prime[1] = false;
        for(long long i = 2; i <= n; i++){
            if(is_prime[i]) prime.push_back(i);
            for(long long j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
        return prime;
    }
};


ll guchoku(ll l, ll r){
    ll res = 0;
    for(ll i = l; i <= r; i++){
        for(ll j = i+1; j <= r; j++){
            ll x = gcd(i, j);
            if(x != 1 && i/x != 1 && j/x != 1){
                cout << "i = " << i << " j = " << j << endl;
                res += 2;
            }
        }
    }
    return res;

}


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll l, r; cin >> l >> r;

    /*
    ll res = guchoku(l, r);
    cout << "guchoku = " << res << endl;
    */
    
    
    
    
    

    ll n = 1000010;
    ll ans = 0;

    vector<long long> prime;
    vector<bool> is_prime(n + 1, true);
    vector<ll> num(n+1);
    long long p = 0;
    is_prime[0] = false; is_prime[1] = false;


    for(ll i = 2; i <= r; i++){
        //iがはいっているとき
        if(l <= i && i <= r){
            ll cnt = 0;
            ll cntx = 0;
            //素数の時
            if(is_prime[i]){
                for(long long j = 2 * i; j <= r; j += i){
                    is_prime[j] = false;
                    if(l <= j && j <= r){
                        cnt++;
                        if(num[j] > 0){
                            cntx++;
                        }
                    }
                    num[j] += 1;
                }
                ans += cnt * (cnt-1);
                ans -= cntx * (cntx-1);
            }else{
            //素数じゃないとき
                ll x = num[i];
                for(long long j = 2 * i; j <= r; j += i){
                    is_prime[j] = false;
                    if(l <= j && j <= r){
                        cnt++;
                    }
                    num[j] += 1;
                }
                ans -= cnt * 2;
            }
        }else{
        //はいっていないとき
            ll cnt = 0;
            ll cntx = 0;
            //素数の時
            if(is_prime[i]){
                for(long long j = 2 * i; j <= r; j += i){
                    is_prime[j] = false;
                    if(l <= j && j <= r){
                        cnt++;
                        if(num[j] > 0){
                            cntx++;
                        }
                    }
                    num[j] += 1;
                }
                ans += cnt * (cnt-1);
                ans -= cntx * (cntx-1);
            }else{
            //素数じゃない時
                for(long long j = 2 * i; j <= r; j += i){
                    is_prime[j] = false;
                    if(l <= j && j <= r){
                        cnt++;
                        if(num[j] > 0){
                            cntx++;
                        }
                    }
                    num[j] += 1;
                }
                ans += cnt * (cnt-1);
                ans -= cntx * (cntx-1);
                //cout << "i = " << i << " " << cnt << " " << cntx << endl; 
            }
        }

        //cout << i <<  " " << ans << endl;


    }
    /*
    for(long long i = 2; i <= r; i++){
        //cout << "i = " << i << endl;
        if(is_prime[i]) prime.push_back(i);
        
        if(is_prime[i]){
            ll cnt = 0;
            for(long long j = 2 * i; j <= n; j += i){
                is_prime[j] = false;
                num[j] += 1;
                if(l <= j && j <= r){
                    cnt++;
                }

                if(j > r) break;
            }
            ans += cnt * (cnt-1);
            
        }else{
            //はいってるとき
            if(l <= i && i <= r){
                ll cnt = 0;
                ll x = num[i];
                for(long long j = 2 * i; j <= n; j += i){
                    is_prime[j] = false;

                    
                    if(l <= j && j <= r){
                        cnt++;
                    }
                    num[j] += 1;

                    if(j > r) break;
                }
                ans -= x * cnt * 2;
            }else{
            //はいっていないとき
                ll cnt = 0;
                ll cnt_s = 0;
                for(long long j = 2 * i; j <= n; j += i){
                    is_prime[j] = false;
                    if(l <= j && j <= r){
                        cnt++;
                        if(num[j] > 0){
                            cnt_s++;
                        }
                    }
                    num[j] += 1;

                    if(j > r) break;
                }
                ans += cnt * (cnt-1);
                ans -= cnt_s * (cnt_s-1);
            }
        }

        //cout << i <<  " " << ans << endl;

    }
    */
    
    
    /*
    rep(i, 12){
        cout << "i = " << i << " " << num[i] << endl;
    }
    */
    

    cout << ans << endl;


}