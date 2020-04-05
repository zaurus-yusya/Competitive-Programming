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


int main() {
    ll n, k;
    cin >> n >> k;
    ll r, s, p;
    cin >> r >> s >> p;
    string t;
    cin >> t;

    vector<string> vec;

    ll ans = 0;
    rep(i,t.size()){
        if(i < k){
            if(t.at(i) == 'r'){
                //cout << i << endl;
                ans += p;
                vec.pb("o");
            }else if(t.at(i) == 's'){
                //cout << i << endl;
                ans += r;
                vec.pb("o");
            }else if(t.at(i) == 'p'){
                //cout << i << endl;
                ans += s;
                vec.pb("o");
            }else{
                vec.pb("*");
            }
        }else{
            if(t.at(i) == 'r'){
                if(t.at(i-k) == 'r' && vec.at(i-k) == "o"){
                    vec.pb("*");
                }else{
                    //cout << i << endl;
                    ans += p;
                    vec.pb("o");
                }
            }else if(t.at(i) == 's'){
                if(t.at(i-k) == 's' && vec.at(i-k) == "o"){
                    vec.pb("*");
                }else{
                    //cout << i << endl;
                    ans += r;
                    vec.pb("o");
                }
            }else if(t.at(i) == 'p'){
                if(t.at(i-k) == 'p' && vec.at(i-k) == "o"){
                    vec.pb("*");
                }else{
                    //cout << i << endl;
                    ans += s;
                    vec.pb("o");
                }
            }else{
                vec.pb("*");
            }
        }
    }

    cout << ans << endl;

}
