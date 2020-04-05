#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    ll ans = 0;
    vector<long long> A(a);
    rep(i, a){
        cin >> A[i];
    } 
    vector<long long> B(b);
    rep(i, b) cin >> B[i];
    vector<long long> C(c);
    rep(i, c) cin >> C[i];

    sort(all(A),greater<ll>());
    sort(all(B),greater<ll>());
    sort(all(C),greater<ll>());
    rep(i,x){
        ans += A[i];
    }
    rep(i,y){
        ans += B[i];
    }

    
    ll red = x-1;
    ll green = y-1;

    
    string s = "";
    rep(i, c){
        if(red == -1 && green == -1){
            continue;
        }else if(red == -1){
            s = "green";
        }else if(green == -1){
            s = "red";
        }else if(A[red] > B[green]){
            s = "green";
        }else{
            s = "red";
        }


        if(s == "red"){
            if(C[i] > A[red]){
                ans -= A[red];
                ans += C[i];
                red--;
            }   
        }else{
            if(C[i] > B[green]){
                ans -= B[green];
                ans += C[i];
                green--;
            }    
        }
    }
    


    cout << ans << endl;
    
}