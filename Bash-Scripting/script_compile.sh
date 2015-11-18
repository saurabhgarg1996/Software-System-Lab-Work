#!/bin/bash
DIR="./"
FILE=$(mktemp)
GOOD="./good.txt"
BAD="./bad.txt"
if [ -e $GOOD ]; then
	rm $GOOD
fi

if [ -e $BAD ]; then
	rm $BAD
fi
for f in $(ls $DIR)
do
EXTENSION=${f##*.}
	
	if [ $EXTENSION = "c" ]; then
		gcc $f 2>$FILE
		if [[ -s $FILE ]]; then
		echo $f>>$BAD
		else	
		echo $f>>$GOOD
		fi
	fi
done

if [[ -s $GOOD ]]; then
	:
	else
	echo "">$GOOD
fi
if [[ -s $BAD ]]; then
	:
	else	
	echo "">$BAD
fi
