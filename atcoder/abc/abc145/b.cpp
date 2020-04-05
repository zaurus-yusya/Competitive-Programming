#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;


int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    if(s.size() % 2 != 0){
        cout << "No" << endl;
    }else{
        rep(i,n/2){
            if(s[i] == s[i+n/2]){
                continue;
            }else{
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;

    }


}
