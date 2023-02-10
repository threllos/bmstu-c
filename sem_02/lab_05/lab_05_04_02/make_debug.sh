#!/bin/bash

gcc -std=c99 -Wall -Werror -g3 -Wpedantic -Wextra -Wvla -c --coverage product.c 
gcc -std=c99 -Wall -Werror -g3 -Wpedantic -Wextra -Wvla -c --coverage main.c
gcc -o app.exe --coverage product.o main.o