#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main() {
  int m, d;
  cin >> m >> d;
  int ans = 0;
  
  for(int i = 1; i < m + 1; i ++){
    for (int j = 1; j < d + 1; j++){
      int d_10 = j / 10;
      int d_1 = j % 10;
      
      if(d_10 != 0 && d_10 >=2 && d_1 >=2){
        if(d_10 * d_1 == i){
          //cout << d_10 << " " << d_1 << " " << i << endl;
          ans += 1;
        }
      }
      
    }
  }
  cout << ans;
 
 
}