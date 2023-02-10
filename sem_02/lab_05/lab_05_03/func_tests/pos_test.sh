#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

args=$(cat "pos_0${1}_args.txt")
key=${args:0:1}

if [ "$key" == "s" ]
then
	fileInput="shared/p_${1}_in.bin"
	file1="shared/my_p_${1}_out.bin"
	file2="shared/p_${1}_out.bin"
	cp "$fileInput" "$file1"
	../app.exe s "$file1"
	rc=$?
	if cmp "${file1}" "${file2}" && (( rc == 0 ))
	then
		echo -e "POSITIVE TEST ${1} ${GREEN}passed! ✅${NC}"
	else
		echo -e "POSITIVE TEST ${1} ${RED}failed! ❌${NC}"
	fi
	rm shared/my_p*
fi

if [ "$key" = "p" ]
then
	fileInput="shared/p_${1}_in.bin"
	if ((${1} < 10))
	then
		file1="my_pos_0${1}_out.txt"
		file2="pos_0${1}_out.txt"	
	else
		file1="my_pos_${1}_out.txt"
		file2="pos_${1}_out.txt"	
	fi
	../app.exe p "$fileInput" > "$file1"
	rc=$?
	if (( rc != 0 ))
	then
		echo "(return code == ${rc})" && exit 1
	else
		if cmp "${file1}" "${file2}"
		then
			echo -e "POSITIVE TEST ${1} ${GREEN}passed! ✅${NC}"
		else
			echo -e "POSITIVE TEST ${1} ${RED}failed! ❌${NC}"
		fi
	fi	
fi