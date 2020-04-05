#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define repr(i,n) for(int i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;

int bit_full_search(int n, string s)
{

    int a;
    
    for (int bit = 0; bit < (1<<n); ++bit) {
        int ans = s[0] - '0';
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) {
                //cout << " " << i << " ";
                ans -= s[i+1]-'0';
            }else{
                ans += s[i+1]-'0';
            }
        }
        if(ans == 7){
            a = bit;
            break;
        }
    }

    return a;
    
}

int main() {
    string s;
    cin >> s;
    vector<string> vec{"+","+","+"};

    int result;
    result = bit_full_search(s.size()-1, s);

    for (int i = 0; i < s.size()-1; ++i) {
        if (result & (1<<i)) {
            vec[i] = "-";
        }
    }

    cout << s[0] << vec[0] << s[1] << vec[1] << s[2] << vec[2] << s[3] << "=7" << endl;

}

