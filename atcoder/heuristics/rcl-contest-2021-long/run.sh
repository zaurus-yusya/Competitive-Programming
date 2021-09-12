#!/bin/bash

IN_FILES=./A/tester/in/*.txt
let score=0
for file_path in $IN_FILES
do
    file_name=$(basename $file_path)
    echo $file_name
    ./a.out < ./A/tester/in/$file_name > ./A/tester/out/$file_name
    let tmp=$(python3 ./A/tester/judge.py ./A/tester/in/$file_name ./A/tester/out/$file_name)
    score=$((score+tmp))
    echo $tmp
done
echo $score