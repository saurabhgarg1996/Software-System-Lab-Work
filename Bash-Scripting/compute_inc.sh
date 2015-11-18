#!/bin/bash
#included population.csv in this directory
clear
if [ -f population\_inc.csv ];then
	rm population\_inc.csv
fi	
declare -i prev
declare -i x=1
declare -i diff
declare -a array
cat population.csv | while read line;
do 
	array=(${line//,/ })
	if [ $x -ne 1 ]; then
		diff=${array[1]}-$prev
		echo "${array[0]},$diff">>population\_inc.csv
	fi
	prev=${array[1]};
	x=x+1
done	

