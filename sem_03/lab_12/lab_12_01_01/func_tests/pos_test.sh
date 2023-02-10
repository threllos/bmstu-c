#! /bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'
BOLD=$(tput bold)
NORMAL=$(tput sgr0)

test=${1}

fileMyOut="shared/p_${test}_out.txt"
fileTestOut="test_p_${test}_out.txt"

../debug_static.exe $(cat "pos_${1}_args.txt")
rc=$?

if cmp "$fileMyOut" "$fileTestOut" && [ $rc -eq 0 ]
then
	echo -e "POSITIVE TEST ${BOLD}${test}${NORMAL} ${GREEN}PASSED!${NC}"
else
	echo -e "POSITIVE TEST ${BOLD}${test}${NORMAL} ${RED}FAILED!${NC}"
fi

rm "$fileTestOut"
