#!/bin/bash

contest=$1

mkdir ${contest}

cp /Users/zaurus/workspace/Competitive-Programming/atcoder/shell/template.cpp ./${contest}/a.cpp
cp /Users/zaurus/workspace/Competitive-Programming/atcoder/shell/template.cpp ./${contest}/b.cpp
cp /Users/zaurus/workspace/Competitive-Programming/atcoder/shell/template.cpp ./${contest}/c.cpp
cp /Users/zaurus/workspace/Competitive-Programming/atcoder/shell/template.cpp ./${contest}/d.cpp
cp /Users/zaurus/workspace/Competitive-Programming/atcoder/shell/template.cpp ./${contest}/e.cpp
cp /Users/zaurus/workspace/Competitive-Programming/atcoder/shell/template.cpp ./${contest}/f.cpp
cp /Users/zaurus/workspace/Competitive-Programming/atcoder/shell/template.cpp ./${contest}/g.cpp
cp /Users/zaurus/workspace/Competitive-Programming/atcoder/shell/template.cpp ./${contest}/h.cpp

cd ${contest}

code a.cpp
code b.cpp
code c.cpp
code d.cpp
code e.cpp
code f.cpp
code g.cpp
code h.cpp
