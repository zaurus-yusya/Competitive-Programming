#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define repr(i,n) for(int i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;

//bit全探索//
//nつの電球があって、電気の付け方を全パターン出す時などに使える。

void bit_full_search(int n)
{

    //2^n回ループ
    for (int bit = 0; bit < (1<<n); ++bit) {
        cout << "{";
        for (int i = 0; i < n; ++i) {
            //if (bit & (1<<i)) {
            if(bit >> i & 1){
                cout << " " << i << " ";
            }
        }
        cout << "}" << endl;
    }
    
}

int main() {
    int n = 3;

    bit_full_search(n);

    return 0;
}

