#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
ll INF = 1000000007;
using Graph = vector<vector<ll>>;

// 0 false, 1 true 
// stringの数字をint型にしてアスキーコードになったら -48する


int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> vec(n, vector<ll>(m));
    vector<vector<ll>> vec2(n, vector<ll>(m));

    rep(i,n){
        rep(j,m){
            ll a;
            cin >> a;
            vec.at(i).at(j) = a;
        }
    }

    string s;
    cin >> s;

    /*
    rep(i,n){
        rep(j,m){
            cout << vec.at(i).at(j) << endl;
        }
        cout << "" << endl;
    }
    */

    rep(i,s.size()){


        //cout << "---------" << i  << s.at(i)<< endl;

        if(s.at(i) == 'U'){

            
            rep(j,m){//列
                
                rep(k,n-1){//行
                    ll count = 1;
                    
                    while(true){
                        if(k + count >= n){
                            break;
                        }else if(vec.at(k+count).at(j) == 0){
                            count++;
                        }else if(vec.at(k).at(j) == vec.at(k+count).at(j)){
                            vec.at(k).at(j) = vec.at(k).at(j) * 2;
                            vec.at(k+count).at(j) = 0;
                            break;
                        }else{
                            break;
                        }
                    }
                    
                }
            }

            vec2 = vec;
            
            rep(j,m){//列
                ll count = 0;
                rep(k,n){//行
                    if(k + count >= n){
                        vec.at(k).at(j) = 0;
                    }else{
                        while(true){
                            if(k + count >= n){
                                vec.at(k).at(j) = 0;
                                break; 
                            }else if(vec2.at(k+count).at(j) == 0){
                                count++;
                            }else{
                                vec.at(k).at(j) = vec2.at(k+count).at(j);
                                break;
                            }
                        }
                    }

                }
            }
            

        }
        
        if(s.at(i) == 'D'){
            rep(j,m){//列
                
                rep(k,n-1){//行
                    ll count = 1;
                    
                    
                    while(true){
                        if(k + count >= n){
                            break;
                        }else if(vec.at(n -1 - k - count).at(j) == 0){
                            count++;
                        }else if(vec.at(n-1-k).at(j) == vec.at(n-1-k-count).at(j)){
                            vec.at(n-1-k).at(j) *= 2;
                            vec.at(n-1-k-count).at(j) = 0;
                            break;
                        }else{
                            break;
                        }
                    }

                    
                }
            }

            vec2 = vec;
            rep(j,m){//列
                ll count = 0;
                rep(k,n){//行
                    if(k + count >= n){
                        vec.at(n-1-k).at(j) = 0;
                    }else{
                        while(true){
                            if(k + count >= n){
                                vec.at(n-1-k).at(j) = 0;
                                break; 
                            }else if(vec2.at(n-1-k-count).at(j) == 0){
                                count++;
                            }else{
                                vec.at(n-1-k).at(j) = vec2.at(n-1-k-count).at(j);
                                break;
                            }
                        }
                    }

                }
                
            } 
            
            
        }


        if(s.at(i) == 'L'){

            rep(j, n){//行
                
                rep(k , m-1){//列
                    ll count = 1;

                    while(true){
                        if(k + count >= m){
                            break;
                        }else if(vec.at(j).at(k+count) == 0){
                            count++;
                        }else if(vec.at(j).at(k) == vec.at(j).at(k+count)){
                            vec.at(j).at(k) = vec.at(j).at(k) * 2;
                            vec.at(j).at(k+count) = 0;
                            break;
                        }else{
                            break;
                        }
                    }
                    


                }
            }

            vec2 = vec;
            
            rep(j,n){//行
                ll count = 0;
                rep(k,m){//列
                    if(k + count >= m){
                        vec.at(j).at(k) = 0;
                    }else{
                        while(true){
                            if(k + count >= m){
                                vec.at(j).at(k) = 0;
                                break; 
                            }else if(vec2.at(j).at(k + count) == 0){
                                count++;
                            }else{
                                vec.at(j).at(k) = vec2.at(j).at(k+count);
                                break;
                            }
                        }
                    }
                    
                    /*
                     if(vec2.at(j).at(k + count) == 0){
                        count++;
                    }else{
                        vec.at(j).at(k) = vec2.at(j).at(k+count);
                    }
                    */
                    /*
                    if(k + count >= m){
                        vec.at(j).at(k) = 0;
                    }else if(vec.at(j).at(k) == 0){
                        count++;
                        if(k + count >= m){
                            vec.at(j).at(k) = 0;
                        }else{
                            vec.at(j).at(k) = vec.at(j).at(k+count);
                        }
                    }else{
                        vec.at(j).at(k) = vec.at(j).at(k+count);
                    }
                    */

                    /*
                    if(k + count >= m){
                        vec.at(j).at(k) = 0;
                    }else{
                        while(true){
                            if(vec.at(j).at(k+count) == 0){
                                count
                            }

                        }
                    }
                    */


                }
            }
            
            
            
        }

        
        if(s.at(i) == 'R'){
            rep(j, n){//行
                
                rep(k , m-1){//列
                    ll count = 1;
                    
                    while(true){
                        if(k + count >= m){
                            break;
                        }else if(vec.at(j).at(m-1-k-count) == 0){
                            count++;
                        }else if(vec.at(j).at(m-1-k) == vec.at(j).at(m-1-k-count)){
                            vec.at(j).at(m-1-k) = vec.at(j).at(m-1-k) * 2;
                            vec.at(j).at(m-1-k-count) = 0;
                            break;
                        }else{
                            break;
                        }
                    }
                    /*
                    if(vec.at(j).at(m-1-k) == vec.at(j).at(m-1-k-1)){
                        vec.at(j).at(m-1-k) = vec.at(j).at(m-1-k-1) * 2;
                        vec.at(j).at(m-1-k-1) = 0;
                    }
                    */

                }
            }

            vec2 = vec;
            
            rep(j,n){//行
                ll count = 0;
                rep(k,m){//列
                    if(k + count >= m){
                        vec.at(j).at(m-1-k) = 0;
                    }else{
                        while(true){
                            if(k + count >= m){
                                vec.at(j).at(m-1-k) = 0;
                                break; 
                            }else if(vec2.at(j).at(m-1-k-count) == 0){
                                count++;
                            }else{
                                vec.at(j).at(m-1-k) = vec2.at(j).at(m-1-k-count);
                                break;
                            }
                        }
                    }
                    


                    /*
                    if(k + count >= m){
                        vec.at(j).at(m-1-k) = 0;
                    }else if(vec.at(j).at(m-1-k) == 0){
                        count ++;
                        if(k + count >= m){
                            vec.at(j).at(m-1-k) = 0;
                        }else{
                            vec.at(j).at(m-1-k) = vec.at(j).at(m-1-k-count);
                        }
                        
                    }else{
                        vec.at(j).at(m-1-k) = vec.at(j).at(m-1-k-count);
                    }
                    */
                }
            }
            
            
        }
        
        /*
        rep(i,n){
            rep(j,m){
                printf("%3d", vec.at(i).at(j));
                cout << " ";
                //cout << vec.at(i).at(j) << " ";
            }
            cout << "" << endl;
        }
        */
        

        //cout << "---------" << endl;
    }


    //cout << "---------" << endl;
    rep(i,n){
        rep(j,m){
            if(j == m-1){
                cout << vec.at(i).at(j);
            }else{
                cout << vec.at(i).at(j) << " ";
            }
        }
        cout << "" << endl;
    }

}
