#!/bin/bash
#q.4 in bash.. $1 used for the value of the command line arg

FILENAME=$1
EXTENSION=${FILENAME##*.}
#echo $EXTENSION
FILE="$HOME/myopen.cfg"
#echo $FILE
#echo $1


if [ ! -n "$FILENAME" ];then
	echo "FILENAME IS EMPTY"	
	exit 1
fi

if [ ! -e "$FILE" ];then
	echo ".cfg FILE NOT FOUND"	
	exit 2
fi
pathto="a"
declare -i flag=0

cat $FILE|(while read line 
do
	var=${line%%:*}
	#echo "$var"
	
	#echo "$pathto"
	if [ $var = $EXTENSION ]; then
		#echo "$pathto found"
		pathto=${line##*:}
		flag=flag+1
		#echo $flag
	else
	  var=${line##*.}
	fi
done 

#echo $flag
if [ $flag -eq 0 ];then
	echo "Program for the entered file extension not found"
	exit 3
fi

echo $pathto

hash "$pathto" &> /dev/null
if [ $? -eq 1 ]; then
	echo "Program doesn't exist"
	exit 4
else
	pathto="$pathto $FILENAME"
	$pathto
fi
)


	 
