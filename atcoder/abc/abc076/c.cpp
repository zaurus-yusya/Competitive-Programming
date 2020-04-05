#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
ll INF = 1000000007;
using Graph = vector<vector<ll>>;

// 0 false, 1 true 
// stringの数字をint型にしてアスキーコードになったら -48する


int main() {
    string s, t;
    cin >> s >> t;

    if(s.size() < t.size()){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    bool result = false;
    ll ans_i = 0;

    rep(i,s.size()-t.size()+1){
        bool flag = true;
        rep(j,t.size()){
            if(s.at(s.size()-i-j-1) == t.at(t.size()-j-1)){
                continue;
            }else if(s.at(s.size()-i-j-1) == '?'){
                continue;
            }else{
                flag = false;
            }
        }
        if(flag){
            result = true;
            ans_i = i;
            break;
        }
    }

    if(result){
        rep(i,t.size()){
            s.at(s.size() - ans_i - t.size() + i) = t.at(i);
        }
        rep(i,s.size()){
            if(s.at(i) == '?'){
                s.at(i) = 'a';
            }
        }
        cout << s << endl;

    }else{
        cout << "UNRESTORABLE" << endl;
    }
    
}
