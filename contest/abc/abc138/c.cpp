#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<double> vec(n);
  
  for(int i = 0; i < n; i++){
    double v;
    cin >> v;
    vec.at(i) = v;
  }
  
  for(int i = 0; i < n - 1; i++){
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    double num;
    //末尾2つを足して2で割る
    num = (vec.at(vec.size() - 1) + vec.at(vec.size() - 2)) / 2;
    //末尾2つを消す
    vec.pop_back();
    vec.pop_back();
    //末尾にnumを追加
    vec.push_back(num); 
  }
  
  cout << vec.at(0) << endl;
 
}