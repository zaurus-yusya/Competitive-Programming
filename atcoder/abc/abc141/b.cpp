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
 
    cin >> s ;
  
  string ans = "Yes";
 
  
  	for(int i = 0; i < s.size(); i ++){
    	if(i%2 == 0){
        	if(s.at(i) == 'L'){
              ans = "No";
              break;
            }
        }else{
          if(s.at(i) == 'R'){
            ans = "No";
              break;
          }
        }
      
    }
   
    
  
  
  cout << ans << endl;
 
 
 
 
 
}