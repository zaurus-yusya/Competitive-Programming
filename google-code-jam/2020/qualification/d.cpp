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
    ll T, B;
    cin >> T >> B;

    if(B != 10){
        exit(0);
    }
    
    if(B == 10){
        rep(t,T){
            vector<char> vec(10);
            for(ll i = 0; i < 10; i++){
                cout << i+1 << endl;
                char c;
                cin >> c;
                vec[i] = c;
                
            }

            for(ll i = 0; i < 10; i++){
                cout << vec[i];
            }
            cout << endl;

            string res;
            cin >> res;
            if(res == "Y"){
                cerr << "TEST" << endl;
                continue;
            }else{
                exit(0);
            } 

        }
    }

    if(B == 20){
        rep(t,T){
            vector<char> vec(20);
            vector<ll> same(20);
            for(ll i = 0; i < 10; i++){
                cout << i+1 << endl;
                char c;
                cin >> c;
                vec[i] = c;

                cout << 20-i << endl;
                cin >> c;
                vec[20-1-i] = c;

                if(vec[i] == vec[20-1-i]){
                    same[i] = 0;
                    same[20-1-i] = 0;
                }else{
                    same[i] = 1;
                    same[20-1-i] = 1;
                }
            }



        }
    }
    

    
}