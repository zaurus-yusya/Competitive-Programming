#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define repr(i,n) for(int i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
 
int main() {
  int a, b;
  cin >> a >> b;
  int ans = 1;
  int tmp = a;
  
  if(b != 1){
  while(true){
    if(a * ans - (ans-1) >= b){
      break;
    }
    ans++;
  }
  
  cout << ans << endl;
  }else{
    cout << 0 << endl;
  }
 
}