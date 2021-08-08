#include <bits/stdc++.h>
using namespace std;

//計算量
//時間計算量 O(nk logn)  ※setの操作がボトルネックでlogn
//空間計算量 O(nk)
vector<int> matching(vector<vector<int>> male, vector<vector<int>> female){
    //男性の数だけペアを作る→男性起点で考える
    //理想:相思相愛のペアを抜きたい→男性の第一希望と女性の第一希望が一致するペア
    //現実:男性の第一希望に対して、女性が共に第一希望しているとは限らない。
    //相思相愛がない場合、男性たちの希望に対し、女性は最も希望順位の高い人をペアにする。貪欲法の考え方。※四角関係になっていてもどこか1つ決めれば連動して決まっていく？
    //繰り返す。男性側は、ペアが決まっていない女性のうち最も希望順位が高い人の所まで希望順位を落とす

    //男性n人、女性k人とする
    int n = male.size();
    int k = female.size();

    //maleのindexに対してペアとなるfemaleのindexを格納する配列(returnする配列)
    vector<int> match(n);

    //男性それぞれに対して次にアプローチをかける女性のindexを持っておく（初期値は第一希望: 配列0番目）
    vector<int> male_approach_index(n, 0);

    //ペアが決まった男性と女性は下記のsetで管理
    set<int> male_decided;
    set<int> female_decided;

    //ペアが決まった男性がn人になるまで繰り返す
    //while文1周につき少なくとも1ペアは決まるので最大でもn回ループ
    while(male_decided.size() < n){

        //女性がアプローチを受けている男性をsetで管理  index番目の女性がアプローチを受けている男性をsetで管理
        vector<set<int>> approach(k);
        
        for(int i = 0; i < n; i ++){ //男性を順番に見ていく
            if(male_decided.count(i)) continue;

            //ペアが決まっていない男性に関して、次にアプローチかける女性を希望順位の高い順から順番に見ていく
            for(int j = male_approach_index[i]; j < k; j++){
                if(!female_decided.count(male[i][j])){
                    approach[male[i][j]].insert(i);

                    //次回は現在の希望順位の次の女性から見る
                    male_approach_index[i] = j+1;
                    break;
                }
            }
        }

        for(int i = 0; i < k; i++){
            if(female_decided.count(i)) continue;

            //この回でアプローチを受けているか調べ、アプローチを受けていない場合は飛ばす
            if(approach[i].size() == 0){
                continue;
            }else{
                //まだペアが決まっていなくて最も希望順位の高い男性と組む
                for(int j = 0; j < male.size(); j++){
                    if(approach[i].count(female[i][j])){
                        match[female[i][j]] = i;
                        male_decided.insert(female[i][j]);
                        female_decided.insert(i);
                        break;
                    }
                }
            }
        }

    }
   
    return match;

    //・・・この方針じゃダメでした！!
    //
    //反例 
    // n = 3, k = 3のケース
    // vector<vector<int>> male = {
    //     {1, 0, 2},
    //     {1, 2, 0},
    //     {0, 1, 2}
    // };
    // vector<vector<int>> female = {
    //     {0, 1, 2},
    //     {1, 0, 2},
    //     {2, 0, 1}
    // };
    //
    //出力(男性,女性) : (0, 2), (1, 1), (2, 0) →男性0と女性0の浮気が成立してしまう
    //男性0が第一希望で女性1を選べず、次に第二希望で女性0を選べなかった所に課題ありそう
}

int main(){

    //使用例

    vector<vector<int>> male = {
        {1, 0, 2, 3},
        {1, 2, 0, 3},
        {3, 0, 1, 2}
    };
    vector<vector<int>> female = {
        {0, 1, 2},
        {1, 0, 2},
        {2, 0, 1},
        {2, 0, 1}
    };

    vector<int> result = matching(male, female);

    for(int i = 0; i < result.size(); i++){
        cout << "男性: " << i << " 女性: " << result[i] << endl; 
    }
    
}