#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

if ((${1} < 10))
then
	file1="my_pos_0${1}_out.txt"
	file2="pos_0${1}_out.txt"
	../app.exe < "pos_0${1}_in.txt" > "my_pos_0${1}_out.txt"
else
	file1="my_pos_${1}_out.txt"
	file2="pos_${1}_out.txt"
	../app.exe < "pos_${1}_in.txt" > "my_pos_${1}_out.txt"
fi

rc=$?
if [ ${rc} -ne 0 ]
then
	echo "(return code == ${rc})" && exit 1
else
	if cmp "${file1}" "${file2}"
	then
		echo -e "POSITIVE TEST ${1} ${GREEN}passed!${NC}"
	else
		echo -e "POSITIVE TEST ${1} ${RED}failed!${NC}"
	fi
fi
