#include <bits/stdc++.h>
using namespace std;
 
 
vector<int> ans;
vector<int> vec[200005]; 
 
 
void dfs(int v ,int p = -1){
  for(int u : vec[v]){
    if(u==p) continue;
    ans.at(u) += ans.at(v);
    dfs(u,v);
  }
  
}
 
int main() {
  int n, q;
  cin >> n;
  cin >> q;
  
  
  for (int i = 0; i < n - 1; i ++){
    int a, b;
    cin >> a;
    cin >> b;
    --a;
    --b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  
  ans.resize(n);
 
  for (int i = 0; i < q; i ++){
    int p, x;
    cin >> p;
    cin >> x;
    --p;
    
    ans[p] += x;
    
  }
 
  dfs(0);
  
  for(int i; i < n; i++){
    cout << ans[i] << endl;
  }
  
 
  
}