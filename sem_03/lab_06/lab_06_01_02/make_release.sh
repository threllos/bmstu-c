#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -c item.c 
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -c main.c
gcc -o app.exe item.o main.o
