#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

args=$(cat "neg_0${1}_args.txt")
key=${args:0:1}

if [ "$key" != "p" ] && [ "$key" != "s" ] && [ "$key" != "c" ]
then
	echo -e "NEGITIVE TEST ${1} ${GREEN}passed! ✅${NC}"	
fi

if [ "$key" = "s" ]
then
	fileInput="shared/n_${1}_in.bin"
	file1="shared/my_n_${1}_out.bin"
	cp "$fileInput" "$file1"
	../app.exe s "$file1"
	rc=$?
	if [ ${rc} -ne 0 ]
	then
		echo -e "NEGITIVE TEST ${1} ${GREEN}passed! ✅${NC}"
	else
		echo -e "NEGITIVE TEST ${1} ${RED}failed! ❌${NC}"
	fi
	rm shared/my_n*
fi

if [ "$key" = "p" ]
then
	if ((${1} < 10))
	then
		file1="my_neg_0${1}_out.txt"
	else
		file1="my_neg_${1}_out.txt"
	fi
	../app.exe "$args" > "$file1"
	rc=$?
	if [ ${rc} -ne 0 ]
	then
		echo -e "NEGITIVE TEST ${1} ${GREEN}passed! ✅${NC}"
	else
		echo -e "NEGITIVE TEST ${1} ${RED}failed! ❌${NC}"
	fi
fi