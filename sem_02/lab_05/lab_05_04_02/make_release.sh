#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -c product.c 
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -c main.c
gcc -o app.exe product.o main.o