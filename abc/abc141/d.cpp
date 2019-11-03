#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define repr(i,n) for(int i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
 
int main() {
 
    int n, m;
    cin >> n >> m;
 
    priority_queue<int> que;
 
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        que.push(a);
    }
 
    for(int i = 0; i < m; i++){
        int tmp = que.top();
        tmp = tmp / 2;
        que.pop();
        que.push(tmp);
    }
    
    ll ans = 0;
    while (!que.empty()) {
        ans += que.top();
        que.pop();
    }
 
    cout << ans << endl;
 
    
 
}