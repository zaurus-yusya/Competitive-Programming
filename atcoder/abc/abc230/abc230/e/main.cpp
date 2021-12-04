#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
using namespace std;


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    ll ans = 0;

    ll left = 1;
    while(true){
        ll val = n / left;
        ll right = n / val;
        ans += val * (right - left + 1);
        left = right + 1;
        if(left > n) break;
    }
    cout << ans << endl;


    
}