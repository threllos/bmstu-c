#!/bin/bash

count_of_pos=$(find . -name "pos_*_in.txt" | wc -l)
count_of_neg=$(find . -name "neg_*_in.txt" | wc -l)

for ((i = 1; i <= count_of_neg; i++))
do
	if [ "$i" -lt 10 ]
	then
		./neg_test.sh "0$i"
	else
		./neg_test.sh "$i"
	fi
done

echo ""

for ((i = 1; i <= count_of_pos; i++))
do
	if [ "$i" -lt 10 ]
	then
		./pos_test.sh "0$i"
	else
		./pos_test.sh "$i"
	fi
done


