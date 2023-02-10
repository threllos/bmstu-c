#!/bin/bash

count_of_neg=$(find . -name "neg_*_in.txt" | wc -l)
count_of_pos=$(find . -name "pos_*_in.txt" | wc -l)

for ((i = 1; i <= count_of_pos; i++))
do
	./pos_test.sh "$i"
done

echo ""

for ((i = 1; i <= count_of_neg; i++))
do
	./neg_test.sh "$i"
done

rm my_*