#!/bin/bash

problem=$1

contest=${PWD##*/}

cp ./${problem}.cpp ./${contest}/${problem}/main.cpp

cd ./${contest}/${problem}/

#acc submit main.cpp
oj s -y -w 0 https://atcoder.jp/contests/${contest}/tasks/${contest}_${problem} ./main.cpp -l c++