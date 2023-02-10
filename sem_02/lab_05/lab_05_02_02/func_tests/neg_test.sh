#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

args=$(cat "neg_0${1}_args.txt")
path=$(pwd)
count=$(find "${path}/shared" -name "${args:7}" | wc -l)

if (( count == 0 ))
then
	echo -e "NEGATIVE TEST ${1} ${GREEN}passed! ${NC}"
else
    fileInput="shared/n_${1}_in.txt" 
	file1="my_neg_0${1}_out.txt"
	../app.exe "$fileInput" > "$file1"

	rc=$?
	if (( rc != 0 ))
	then
		echo -e "NEGATIVE TEST ${1} ${GREEN}passed!${NC}"
	else
		echo -e "NEGATIVE TEST ${1} ${RED}failed!${NC}"
	fi
fi