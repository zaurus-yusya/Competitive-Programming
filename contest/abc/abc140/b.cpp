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
  
  
    vector<int> vec_a(n);
    vector<int> vec_b(n);
    vector<int> vec_c(n);
 
    rep(i,n){
      cin >> vec_a.at(i);
    }
    rep(i,n){
        cin >> vec_b.at(i);
    }
    rep(i,n){
        cin >> vec_c.at(i);
    }
  
  	int ans = 0;
    int tmp = 0;
  	rep(i,n){
      int num = vec_a.at(i) - 1;
      ans += vec_b.at(num);
      
      if(i != 0 && tmp + 1 == num){
        ans += vec_c.at(tmp);
      }
      
      
      tmp = num;
      
      
    }
 
 
 
    cout << ans << endl;
    
}