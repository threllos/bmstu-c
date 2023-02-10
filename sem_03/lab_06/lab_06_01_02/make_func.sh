#!/bin/bash

cd func_tests
./all_tests.sh
cd ..

if [ -f ./main.gcno ]
then
    gcov -r main.c
    gcov -r item.c
fi