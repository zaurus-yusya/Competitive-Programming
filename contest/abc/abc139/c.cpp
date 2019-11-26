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
  vector<ll> vec(100000);
  
  ll ans = 0;
  ll count = 0;
 
  for(ll i = 0; i < n; i++){
    cin >> vec.at(i);
    if(i == 0) continue;
    
    if(vec.at(i-1) >= vec.at(i)){
      count++;
    }else{
      if(ans < count){
        ans = count;
        count = 0;
      }else{
        count = 0;
      }
    }
  }
  
  if(ans < count){
    ans = count;
  }
  cout << ans << endl;
 
}