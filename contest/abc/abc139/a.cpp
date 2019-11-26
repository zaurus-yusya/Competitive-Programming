#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define repr(i,n) for(int i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
 
int main() {
  string s, t;
  cin >> s >> t;
  int ans = 0;
  for(int i = 0; i < 3; i ++){
    if(s.at(i) == t.at(i)){
      ans++;
    }
    
  }
 
  cout << ans << endl;
 
}