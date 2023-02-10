#! /bin/bash

test=${1}

../debug.exe < pos_${test}_in.txt > test_pos_${test}_out.txt
rc=$?

if cmp test_pos_${test}_out.txt pos_${test}_out.txt && [ $rc -eq 0 ]
then
    echo "pos test ${test} passed"
else
    echo "pos test ${test} failed"
fi

rm -f test_pos_${test}_out.txt