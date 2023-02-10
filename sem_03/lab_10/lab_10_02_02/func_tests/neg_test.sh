#! /bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'
BOLD=$(tput bold)
NORMAL=$(tput sgr0)

test=${1}

fileMyOut="neg_${test}_out.txt"
fileTestOut="test_neg_${test}_out.txt"

../debug.exe < neg_${test}_in.txt >> $fileTestOut
rc=$?

if [ $rc -ne 0 ]
then
	echo -e "NEGATIVE TEST ${BOLD}${test}${NORMAL} ${GREEN}PASSED!${NC}"
else
	echo "$rc"
	echo -e "NEGATIVE TEST ${BOLD}${test}${NORMAL} ${RED}FAILED!${NC}"
fi

rm -f "$fileTestOut"
