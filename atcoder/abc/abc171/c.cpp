#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

ll tmp = 1000000000000001;

vector<ll> vec;
vector<ll> vec2;

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;

    
    ll a = 26;
    for(ll i = 0; i < 11; i++){
        if(i == 0){
            vec.push_back(a);
            vec2.push_back(0);
        }else{
            vec.push_back(a + vec[i-1]);
            vec2.push_back(vec[i] - vec[i-1]);
        }
        a *= 26;
    }
    /*
    for(ll i = 0; i < 11; i++){
        cout << vec[i] << " " << endl;
    }
    
    for(ll i = 0; i < 11; i++){
        cout << vec2[i] << " " << endl;
    }
    */

    ll num = 0;
    for(ll i = 0; i < 11; i++){
        if(n <= vec[i]){
            break;
        }
        num++;
    }
    cout << "num = " << num << endl;

    ll tmp = n;
    for(ll i = num; i >= 0; i--){
        if(i == 0){

        }else{
            tmp = n - vec2[i - 1];
            cout << tmp << endl;
            tmp %= 26;

            ll tmp2 = tmp / 26;
            if(tmp2 == 0){
                cout << (char)('a' + 26 - 1) << endl;
            }else{
                cout << (char)('a' + tmp - 1) << endl;
            }

            /*
            if(tmp == 0){
                cout << (char)('a' + 26 - 1) << endl;
            }else{
                cout << (char)('a' + tmp - 1) << endl;
            }
            */
        }
    }

    cout << "tmp = " << tmp << endl;
    if(tmp == 0){
        cout << (char)('a' + 26 - 1) << endl;
    }else{
        cout << (char)('a' + tmp - 1) << endl;
    }





    /*
    while(true){
        if(n / 26 == 0 || (n / 26 == 1 && n % 26 == 0)){
            break;
        }

        ll aaa = n % 26;
        if(aaa == 0){
            cout << (char)('a' + 26 - 1) << endl;
        }else{
            cout << (char)('a' + aaa - 1) << endl;
        }
        n = n / 26;
    }

    ll tmp = n % 26;
    if(tmp == 0){
        cout << (char)('a' + 26 - 1) << endl;
    }else{
        cout << (char)('a' + tmp - 1) << endl;
    }
    */


}