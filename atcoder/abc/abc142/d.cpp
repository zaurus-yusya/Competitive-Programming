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

long long gcd(long long a, long long b){
    if(a < b) swap(a, b);
    if(a % b == 0) return b;
    return gcd(a % b, b); 
}
long long lcm(long long a,long long b){
    return (a / gcd(a, b)) * b;
}

map<ll,ll> prime_factorization(ll n){
    map<ll, ll> res;
    ll div = 2;
    for(ll i = 2; i*i <= n; i++){
        if(n % i != 0){
            continue;
        }else{
            while(n % i == 0){
                n /= i;
                res[i]++;
            }
        }
    }
    if(n != 1){
        res[n]++;
    }

    return res;
}


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll a, b;
    cin >> a >> b;

    ll tmp = gcd(a,b);
    map<ll,ll> ans;
    //prime_factorization(a);
    //prime_factorization(b);
    ans = prime_factorization(tmp);
    
    cout << ans.size() + 1 << endl;

    /*
    ll tmp = min(a,b);

    if(tmp == 1){
        cout << 1 << endl;
        return 0;
    }

    map<ll, ll> ans;
    ans = prime_factorization(a);
    for(auto i: ans){
        cout << i.first << " " << i.second << endl;  //key
    }
    */

    
    /*
    //ll ans = 1; //1は絶対ある
    map<ll,ll> ans;
    ans[1]++;

    bool is_prime[1000001];
    //for(ll i = 0; i*i <= tmp; i++){
    for(ll i = 0; i <= 1000001; i++){
        is_prime[i] = true;
    }

    for(ll i = 2; i*i <= a; i++){
        if(is_prime[i]){
            cout << "i = " << i << endl;
            if(a % i == 0 && b % i == 0){
                ans[i]++;
            }
            for(ll j = i*2; j*j <= a; j += i){
                is_prime[j] = false;
            }
        }    
    }


    bool is_prime2[1000001];
    //for(ll i = 0; i*i <= tmp; i++){
    for(ll i = 0; i <= 1000001; i++){
        is_prime2[i] = true;
    }

    for(ll i = 2; i*i <= b; i++){
        if(is_prime2[i]){
            if(a % i == 0 && b % i == 0){
                ans[i]++;
            }
            for(ll j = i*2; j*j <= b; j += i){
                is_prime2[j] = false;
            }
        }    
    }
    

    cout << ans.size() << endl;
    */
}