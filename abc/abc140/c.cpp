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
    cin >> n ;
    vector<int> vec(n);
    vector<int> vec_ans(n);
 
    rep(i,n-1){
        cin >> vec.at(i);
      	//vec_ans.at(i) = -1;
    }
  
  
  
  	int through = 0;
  	for(int i = 0; i < n-1; i ++){
      if(i==0){
        vec_ans.at(0) = vec.at(0);
      }
      if(i == n-2){
        if(through == 1){
          vec_ans.at(n-2) = vec.at(n-2);
        }
        vec_ans.at(n-1) = vec.at(n-2);
        continue;
      }
      
      if(through == 1){
        through = 0;
        vec_ans.at(i) = vec.at(i);
      }
      
      if(vec.at(i) <= vec.at(i+1)){
        vec_ans.at(i+1) = vec.at(i);
      }
      if(vec.at(i) > vec.at(i+1)){
        through = 1;
      }
      
    }
  
  	ll ans = 0;
  	rep(i,n){
      //cout << "i = " << vec_ans.at(i) << endl;
      ans += vec_ans.at(i);
    }
  
  	cout << ans << endl;
 
 
}