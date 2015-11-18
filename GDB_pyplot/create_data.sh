#!/bin/bash
i=1
g++ --std=c++0x fip.cpp
while [ $i -lt 47 ] 
do
    ./a.out $i >> data.csv
    i=$[$i+1]
done


