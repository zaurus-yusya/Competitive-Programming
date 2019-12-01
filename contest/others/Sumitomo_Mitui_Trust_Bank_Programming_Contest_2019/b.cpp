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


int main() {
    int n;
    cin >> n;

    int tmp;

    tmp = n / 1.08;

    /*
    cout << tmp << endl;
    cout << tmp * 1.08 << endl;
    cout << (tmp+1) * 1.08 << endl;
    */

    if(int(tmp * 1.08) == n){
        cout << tmp << endl;
    }else if(int((tmp+1) * 1.08) == n){
        cout << tmp + 1 << endl;
    }else{
        cout << ":(" << endl;
    }
}
