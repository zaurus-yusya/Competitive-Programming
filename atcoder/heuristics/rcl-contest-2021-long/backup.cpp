    Action select_next_action2(int day){
        if (money < next_price) {
            //金がないならpass
            return Action::pass();
        }else{
            //これ以降に現れる場所で、次の金額以上稼げる最短のところに置く
            //ex: 1円の時、4円以上稼げるところ。4円の時、8円以上稼げるところ
            vector<vector<int>> sum_future_veges(N, vector<int>(N, 0));
            vector<vector<int>> day_future_veges(N, vector<int>(N, -1));
            int need_money = (num_machine + 1) * (num_machine + 1) * (num_machine + 1);
            for (int i = day; i < T; i++) {
                for (const Vegetable& vege : veges_start[i]) {
                    if(day_future_veges[vege.r][vege.c] >= 0) continue;

                    sum_future_veges[vege.r][vege.c] += vege.v;
                    if(sum_future_veges[vege.r][vege.c] >= need_money){
                        day_future_veges[vege.r][vege.c] = i;
                    }
                }
            }

            int min_day = 10000;
            int min_r = -1;
            int min_c = -1;
            
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < N; c++) {
                    if (has_machine[r][c]) {
                        continue;
                    }
                    if((day_future_veges[r][c] != -1) && (day_future_veges[r][c] < min_day) ){
                        min_day = day_future_veges[r][c];
                        min_r = r;
                        min_c = c;
                    }
                }
            }
            if (min_day < 10000) {
                return Action::purchase(min_r, min_c);
            } else {
                return Action::pass();
            }
        }
    }


    Action select_next_action3(int day){
        if(money < next_price || day >= 850){
            //次のマシンを買う金がない
            //次の場所で最も稼げる場所に移動する（区画の連結は考慮しない）
            int dame_r = -1, dame_c = -1, dame_v = 1000000000;//最も稼げないマシンの場所
            int ok_r = -1, ok_c = -1, ok_v = 0;//次の日最も稼げる場所
            
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < N; c++) {
                    //マシンが置かれている場所のうち最も稼げない場所を調べる
                    if(has_machine[r][c] && vege_values[r][c] < dame_v){
                        dame_r = r; dame_c = c; dame_v = vege_values[r][c];
                    }
                    //最も稼げる場所でマシンが置かれていない場所を調べる
                    if(!has_machine[r][c] && vege_values[r][c] > ok_v){
                        ok_r = r; ok_c = c; ok_v = vege_values[r][c];
                    }
                }
            }

            if(ok_v == 0) return Action::pass(); //稼げる場所がそもそも無かったらパス
            if(dame_v > ok_v) return Action::pass(); //置きっ放しの方が稼げるならパス

            //稼げない場所から稼げる場所に移動する
            return Action::move(dame_r, dame_c, ok_r, ok_c);

        }else{
            //次のマシンを買う金がある
            //マシンを買って最も稼げる場所に置く
            int ok_r = -1, ok_c = -1, ok_v = 0;
            
            //マシンが置かれていなくて一番辞書順最小の場所を調べる
            int set_r = -1, set_c = -1;
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < N; c++) {
                    //最も稼げる場所でマシンが置かれていない場所を調べる
                    if(!has_machine[r][c] && vege_values[r][c] > ok_v){
                        ok_r = r; ok_c = c; ok_v = vege_values[r][c];
                    }

                    //マシンが置かれていなくて一番辞書順最小の場所を調べる
                    if(!has_machine[r][c] && set_r == -1 && set_c == -1){
                        set_r = r; set_c = c;
                    }
                }
            }

            //マシンを置く場所が決まる時
            if(ok_v != 0){
                //cout << "purchase" << ok_r << " " << ok_c << endl;
                return Action::purchase(ok_r, ok_c);
            }else{
                if(set_r == -1 && set_c == -1){
                    return Action::pass();
                }
                else{
                    //cout << "purchase " << set_r << " " << set_c << endl;
                    return Action::purchase(set_r, set_c);
                }
            }
        }
    }

    Action select_next_action4(int day){
        if(money < next_price || day >= X_DAY){
            //金がない時、X_DAY日以降の時は買わない

            //最もコストの高いマスを返す
            Node most_earn_place = calc_most_earn_place();

            if(most_earn_place.r == -1 && most_earn_place.c == -1){
                return Action::pass(); //そもそも稼げるマスが無かった場合パス
            }

            int BEF_R = R, BEF_C = C; //移動前の位置を記憶
            R = most_earn_place.r; C = most_earn_place.c; //移動後の位置を記憶
            return Action::move(BEF_R, BEF_C, R, C);

        }else{
            //マシンを買う金がある

            //最初の1台目だけ最も稼げる場所に買う
            if(num_machine == 0){
                //最もコストの高いマスを返す
                Node most_earn_place = calc_most_earn_place();
                if(most_earn_place.r == -1 && most_earn_place.c == -1){
                    return Action::pass(); //そもそも稼げるマスが無かった場合パス
                }
                R = most_earn_place.r; C = most_earn_place.c; //購入後の位置を記憶
                return Action::purchase(R, C);
            }

            //十字架が完成している時、最も稼げる位置に買う (todo どこか隣接しているマスを買った方が良い？？)
            if(tugi >= junban.size()){
                //最もコストの高いマスを返す
                Node most_earn_place = calc_most_earn_place();
                if(most_earn_place.r == -1 && most_earn_place.c == -1){
                    return Action::pass(); //そもそも稼げるマスが無かった場合パス
                }
                R = most_earn_place.r; C = most_earn_place.c; //購入後の位置を記憶
                return Action::purchase(R, C);
            }

            if(has_machine[junban[tugi].first][junban[tugi].second]){
                //置きたかった場所に既にマシンがある時、最もコストが高いマスへ移動する
                
                //最もコストの高いマスを返す
                Node most_earn_place = calc_most_earn_place();

                if(most_earn_place.r == -1 && most_earn_place.c == -1){
                    return Action::pass(); //そもそも稼げるマスが無かった場合パス
                }

                //int BEF_R = R, BEF_C = C; //移動前の位置を記憶
                R = most_earn_place.r; C = most_earn_place.c; //購入後の位置を記憶
                //return Action::move(BEF_R, BEF_C, R, C);
                tugi++;
                return Action::purchase(R, C);
                
            }else{
                //置きたい場所にマシンが無い場合、置きたい場所を買う
                tugi++;
                return Action::purchase(junban[tugi-1].first, junban[tugi-1].second);
            }
        }
    }

    Action select_next_action4(int day){
        if(money < next_price || day >= X_DAY){
            //金がない時、X_DAY日以降の時は買わない

            //最もコストの高いマスを返す
            Node most_earn_place = calc_most_earn_place();

            if(most_earn_place.r == -1 && most_earn_place.c == -1){
                return Action::pass(); //そもそも稼げるマスが無かった場合パス
            }

            int BEF_R = R, BEF_C = C; //移動前の位置を記憶
            R = most_earn_place.r; C = most_earn_place.c; //移動後の位置を記憶
            return Action::move(BEF_R, BEF_C, R, C);

        }else{
            //マシンを買う金がある

            //最初の1台目だけ最も稼げる場所に買う
            if(num_machine == 0){
                //最もコストの高いマスを返す
                Node most_earn_place = calc_most_earn_place();
                if(most_earn_place.r == -1 && most_earn_place.c == -1){
                    return Action::pass(); //そもそも稼げるマスが無かった場合パス
                }
                R = most_earn_place.r; C = most_earn_place.c; //購入後の位置を記憶
                return Action::purchase(R, C);
            }

            //十字架が完成している時、最も稼げる位置に買う (todo どこか隣接しているマスを買った方が良い？？)
            if(tugi >= junban.size()){
                //最もコストの高いマスを返す
                Node most_earn_place = calc_most_earn_place();
                if(most_earn_place.r == -1 && most_earn_place.c == -1){
                    return Action::pass(); //そもそも稼げるマスが無かった場合パス
                }
                R = most_earn_place.r; C = most_earn_place.c; //購入後の位置を記憶
                return Action::purchase(R, C);
            }

            if(has_machine[junban[tugi].first][junban[tugi].second]){
                //置きたかった場所に既にマシンがある時、最もコストが高いマスへ移動する
                
                //最もコストの高いマスを返す
                Node most_earn_place = calc_most_earn_place();

                if(most_earn_place.r == -1 && most_earn_place.c == -1){
                    return Action::pass(); //そもそも稼げるマスが無かった場合パス
                }

                //int BEF_R = R, BEF_C = C; //移動前の位置を記憶
                R = most_earn_place.r; C = most_earn_place.c; //購入後の位置を記憶
                //return Action::move(BEF_R, BEF_C, R, C);
                tugi++;
                return Action::purchase(R, C);
                
            }else{
                //置きたい場所にマシンが無い場合、置きたい場所を買う
                tugi++;
                return Action::purchase(junban[tugi-1].first, junban[tugi-1].second);
            }
        }
    }


    Action select_next_action4(int day){
        if(money < next_price || day >= X_DAY){
            //金がない時、X_DAY日以降の時は買わない

            //最もコストの高いマスを返す
            bool f = false;
            if(has_machine[R][C]) {has_machine[R][C] = 0; f = true;} //移動予定のマスは一時的に未購入状態に
            Node most_earn_place = calc_most_earn_place();
            if(f) {has_machine[R][C] = 1;} //移動予定のマスを元に戻す

            if(most_earn_place.r == -1 && most_earn_place.c == -1){
                return Action::pass(); //そもそも稼げるマスが無かった場合パス
            }

            int BEF_R = R, BEF_C = C; //移動前の位置を記憶
            R = most_earn_place.r; C = most_earn_place.c; //移動後の位置を記憶
            return Action::move(BEF_R, BEF_C, R, C);

        }else{
            //マシンを買う金がある

            //最初の1台目だけ最も稼げる場所に買う
            if(num_machine == 0){
                //最もコストの高いマスを返す
                Node most_earn_place = calc_most_earn_place();
                if(most_earn_place.r == -1 && most_earn_place.c == -1){
                    return Action::pass(); //そもそも稼げるマスが無かった場合パス
                }
                R = most_earn_place.r; C = most_earn_place.c; //購入後の位置を記憶
                return Action::purchase(R, C);
            }

            //十字架が完成している時、最も稼げる位置に買う (todo どこか隣接しているマスを買った方が良い？？)
            if(tugi >= junban.size()){
                //隣接しているマスでコストが最も高いマスを購入
                Node most_earn_place = calc_most_earn_place2();
                
                if(most_earn_place.r == -1 && most_earn_place.c == -1){
                    //最も稼げるマスへ移動

                    //最もコストの高いマスを返す
                    bool f = false;
                    if(has_machine[R][C]) {has_machine[R][C] = 0; f = true;} //移動予定のマスは一時的に未購入状態に
                    Node most_earn_place = calc_most_earn_place();
                    if(f) {has_machine[R][C] = 1;} //移動予定のマスを元に戻す

                    if(most_earn_place.r == -1 && most_earn_place.c == -1){
                        return Action::pass(); //そもそも稼げるマスが無かった場合パス
                    }

                    int BEF_R = R, BEF_C = C; //移動前の位置を記憶
                    R = most_earn_place.r; C = most_earn_place.c; //移動後の位置を記憶
                    return Action::move(BEF_R, BEF_C, R, C);
                
                }

                return Action::purchase(most_earn_place.r, most_earn_place.c);

                //R = most_earn_place.r; C = most_earn_place.c; //購入後の位置を記憶
                //return Action::purchase(R, C);
                
            }

            if(has_machine[junban[tugi].first][junban[tugi].second]){
                //置きたかった場所に既にマシンがある時、最もコストが高いマスを購入。以後そのマスのマシンを移動するマシンとする。
                
                //最もコストの高いマスを返す
                Node most_earn_place = calc_most_earn_place();

                if(most_earn_place.r == -1 && most_earn_place.c == -1){
                    return Action::pass(); //そもそも稼げるマスが無かった場合パス
                }

                //int BEF_R = R, BEF_C = C; //移動前の位置を記憶
                R = most_earn_place.r; C = most_earn_place.c; //購入後の位置を記憶
                //return Action::move(BEF_R, BEF_C, R, C);
                tugi++;
                return Action::purchase(R, C);
                
            }else{
                //置きたい場所にマシンが無い場合、置きたい場所を買う
                tugi++;
                return Action::purchase(junban[tugi-1].first, junban[tugi-1].second);
            }

            
        }
    }