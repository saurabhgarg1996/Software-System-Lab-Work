#!/bin/bash
#Bash ....
declare -i countfile=0
declare -i countdir=0
#echo $(ls -a)
for file in $(ls -a) 	
do
	if [ -f "$file" ]; then
		countfile=countfile+1
	fi
	if [ -d "$file" ]; then
		countdir=countdir+1
	fi
done
echo "$countfile"
echo "$countdir" 
