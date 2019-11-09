#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define repr(i,n) for(int i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    string a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    ll ans = 0;
    rep(i,n){
        int count = 0;
        if(a[i] != b[i]){
            count ++;
        }
        if(b[i] != c[i]){
            count ++;
        }
        if(c[i] != a[i]){
            count ++;  
        }

        if(count == 3){
            ans += 2;
        }
        if(count == 2){
            ans += 1;
        }
    }

    cout << ans << endl;



}
