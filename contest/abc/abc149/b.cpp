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


int main() {
    ll a, b, k;
    cin >> a >> b >> k;

    if(k < a){
        cout << a-k << " " << b << endl;
    }else if(k > a+b){
        cout << "0 0" << endl;
    }else{
        cout << "0 " << b-(k-a) << endl;
    }


}
