#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -c str.c 
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -c main.c
gcc -o app.exe str.o main.o