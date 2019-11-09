#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define repr(i,n) for(int i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;

    ll ans = 0;

    for(int bit = 0; bit < (1<<s.size()-1); bit++){
        vector<int> S;

        ll tmp = 0;
        ll tmp2 = 0;
        tmp = s[0]-'0';
        for (int i = 0; i < s.size()-1; ++i) {
            if (bit & (1<<i)) { // i が bit に入るかどうか
                S.push_back(i);
                tmp2 += tmp;
                tmp = 0;
            }
                tmp = tmp * 10 + s[i+1]-'0';       
            
        }

        tmp2 += tmp;
        ans += tmp2;



        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < (int)S.size(); ++j){
                
            }
        }

    }

    cout << ans << endl;

}

