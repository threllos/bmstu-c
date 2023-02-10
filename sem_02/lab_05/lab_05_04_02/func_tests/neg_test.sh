#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

args=$(cat "neg_0${1}_args.txt")
key=${args:0:2}

if [ "$key" != "db" ] && [ "$key" != "sb" ] && [ "$key" != "fb" ]
then
	echo -e "NEGITIVE TEST ${1} ${GREEN}passed! ✅${NC}"
fi

if [ "$key" = "sb" ]
then
	fileInput="shared/n_${1}_in.bin"
	file1="shared/my_n_${1}_out.bin"
	cp "$fileInput" "$file1"
	../app.exe sb "$file1" > "my_neg_0${1}_out.txt"
	rc=$?
	if [ ${rc} -ne 0 ]
	then
		echo -e "NEGATIVE TEST ${1} ${GREEN}passed! ✅${NC}"
	else
		echo -e "NEGATIVE TEST ${1} ${RED}failed! ❌${NC}"
	fi
	rm shared/my_n*
	rm my_n*
fi

if [ "$key" = "fb" ]
then
	fileInput="shared/n_${1}_in.bin"
	file1="shared/my_n_${1}_out.bin"
	../app.exe fb "$fileInput" "$file1" "${args: -4}"
	rc=$?
	if [ ${rc} -ne 0 ]
	then
		echo -e "NEGATIVE TEST ${1} ${GREEN}passed! ✅${NC}"
	else
		echo -e "NEGATIVE TEST ${1} ${RED}failed! ❌${NC}"
	fi
	rm shared/my_n*
fi

if [ "$key" = "db" ]
then
	fileInput="shared/n_${1}_in.bin"
	file1="shared/my_n_${1}_out.bin"
	cp "$fileInput" "$file1"
	../app.exe db "$file1"
	rc=$?
	if [ ${rc} -ne 0 ]
	then
		echo -e "NEGATIVE TEST ${1} ${GREEN}passed! ✅${NC}"
	else
		echo -e "NEGATIVE TEST ${1} ${RED}failed! ❌${NC}"
	fi
	rm shared/my_n*
fi