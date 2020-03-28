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

ll h, w, k;
vector<vector<string>> vec(h, vector<string>(w));

ll ans = INF;

void bit_full_search(ll n){
    for(ll bit = 0; bit < (1 << n); bit++){
        vector<ll> div;
        ll res = 0;

        cout << "{ ";
        for(ll i = 0; i < n; i++){
            if(1 & (bit >> i)){
                cout << i << " ";
                div.pb(i);
                res++;
            }
        }
        cout << " }" << endl;

        vector<ll> sum(div.size() + 1);
        

        rep(j,w){
            ll count = 0;
            ll tmp = 0;
            vector<ll> one(div.size() + 1);
            rep(i,h){
                if(vec[i][j] == "1"){
                    tmp++;
                }
                if(div.size() != 0 && i == div[count]){
                    //sum[count] += tmp;
                    one[count] = tmp;
                    count++;
                    tmp = 0;
                }
            }

            //sum[sum.size()-1] += tmp;
            one[count] = tmp;

            cout << "sum = " << sum[0] << endl;
            cout << "one = " << one[0] << endl;
            bool flag = false;
            rep(i,one.size()){
                if(one[i] > k){
                    res = INF;
                    break;
                }else if(sum[i] + one[i] > k){
                    flag = true;
                }
            }

            if(flag){
                res++;
                rep(i,sum.size()){
                    sum[i] = one[i];
                }
            }else{
                rep(i,sum.size()){
                    sum[i] += one[i];
                }
            }

        }

        if(ans > res){
            ans = res;
        }
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> h >> w >> k;
    vec.resize(h, vector<string>(w));

    //グリッドの読み込み
    string s;
    ll white = 0;
    rep(i,h){
        cin >> s;
        rep(j,w){
            vec.at(i).at(j) = s[j];
            if(s[j] == '1'){
                white++;
            }
        }
    }

    bit_full_search(h-1);

    cout << ans << endl;

}