#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;

// 0 false, 1 true 
// string number to int : -48 or - '0'
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!
// (a * b)over flow?   if(a > INF / b){ /* overflow */}

vector<ll> L(500010);
vector<ll> R(500010);
ll cnt = 0;

void merge(vector<ll> &A, ll left, ll mid, ll right){
  ll n1 = mid - left;
  ll n2 = right - mid;
  
  //L[0...n1], R[0...n2] を生成
  //L.assign(n1, 0);
  //R.assign(n2, 0);
  rep(i, n1){
    L[i] = A[left + i];
  }
  rep(i, n2){
    R[i] = A[mid + i];
  }
  L[n1] = INF;
  R[n2] = INF;
  ll i = 0;
  ll j = 0;
  for(ll k = left; k < right; k++){
      cnt++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else{ 
      A[k] = R[j];
      j = j + 1;
    }
  }
}


void mergeSort(vector<ll> &A, ll left, ll right){
  if(left+1 < right){
    ll mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<long long> vec(n);
    for(long long i = 0; i < n; i ++){
        cin >> vec[i];
    }

    mergeSort(vec, 0, n);
    
    rep(i, n){
        if(i == 0) cout << vec[i];
        else cout << " " << vec[i];
    }br;
    cout << cnt << endl;
    
}