#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << endl;
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// stringの数字をint型にしてアスキーコードになったら -48する
// 切り上げ　ceil(a)
// コンパイル　g++ -std=c++17 a.cpp

int main() {
    string n;
    cin >> n;
    ll size = n.size();
    //cout << size << endl;

    vector<ll> customer(size+1);
    vector<ll> shop(size+1);

    for(ll i = 0; i < size; i++){
        ll tmp = (ll)n.at(i) - '0';
        if(tmp >= 6){
            customer.at(i) += 1;
            shop.at(i+1) += (10-tmp);
        }else if(tmp == 5){
            if(i != size-1){
                if((ll)n.at(i+1) - '0' >= 6){
                    customer.at(i) += 1;
                    shop.at(i+1) += (10-tmp);
                }else{
                    customer.at(i+1) += tmp;
                }
            }else{
                customer.at(i+1) += tmp;
            }
        }else{
            customer.at(i+1) += tmp;
        }
    }


    
    //cout << "---" << endl;
    ll ans = 0;
    rep(i,size+1){
        
        ll tmp = 0;
        tmp = customer.at(i) - shop.at(i);
        if(tmp > 0){
            ans += tmp;
        }else{
            ans += (-1*tmp);
        }
        //cout << customer.at(i) << " " << shop.at(i) << " ans = " << ans << endl;
    }
    //cout << "---" << endl;
    


    cout << ans << endl;

}