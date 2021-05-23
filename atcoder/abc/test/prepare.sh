#!/bin/bash

contest=$1

mkdir ${contest}

cp template.cpp ./${contest}/a.cpp
cp template.cpp ./${contest}/b.cpp
cp template.cpp ./${contest}/c.cpp
cp template.cpp ./${contest}/d.cpp
cp template.cpp ./${contest}/e.cpp
cp template.cpp ./${contest}/f.cpp

cd ${contest}

code a.cpp
code b.cpp
code c.cpp
code d.cpp
code e.cpp
code f.cpp
