#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

args=$(cat "pos_0${1}_args.txt")
key=${args:0:2}

if [ "$key" = "sb" ]
then
	fileInput="shared/p_${1}_in.bin"
	file1="shared/my_p_${1}_out.bin"
	file2="shared/p_${1}_out.bin"
	file3="my_pos_0${1}_out.txt"
	file4="pos_0${1}_out.txt"	
	cp "$fileInput" "$file1"
	../app.exe sb "$file1" > "my_pos_0${1}_out.txt"
	rc=$?
	if cmp "${file1}" "${file2}" && [ ${rc} -eq 0 ] && cmp "$file3" "$file4"
	then
		echo -e "POSITIVE TEST ${1} ${GREEN}passed! ✅${NC}"
	else
		echo -e "POSITIVE TEST ${1} ${RED}failed! ❌${NC}"
	fi
	rm shared/my_p*
	rm my_p*
fi

if [ "$key" = "fb" ]
then
	fileInput="shared/p_${1}_in.bin"
	file1="shared/my_p_${1}_out.bin"
	file2="shared/p_${1}_out.bin"
	../app.exe fb "$fileInput" "$file1" "${args: -4}"
	rc=$?
	if cmp "${file1}" "${file2}" && [ ${rc} -eq 0 ]
	then
		echo -e "POSITIVE TEST ${1} ${GREEN}passed! ✅${NC}"
	else
		echo -e "POSITIVE TEST ${1} ${RED}failed! ❌${NC}"
	fi
	rm shared/my_p*
fi

if [ "$key" = "db" ]
then
	fileInput="shared/p_${1}_in.bin"
	file1="shared/my_p_${1}_out.bin"
	file2="shared/p_${1}_out.bin"
	cp "$fileInput" "$file1"
	../app.exe db "$file1"
	rc=$?
	if cmp "${file1}" "${file2}" && [ ${rc} -eq 0 ]
	then
		echo -e "POSITIVE TEST ${1} ${GREEN}passed! ✅${NC}"
	else
		echo -e "POSITIVE TEST ${1} ${RED}failed! ❌${NC}"
	fi
	rm shared/my_p*
fi