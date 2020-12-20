#include <bits/stdc++.h>
#include <atcoder/all>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
using namespace atcoder;
const long long INF = 1e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b == 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cout << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cout << v[i][j] << " ";} br;}}

// 0 false, 1 true 
// string number to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// If the result in local and judge is different, USE CODETEST!!

int main() {
    //O(n)解放となります
    int n; cin >> n;

    //nが奇数なら不可能
    if(n % 2 != 0){
        cout << -1 << endl;
        return 0;
    }

    map<int, int> mp; //同じ能力の門下生の人数を記録する
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
        mp[A[i]] ++;
    }

    //同じ能力の門下生が奇数人なら不可能
    for(auto i : mp){
        if(i.second % 2 != 0){
            cout << -1 << endl;
            return 0;
        }
    }

    //可能なケース
    map<int, int> retsu;        //ある能力の門下生に割り当てる列番号
    map<int, int> count;        //ある能力の門下生が何回出てきたか記録するmap
    queue<int> que;             //再使用できる列番号を格納するqueue
    int now = 0;                //現在使用している列の数
    vector<int> res(n);         //結果を格納する配列
    for(int i = 0; i < n; i++){
        if(retsu[A[i]] == 0){
            if(que.empty()){    //再使用できる列が無かったら、新しい列を作る
                now++;
                retsu[A[i]] = now;
            }else{              //再使用できる列があればその列を割り当てる
                int tmp = que.front();
                que.pop();
                retsu[A[i]] = tmp;
            }
        }
        res[i] = retsu[A[i]];
        count[A[i]]++;
        if(count[A[i]] % 2 == 0){   //偶数人並べたらその列は再使用可能となる
            que.push(retsu[A[i]]);
            retsu[A[i]] = 0;
        }
    }

    cout << now << endl; //作った列の数
    for(int i = 0; i < n; i++){
        cout << res[i] << " ";
    }
    cout << "\n";

}