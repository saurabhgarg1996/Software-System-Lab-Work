#!/bin/bash
FILE=/proc/cpuinfo
FREQ=$(mktemp)
SIZE=$(mktemp)

(grep 'cpu MHz' $FILE)>$FREQ
(grep 'address sizes' $FILE)>$SIZE
line=$(head -n 1 $FREQ) 

	var=${line##*[:  ]}
	echo $var
	

line=$(head -n 1 $SIZE)
	var=${line##*:}
	echo $var>$SIZE

line=$(head -n 1 $SIZE)
 var1=${line##*,}
 var2=${line%%,*}

echo $var2>$SIZE
line=$(head -n 1 $SIZE)
	var2=${line%%b*}
	echo $var2

echo $var1>$SIZE
line=$(head -n 1 $SIZE)
	var1=${line%%b*}
	echo $var1