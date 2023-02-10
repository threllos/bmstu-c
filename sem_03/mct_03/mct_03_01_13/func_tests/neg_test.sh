#!/bin/bash

test=${1}

../debug.exe < neg_${test}_in.txt > test_neg_${test}_out.txt
rc=$?

if [ $rc -ne 0 ]
then
    echo "neg test ${test} passed"
else
    echo "neg test ${test} failed"
fi

rm -f test_neg_${test}_out.txt