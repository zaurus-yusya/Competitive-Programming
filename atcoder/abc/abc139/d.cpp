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
 
    ll ans = 0;
  	/*
    for(ll i = 1; i < n+1; i++){
        //ans += (i+1) % (n-i);
      	if(i == n){
          	ans += i % 1;
        }else{
      		ans += i % (i+1);
        }
      
        
      	cout << "ans =  " << ans << endl;
 
    }
    */
    
	ans = n*(n-1) /2;
    cout << ans << endl;
 
 
}