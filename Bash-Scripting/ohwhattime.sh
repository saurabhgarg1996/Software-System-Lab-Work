#!/bin/bash
#q6
clear
s="ohwhattime.sh"
#alias ls='ls --hide="*~"'
#find . -name '*~' -delete
declare -a array
declare -a out
declare -a input
declare -i a
for entry in $(ls ) 
do
	if [ "$entry" != "$s" ] ; then
		mod=$(stat -c %y $entry)
		input=(${entry//_/ });
		input=(${input[0]})
		#echo "$input"
		#echo "Time of last modification of $entry: $(stat -c %y $entry)"
		
		array=(${mod//[: -]/ })
		a=$(echo "${array[4]}" | bc)
		if [[ ${array[5]}>34.5 ]]; then
			a=$a+1			
			#echo "$a"
		fi
		
		out=(${input}_${array[1]}_${array[2]}_${array[3]}:${a})
		#echo "$out"
		#echo "$entry     $out "
		mv $entry $out
	fi
done