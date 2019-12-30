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
    ll n ,m;
    cin >> n >> m;
    vector<ll> vec(n);
    rep(i,n){
        ll a;
        cin >> a;
        vec.at(i) = a;
    }

    sort(all(vec),std::greater<int>()); 

    rep(i,n){
        cout << vec.at(i) <<endl;
    }

    ll ans = 0;

    //3以下の処理
    if(n == 1){
        ans = vec.at(0) * 2;
        cout << ans << endl;
        return 0;
    }
    if(n == 2){
        if(m == 1){
            ans += vec.at(0) * 2;
            cout << ans << endl;
            return 0;
        }
        if(m == 2){
            ans += vec.at(0) * 2;
            ans += vec.at(0) + vec.at(1);
            cout << ans << endl;
            return 0;
        }
        if(m == 3){
            ans += vec.at(0) * 2;
            ans += (vec.at(0) + vec.at(1)) * 2;
            cout << ans << endl;
            return 0;
        }
        if(m == 4){
            ans += vec.at(0) * 2;
            ans += (vec.at(0) + vec.at(1)) * 2;
            ans += vec.at(1) * 2;
            cout << ans << endl;
            return 0;
        }
    }

    //3以上の処理
    ll tmp = 0;
    rep(i,n){
        if(i > (m/3) - 1){
            break;
        }else{
            ans += vec.at(i) * 4 + vec.at(i+1) * 2;
        }
        tmp = i;
    }
    if(m%3 == 0){
        cout << ans << endl;
        return 0;
    }
    if(m%3 == 1){
        ans += vec.at(tmp+1) * 2;
        cout << ans << endl;
        return 0;
    }
    if(m%3 == 2){
        ans += vec.at(tmp+1) * 2;
        ans += vec.at(tmp+1) + vec.at(tmp + 2);
        cout << ans << endl;
        return 0;
    }

}

