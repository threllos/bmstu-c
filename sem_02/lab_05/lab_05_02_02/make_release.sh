#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -c variance.c 
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -c main.c
gcc -o app.exe variance.o main.o