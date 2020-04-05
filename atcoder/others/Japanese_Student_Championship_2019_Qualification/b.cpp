#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main() {
  ll n, k;
  cin >> n >> k;
  vector<int> vec(n);
  for(int i = 0; i < n; i ++){
    cin >> vec.at(i);
  }
 
  
  ll all_count = 0;
  ll after_count = 0;
  
  for(int i; i < n; i++){
    int num = vec.at(i);
    
    for(int j = 0; j < n; j ++){
      if(num > vec.at(j)){
        if(i < j){
          after_count += 1;
          all_count += 1;
        }else{
          all_count += 1;
        }
      }
    }
 
  }
 
  
  ll tento = 0;
  ll tento_2 = 0;
  ll mod = 1000000007;
  
  ll all_count_mod = all_count % mod;
  ll after_count_mod = after_count % mod;
  ll k_mod = k % mod;
  ll k_mod_1 = (k-1) % mod;
  
  ll k_mod_2 = (k*(k-1)/2) % mod;
  
  tento = all_count * k_mod_2 % mod;
  tento_2 = after_count_mod * k_mod % mod;
  tento = (tento + tento_2) % mod;
  
  cout << tento << endl;
  
  
  
  //tento = ((all_count % mod)  * (((k % mod)*((k-1) % mod)/2)) % mod) + ((after_count % mod) * (k % mod));
  //tento = (((all_count % mod)  * ((k % mod)*((k-1) % mod) * 2) % mod) + ((after_count % mod) * (k % mod) % mod)) % mod;
 
  
 
 
 
}