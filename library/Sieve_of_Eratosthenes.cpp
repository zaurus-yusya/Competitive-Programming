#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << endl;
using namespace std;
ll INF = 1000000007;
using Graph = vector<vector<ll>>;

// 0 false, 1 true 
// stringの数字をint型にしてアスキーコードになったら -48する
// 切り上げ　ceil(a)

//素数判定

vector<bool> prime_number_list;

void prime_number(ll n){
    prime_number_list.resize(n+1, true);

    prime_number_list[0] = false; 
    prime_number_list[1] = false;

    for(ll i = 2; i * i <= n; i++){
        if(prime_number_list.at(i)){
            for(ll j = 2; i * j <= n; j++){
                prime_number_list[i * j] = false;
            }
        }
    }
}

int main() {

    ll x;
    cin >> x;

    //xまでの素数を求める(xは2以上)
    prime_number(x);

    //print
    rep(i, prime_number_list.size()){
        if(prime_number_list.at(i)){
            cout << i << endl;
        }
    }

}
