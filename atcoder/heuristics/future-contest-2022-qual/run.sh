#!/bin/bash

IN_FILES=./in/*.txt
let score=0
rm ./out/score.txt
for file_path in $IN_FILES
do
    file_name=$(basename $file_path)
    echo $file_name
    ./a.out < ./in/$file_name > ./out/$file_name

    # ./a.out < ./A/tester/in/$file_name > ./A/tester/out/$file_name
    # let tmp=$(python3 ./A/tester/judge.py ./A/tester/in/$file_name ./A/tester/out/$file_name)
    # score=$((score+tmp))
    # echo $tmp
done

./out/a.out < ./out/score.txt