#! /bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'
BOLD=$(tput bold)
NORMAL=$(tput sgr0)

test=${1}

fileMyOut="pos_${test}_out.txt"
fileTestOut="test_pos_${test}_out.txt"

../debug.exe < pos_${test}_in.txt >> $fileTestOut
rc=$?

if cmp "$fileMyOut" "$fileTestOut" && [ $rc -eq 0 ]
then
	echo -e "POSITIVE TEST ${BOLD}${test}${NORMAL} ${GREEN}PASSED!${NC}"
else
	echo -e "POSITIVE TEST ${BOLD}${test}${NORMAL} ${RED}FAILED!${NC}"
fi

rm -f "$fileTestOut"
