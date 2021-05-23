#!/bin/bash

problem=$1

contest=${PWD##*/}

cp ./a.out ./${contest}/${problem}

oj t -d ./${contest}/${problem}/tests