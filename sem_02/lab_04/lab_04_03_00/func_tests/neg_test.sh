#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

if ((${1} < 10))
then
	../app.exe < "neg_0${1}_in.txt" > "my_neg_0${1}_out.txt"
else
	../app.exe < "neg_${1}_in.txt" > "my_neg_${1}_out.txt"
fi

rc=$?
if [ ${rc} -ne 0 ]
then
	echo -e "NEGATIVE TEST ${1} ${GREEN}passed!${NC}"
else
	echo -e "NEGATIVE TEST ${1} ${RED}failed!${NC}"
fi
