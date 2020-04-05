#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  double sum = 0;
  
  for(int i = 0; i < n; i++){
    double a;
    cin >> a;
    sum += 1 / a;
  }
 
  cout << 1 / sum << endl;
}