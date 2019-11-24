#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
ll INF = 1000000007;

// 0 false, 1 true


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    rep(i,s.size()){
        if(s.at(i) + n > 90){
            printf("%c", s.at(i)+n-26);
        }else{
            printf("%c", s.at(i)+n);
        }
    }

    printf("\n");


}
