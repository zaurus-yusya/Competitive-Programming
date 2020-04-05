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

bool cmp(pair<ll,ll> a, pair<ll,ll> b){
    return a.second < b.second;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll T;
    cin >> T;

    rep(t,T){

        ll n;
        cin >> n;
        vector<pair<ll,ll>> vec(n);

        vector<tuple<ll,ll,ll>> vec2;

        rep(i,n){
            ll a, b;
            cin >> a >> b;
            vec[i] = make_pair(a,b);
            vec2.emplace_back(a,b,i);
        }

        sort(all(vec));
        sort(all(vec2));

        /*
        rep(i,n){
            cout << vec[i].first << " " << vec[i].second << endl;
        }
        */
        /*
        rep(i,n){
            cout << get<0>(vec2[i]) << " " << get<1>(vec2[i]) << " " << get<2>(vec2[i]) << endl;
        }
        */
        
        
        
        
        vector<string> ans(n);
        ll c_s = 0;
        ll c_e = 0;
        ll j_s = 0;
        ll j_e = 0;
        bool imp = false;

        cout << "Case #" << t+1 << ": ";
        rep(i,n){
            ll start = get<0>(vec2[i]);
            ll end = get<1>(vec2[i]);
            ll itr = get<2>(vec2[i]);

            if(i == 0){
                ans[itr] = "C";
                c_s = start;
                c_e = end;
                continue;
            }
            if(c_e <= start){
                ans[itr] = "C";
                c_s = start;
                c_e = end;
            }else if(j_e <= start){
                ans[itr] = "J";
                j_s = start;
                j_e = end;
            }else{
                imp = true;
                break;
            }
        }

        if(imp){
            cout << "IMPOSSIBLE" << endl;
        }else{
            rep(i,n){
                cout << ans[i];
            }
            cout << endl;
        }
        
        
    }

}