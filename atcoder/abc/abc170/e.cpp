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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, q; cin >> n >> q;

    vector<ll> enzi_rate(n); //園児のレートにO(1)でアクセス用
    vector<ll> enzi_at(n);   //園児の今いる幼稚園
    multiset<ll> higher; //各幼稚園の最も高いレートの集合
    vector<multiset<ll>> youchien(200000); //幼稚園ごとにmultiset

    rep(i, n){
        ll a, b; cin >> a >> b; b--;
        enzi_rate[i] = a;
        enzi_at[i] = b;
        youchien[b].insert(a);
    }

    vector<pll> query(q);
    rep(i, q){
        ll c, d; cin >> c >> d; c--; d--;
        query[i] = {c, d};
    }


    //初期処理
    rep(i, 200000){
        if(!youchien[i].empty()){
            higher.insert(*youchien[i].rbegin());
        }
    }
    
    //クエリ処理
    rep(i, q){
        ll enzi = query[i].first;
        ll rate = enzi_rate[enzi];
        ll before = enzi_at[enzi];
        ll next = query[i].second;
        
        //出る
        bool before_f = false;
        if(rate == *youchien[before].rbegin()){
            //higherから抜く
            higher.erase(higher.find(rate));
            before_f = true;
        }
        youchien[before].erase(youchien[before].find(rate));
        if(!youchien[before].empty() && before_f){
            //higherに入れる
            higher.insert(*youchien[before].rbegin());
        }
        //入る
        if(!youchien[next].empty() && rate > *youchien[next].rbegin()){
            higher.erase(higher.find(*youchien[next].rbegin()));
            youchien[next].insert(rate);
            higher.insert(*youchien[next].rbegin());
        }else if(youchien[next].empty()){
            youchien[next].insert(rate);
            higher.insert(*youchien[next].rbegin());
        }else{
            youchien[next].insert(rate);
        }

        enzi_at[enzi] = next;

        cout << *higher.begin() << endl;
    }

}