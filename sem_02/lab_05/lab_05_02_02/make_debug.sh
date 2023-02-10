#!/bin/bash

gcc -std=c99 -Wall -Werror -g3 -Wpedantic -Wextra -Wvla -c --coverage variance.c 
gcc -std=c99 -Wall -Werror -g3 -Wpedantic -Wextra -Wvla -c --coverage main.c
gcc -o app.exe --coverage variance.o main.o