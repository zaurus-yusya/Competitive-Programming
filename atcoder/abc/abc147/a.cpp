#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
ll INF = 1000000007;
using Graph = vector<vector<ll>>;

// 0 false, 1 true 
// stringの数字をint型にしてアスキーコードになったら -48する


int main() {
    ll a1,a2,a3;
    cin >> a1 >> a2 >> a3;

    if(a1+a2+a3 >= 22){
        cout << "bust" << endl;
    }else{
        cout << "win" << endl;
    }


    


}
