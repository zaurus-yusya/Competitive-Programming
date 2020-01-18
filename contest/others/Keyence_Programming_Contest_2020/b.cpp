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


int main() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>> vec(n);
    rep(i,n){
        ll x, l;
        cin >> x >> l;
        vec.at(i) = make_pair(x,l);
    }

    sort(vec.begin(), vec.end());

    vector<pair<ll,ll>> vec2(n);

    rep(i,n){
        vec2.at(i).first = vec.at(i).first - vec.at(i).second;
        vec2.at(i).second = vec.at(i).first + vec.at(i).second;
    }

    sort(vec2.begin(), vec2.end());

    cout << "----" << endl;
    rep(i,n){
        cout << vec2.at(i).first << " " << vec2.at(i).second <<endl;
    }

    cout << "----" << endl;

    vector<ll> robot(n);
    ll tmp = -1 * INF;
    ll ans4 = 0;
    rep(i,n){
        if(robot[i] == 1) continue;
        if(i == n-1){
            //cout << "ok " <<endl;
            if(vec2[i].first >= tmp){
                //cout << i << endl;
                ans4++;
            }
            continue;
        }

        if(vec2[i].second > vec2[i+1].first){
            if(vec2[i].second > vec2[i+1].second){
                robot[i] = 1;
            }else{
                robot[i+1] = 1;
                //cout << i << endl;
                ans4++;
                tmp = vec2[i].second;
            }
        }else{
            //cout << i << endl;
            ans4++;
            tmp = vec2[i].second;
        }
    }

    cout << ans4 << endl;

    vector<ll> robot2(n);
    tmp = -1 * INF;
    ll ans = 0;
    rep(i,n){
        if(i == 0) continue;

        if(tmp > vec2[i].first){
            cout << "in " << endl;
            if(vec2[i-1].second < vec2[i].second){
                tmp = vec2[i-1].second;
                cout << "i= " <<i <<endl;
                robot2[i] = 1;
            }else{
                tmp = vec2[i].second;
                cout << "i=" <<i <<endl;
                robot2[i-1] = 1;
            }
        }

    }

    cout << "---" << endl;
    rep(i,n){
        if(robot2.at(i) == 0){
            cout << i << endl;
            ans++;
        }
    }
    cout << ans << endl;
    
}
