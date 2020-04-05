#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
ll INF = 1000000007;

// bool 0 false, 1 true


int main() {
    string s;
    cin >> s;
    if(s == "SUN"){
        cout << 7 << endl;
    }
    if(s == "MON"){
        cout << 6 << endl;
    }
    if(s == "TUE"){
        cout << 5 << endl;
    }
    if(s == "WED"){
        cout << 4 << endl;
    }
    if(s == "THU"){
        cout << 3 << endl;
    }
    if(s == "FRI"){
        cout << 2 << endl;
    }
    if(s == "SAT"){
        cout << 1 << endl;
    }



}
