#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> vec_x(n);
    vector<int> vec_y(n);

    rep(i,n){
        cin >> vec_x.at(i) >> vec_y.at(i);
    }

    int kaijou = 1;
    rep(i,n){
        kaijou = kaijou * (i+1);
    }

    int count = 0;
    for(int i = 0; i < n - 1; i ++){
        for(int j = i + 1; j < n; j ++){
            count++;
        }
    }

    int tmp = kaijou * (n-1) / count;

    double ans = 0;
    for(int i = 0; i < n - 1; i ++){
        for(int j = i + 1; j < n; j ++){
            double xxx = (vec_x.at(i) - vec_x.at(j)) * (vec_x.at(i) - vec_x.at(j));
            double yyy = (vec_y.at(i) - vec_y.at(j)) * (vec_y.at(i) - vec_y.at(j));
            ans += sqrt(xxx+yyy) * tmp;
        }
    }

    cout<<std::setprecision(20)<<ans/kaijou<<endl;

}
