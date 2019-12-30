#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << endl;
using namespace std;
ll INF = 1000000007;
using Graph = vector<vector<ll>>;

// 0 false, 1 true 
// stringの数字をint型にしてアスキーコードになったら -48する
// 切り上げ　ceil(a)

bool is_prime(const unsigned n){
    switch(n){
        case 0: // fall-through
        case 1: return false;
        case 2: // fall-through
        case 3: return true;
    } // n > 3 が保証された

    if(n%2 == 0) return false;
    if(n%3 == 0) return false;
    // 2と3の倍数でないので6の倍数ではないことが保証された

    if(n%6 != 1 && n%6 != 5) return false;
    // 6の倍数前後の数(素数かもしれない数)であることが保証された

    // 6の倍数前後の数を使って試し割りをする
    for(unsigned i=5;i*i<=n;i+=6){
        if(n%i     == 0) return false; // 6n-1
        if(n%(i+2) == 0) return false; // 6n+1
    }

    return true;
}


int main() {
    ll x;
    cin >> x;

    if(x > 99991){
        cout << 100003 << endl;
        return 0;
    }

    for(ll i = x; i <= 100000; i++){
        if(is_prime(i)){
            cout << i << endl;
            break;
        }
    }

}
