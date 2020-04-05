#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define repr(i,n) for(int i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
 
int main() {
 
    int n, k, q;
    cin >> n >> k >> q;
 
    vector<int> vec(n);  
 
    for(int i ; i < q; i++){
        int a;
        cin >> a;
        vec.at(a-1) ++;
    }
 
    for(int i = 0; i < n; i ++){
        if(k-q+vec.at(i) > 0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
        //cout << vec.at(i) << endl;
    }
 
 
}