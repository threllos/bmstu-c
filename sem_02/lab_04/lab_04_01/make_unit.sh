#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla --coverage -c my_string.c 
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla --coverage -c main.c
gcc -o app.exe --coverage my_string.o main.o

./app.exe
rc=$?
echo ""
echo "Return code = ${rc}"
echo ""
echo "GCOV info:"
gcov -f -r main.c my_string.c