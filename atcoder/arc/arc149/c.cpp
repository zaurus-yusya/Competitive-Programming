#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << '\n';
using namespace std;
const long long INF = 8e18;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << ' ';} cerr << '\n';}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << ' ';} cerr << '\n';}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;
const double PI = acos(-1);

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
// for(auto& i: mp) &&&&&&&&&&&&&

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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;

    if(n == 3){
        cout << "5 9 1" << endl;
        cout << "3 7 8" << endl;
        cout << "6 2 4" << endl;
        return 0;
    }


    PrimeNumber p;
    vector<ll> tmp = p.eratosthenes(200000);

    map<ll, ll> sosu;
    rep(i, tmp.size()){
        sosu[tmp[i]]++;
    }

    ll kumi = n;
    if(n % 2 == 1){
        kumi -= 2;
    }

    map<ll, ll> used;
    vector<pair<ll, ll>> pea;
    vector<pair<ll, ll>> spea;
    ll cnt = 0;
    if(n % 2 == 0){
        for(ll i = 1; i <= n*n; i+=2){
            for(ll j = 2; j <= n*n; j+=2){
                if(used.count(j) > 0){
                    continue;
                }else{
                    if(sosu.count(i + j) == 0){
                        used[j]++;
                        pea.push_back({i, j});
                        cnt++;
                        break;
                    }
                }
            }

            if(cnt >= kumi){
                break;
            }
        }
    }else{
        // 2つ
        // 特別な奇数：1, 特別な偶数: 8
        used[1]++;
        used[8]++;
        // 特別な奇数 1 に合う偶数
        for(ll j = 2; j <= n*n; j+=2){
            if(used.count(j) > 0){
                continue;
            }else{
                if(sosu.count(1 + j) == 0){
                    used[j]++;
                    spea.push_back({1, j});
                    break;
                }
            }
        }
        // 特別な偶数 8 に合う奇数
        for(ll j = 3; j <= n*n; j+=2){
            if(used.count(j) > 0){
                continue;
            }else{
                if(sosu.count(8 + j) == 0){
                    used[j]++;
                    spea.push_back({j, 8});
                    break;
                }
            }
        }

        for(ll i = 1; i <= n*n; i+=2){
            if(used.count(i) > 0) continue;

            for(ll j = 2; j <= n*n; j+=2){
                if(used.count(j) > 0){
                    continue;
                }else{
                    if(sosu.count(i + j) == 0){
                        used[j]++;
                        pea.push_back({i, j});
                        cnt++;
                        break;
                    }
                }
            }

            if(cnt >= kumi){
                break;
            }
        }
    }

    map<ll, ll> kisu;
    map<ll, ll> gusu;
    vector<vector<ll>> ans(n, vector<ll>(n, -1));
    if(n % 2 == 0){
        ll x = (n / 2) - 1;
        rep(j, n){
            ans[x][j] = pea[j].first;
            ans[x+1][j] = pea[j].second;
            kisu[pea[j].first]++;
            gusu[pea[j].second]++;
        }

        ll odd = 1;
        ll even = 2;
        rep(i, n){
            rep(j, n){
                if(ans[i][j] != -1) continue;
                if(i < n/2){
                    // 奇数
                    while(true){
                        if(kisu.count(odd) == 0){
                            break;
                        }else{
                            odd += 2;
                        }
                    }
                    ans[i][j] = odd;
                    kisu[odd]++;
                }else{
                    // 偶数
                    while(true){
                        if(gusu.count(even) == 0){
                            break;
                        }else{
                            even += 2;
                        }
                    }
                    ans[i][j] = even;
                    gusu[even]++;
                }
            }
        }
    }else{
        // cerr << "pea size = " << pea.size() << endl;
        // cerr << "spea size = " << spea.size() << endl;

        // speaうめ
        ans[n/2][n/2] = spea[0].first; kisu[spea[0].first]++;
        ans[n/2 + 1][n/2] = spea[0].second; gusu[spea[0].second]++;
        ans[n/2 - 1][n/2 + 1] = spea[1].first; kisu[spea[1].first]++;
        ans[n/2][n/2 + 1] = spea[1].second; gusu[spea[1].second]++;

        // peaうめ
        ll cnt = 0;
        rep(j, n){
            if(j == (n/2) || j == (n/2 + 1)){
                continue;
            }else{
                if(j < n/2){
                    ans[n/2][j] = pea[cnt].first; kisu[pea[cnt].first]++;
                    ans[n/2 + 1][j] = pea[cnt].second; gusu[pea[cnt].second]++;
                    cnt++;
                }else{
                    ans[n/2 - 1][j] = pea[cnt].first; kisu[pea[cnt].first]++;
                    ans[n/2][j] = pea[cnt].second; gusu[pea[cnt].second]++;
                    cnt++;
                }
            }
        }

        //それ以外うめ
        ll odd = 1;
        ll even = 2;
        rep(i, n){
            rep(j, n){
                if(ans[i][j] != -1) continue;
                if(i < n/2){
                    // 奇数
                    while(true){
                        if(kisu.count(odd) == 0){
                            break;
                        }else{
                            odd += 2;
                        }
                    }
                    ans[i][j] = odd;
                    kisu[odd]++;
                }else{
                    // 偶数
                    while(true){
                        if(gusu.count(even) == 0){
                            break;
                        }else{
                            even += 2;
                        }
                    }
                    ans[i][j] = even;
                    gusu[even]++;
                }
            }
        }
    }

    rep(i, n){
        rep(j, n){
            cout << ans[i][j] << " ";
        }br;
    }
    


}