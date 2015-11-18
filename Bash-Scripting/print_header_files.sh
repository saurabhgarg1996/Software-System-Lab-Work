#!/bin/bash

FILENAME=$1
COMMENT="//"
hashinc="#include<"
hashend=">"
declare -a arr;

if [ ! -e $1 ];then
	echo "File doesn't exist"
	exit 0
fi

var=$(mktemp)
#tr is used to tuncate spaces in a file
cat $FILENAME | tr -d " " > var 
(
declare -i flag=0
declare -a array
while read line; do
	#echo ${line:0:2}
	
	if [ "${line:0:2}" = $COMMENT ];then
		continue
	fi

	if [[ $line == *$hashinc* ]]; then
		array=(${line//// })
		line="${array[0]}"
		if [[ $line == *$hashinc* ]]; then
			if [[ $line == *$hashend* ]]; then 					
				array=(${line//[< >]/ })
				line1="${array[1]}"
				y="${line1//[^.]}"
				if [ ${#y} -le 1 ]; then 				
					echo "${array[1]}"
				fi
			fi
		fi
	fi
done < var
)



	

