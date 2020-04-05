#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define repr(i,n) for(int i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    if(n % 2 == 0){
        cout << (n/2) -1 << endl;
    }else{
        cout << (n/2) << endl;
    }

    return 0;

}
