#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;

// 0 false, 1 true 
// string number to int : -48 or - '0'
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!
// (a * b)over flow?   if(a > INF / b){ /* overflow */}

map<char, ll> mozi;
map<char, ll> cant_zero;
void add_mozi(string s){
    rep(i, s.size()){
        mozi[s[i]]++;
    }
}


int main() {
    std::cout << std::fixed << std::setprecision(15);
    string s1, s2, s3; cin >> s1 >> s2 >> s3;

    add_mozi(s1);
    add_mozi(s2);
    add_mozi(s3);
    cant_zero[s1[0]]++;
    cant_zero[s2[0]]++;
    cant_zero[s3[0]]++;

    if(mozi.size() > 10){
        cout << "UNSOLVABLE" << endl; return 0;
    }

    // for(auto i: mozi){
    //     cout << i.first << " " << i.second << endl;
    // }
    // for(auto i: cant_zero){
    //     cout << i.first << " " << i.second << endl;
    // }
    // cout << mozi.size() << endl;
    // cout << POW(10, 0) << endl;

    vector<ll> num = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    do{
        //num書き換え禁止
        //配列中身
        // if(num[0] == 9 && num[1] == 5 && num[2] == 6 && num[3] == 7){
        //     for(ll i = 0; i < num.size(); i++){
        //         cout << num[i] << " ";
        //     }
        //     cout << endl;
        // }


        bool flag = true;
        ll cnt = 0;
        map<char, ll> set_num;

        for(auto i: mozi){
            char x = i.first;

            if(num[cnt] == 0 && cant_zero[x] > 0){
                flag = false; break;
            }else{
                set_num[x] = num[cnt];
            }
            cnt += 1;
        }

        if(flag){
            //文字の数値決める
            ll n1 = 0, n2 = 0, n3 = 0;

            rep(i, s1.size()){
                n1 += set_num[s1[i]] * POW(10, (s1.size() - 1 - i));
            }
            rep(i, s2.size()){
                n2 += set_num[s2[i]] * POW(10, (s2.size() - 1 - i));
            }
            rep(i, s3.size()){
                n3 += set_num[s3[i]] * POW(10, (s3.size() - 1 - i));
            }

            // cerr << "n1 = " << n1 << endl;
            // cerr << "n2 = " << n2 << endl;
            // cerr << "n3 = " << n3 << endl;
            if(n1 + n2 == n3){
                cout << n1 << "\n";
                cout << n2 << "\n";
                cout << n3 << "\n";
                return 0;
            }
        }


    }while(next_permutation(num.begin(), num.end()));

    cout << "UNSOLVABLE" << endl;

    

    // for(auto i: mozi){
    //     cout << i.first << " " << i.second << endl;
    // }








    

}