#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -c binary.c 
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -c main.c
gcc -o app.exe binary.o main.o