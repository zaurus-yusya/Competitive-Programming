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


#define ALL(x) x.begin(),x.end()
// 0 false, 1 true 
// string to int : -48
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

long long binary_search(vector<long long> vec, long long value) {
    long long left = -1;
    long long right = (long long)vec.size();
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        if(vec[mid] >= value){
            right = mid;
        }else{
            left = mid;
        }
    }
    return right;
}

int main() {
    //ソートする必要があるのじゃ…
    vector<ll> a = {1, 4, 4, 7, 7, 8, 8, 11, 13, 19};

    cout << binary_search(a, -2) << endl;
    cout << binary_search(a, 4) << endl;
    cout << binary_search(a, 5) << endl;
    cout << binary_search(a, 7) << endl;
    cout << binary_search(a, 10000) << endl;


    /*
    auto itr = a.begin();
    //イテレータを返す
    auto Iter1 = upper_bound(a.at(3), a.end(), 4);
    auto Iter2 = upper_bound(ALL(a), 6);
    auto Iter3 = upper_bound(ALL(a), 7);
    auto Iter4 = upper_bound(ALL(a), 19);
    auto Iter5 = upper_bound(ALL(a), 20);
    

    //値の表示
    cout << "----------value----------" << endl;
    cout << "Iter1 = " << *Iter1 << endl; //Iter1 = 7
    cout << "Iter2 = " << *Iter2 << endl; //Iter2 = 7
    cout << "Iter3 = " << *Iter3 << endl; //Iter3 = 8
    cout << "Iter4 = " << *Iter4 << endl; //Iter4 = 1326115891
    cout << "Iter5 = " << *Iter5 << endl; //Iter5 = 1326115891

    //先頭からの距離
    cout << "----------from----------" << endl;
    cout << "Iter1 = " << Iter1 - a.begin() << endl; //Iter1 = 3
    cout << "Iter2 = " << Iter2 - a.begin() << endl; //Iter2 = 3
    cout << "Iter3 = " << Iter3 - a.begin() << endl; //Iter3 = 5
    cout << "Iter4 = " << Iter4 - a.begin() << endl; //Iter4 = 10
    cout << "Iter5 = " << Iter5 - a.begin() << endl; //Iter5 = 10

    //末尾までの距離
    cout << "----------to----------" << endl;
    cout << "Iter1 = " << a.end() - Iter1 << endl; //Iter1 = 7
    cout << "Iter2 = " << a.end() - Iter2 << endl; //Iter2 = 7
    cout << "Iter3 = " << a.end() - Iter3 << endl; //Iter3 = 5
    cout << "Iter4 = " << a.end() - Iter4 << endl; //Iter4 = 0
    cout << "Iter5 = " << a.end() - Iter5 << endl; //Iter5 = 0

    return 0;
    */

}