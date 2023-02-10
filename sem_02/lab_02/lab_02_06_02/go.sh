#!/bin/sh

./compile.sh

# time_{размер массива}_{количество повторов}_{вариант}.txt

python gen.py 10 >data_10.txt
./app_0.exe <data_10.txt >>time_10_1_0.txt
./app_1.exe <data_10.txt >>time_10_1_1.txt
./app_2.exe <data_10.txt >>time_10_1_2.txt

python gen.py 100 >data_100.txt
./app_0.exe <data_100.txt >>time_100_1_0.txt
./app_1.exe <data_100.txt >>time_100_1_1.txt
./app_2.exe <data_100.txt >>time_100_1_2.txt

python gen.py 1000 >data_1000.txt
./app_0.exe <data_1000.txt >>time_1000_1_0.txt
./app_1.exe <data_1000.txt >>time_1000_1_1.txt
./app_2.exe <data_1000.txt >>time_1000_1_2.txt

python gen.py 10000 >data_10000.txt
./app_0.exe <data_10000.txt >>time_10000_1_0.txt
./app_1.exe <data_10000.txt >>time_10000_1_1.txt
./app_2.exe <data_10000.txt >>time_10000_1_2.txt

for ((i = 1; i <= 10; i++))
do
	python gen.py 10 >data_10.txt
	./app_0.exe <data_10.txt >>time_10_10_0.txt
	./app_1.exe <data_10.txt >>time_10_10_1.txt
	./app_2.exe <data_10.txt >>time_10_10_2.txt
done

for ((i = 1; i <= 10; i++))
do
	python gen.py 100 >data_100.txt
	./app_0.exe <data_100.txt >>time_100_10_0.txt
	./app_1.exe <data_100.txt >>time_100_10_1.txt
	./app_2.exe <data_100.txt >>time_100_10_2.txt
done

for ((i = 1; i <= 10; i++))
do
	python gen.py 1000 >data_1000.txt
	./app_0.exe <data_1000.txt >>time_1000_10_0.txt
	./app_1.exe <data_1000.txt >>time_1000_10_1.txt
	./app_2.exe <data_1000.txt >>time_1000_10_2.txt
done

for ((i = 1; i <= 10; i++))
do
	python gen.py 10000 >data_10000.txt
	./app_0.exe <data_10000.txt >>time_10000_10_0.txt
	./app_1.exe <data_10000.txt >>time_10000_10_1.txt
	./app_2.exe <data_10000.txt >>time_10000_10_2.txt
done

for ((i = 1; i <= 100; i++))
do
	python gen.py 10 >data_10.txt
	./app_0.exe <data_10.txt >>time_10_100_0.txt
	./app_1.exe <data_10.txt >>time_10_100_1.txt
	./app_2.exe <data_10.txt >>time_10_100_2.txt
done

for ((i = 1; i <= 100; i++))
do
	python gen.py 100 >data_100.txt
	./app_0.exe <data_100.txt >>time_100_100_0.txt
	./app_1.exe <data_100.txt >>time_100_100_1.txt
	./app_2.exe <data_100.txt >>time_100_100_2.txt
done

for ((i = 1; i <= 100; i++))
do
	python gen.py 1000 >data_1000.txt
	./app_0.exe <data_1000.txt >>time_1000_100_0.txt
	./app_1.exe <data_1000.txt >>time_1000_100_1.txt
	./app_2.exe <data_1000.txt >>time_1000_100_2.txt
done

for ((i = 1; i <= 100; i++))
do
	python gen.py 10000 >data_10000.txt
	./app_0.exe <data_10000.txt >>time_10000_100_0.txt
	./app_1.exe <data_10000.txt >>time_10000_100_1.txt
	./app_2.exe <data_10000.txt >>time_10000_100_2.txt
done

for ((i = 1; i <= 1000; i++))
do
	python gen.py 10 >data_10.txt
	./app_0.exe <data_10.txt >>time_10_1000_0.txt
	./app_1.exe <data_10.txt >>time_10_1000_1.txt
	./app_2.exe <data_10.txt >>time_10_1000_2.txt
done

for ((i = 1; i <= 1000; i++))
do
	python gen.py 100 >data_100.txt
	./app_0.exe <data_100.txt >>time_100_1000_0.txt
	./app_1.exe <data_100.txt >>time_100_1000_1.txt
	./app_2.exe <data_100.txt >>time_100_1000_2.txt
done

for ((i = 1; i <= 1000; i++))
do
	python gen.py 1000 >data_1000.txt
	./app_0.exe <data_1000.txt >>time_1000_1000_0.txt
	./app_1.exe <data_1000.txt >>time_1000_1000_1.txt
	./app_2.exe <data_1000.txt >>time_1000_1000_2.txt
done

for ((i = 1; i <= 1000; i++))
do
	python gen.py 10000 >data_10000.txt
	./app_0.exe <data_10000.txt >>time_10000_1000_0.txt
	./app_1.exe <data_10000.txt >>time_10000_1000_1.txt
	./app_2.exe <data_10000.txt >>time_10000_1000_2.txt
done

for ((i = 1; i <= 5000; i++))
do
	python gen.py 10 >data_10.txt
	./app_0.exe <data_10.txt >>time_10_5000_0.txt
	./app_1.exe <data_10.txt >>time_10_5000_1.txt
	./app_2.exe <data_10.txt >>time_10_5000_2.txt
done

for ((i = 1; i <= 5000; i++))
do
	python gen.py 100 >data_100.txt
	./app_0.exe <data_100.txt >>time_100_5000_0.txt
	./app_1.exe <data_100.txt >>time_100_5000_1.txt
	./app_2.exe <data_100.txt >>time_100_5000_2.txt
done

for ((i = 1; i <= 5000; i++))
do
	python gen.py 1000 >data_1000.txt
	./app_0.exe <data_1000.txt >>time_1000_5000_0.txt
	./app_1.exe <data_1000.txt >>time_1000_5000_1.txt
	./app_2.exe <data_1000.txt >>time_1000_5000_2.txt
done

for ((i = 1; i <= 5000; i++))
do
	python gen.py 10000 >data_10000.txt
	./app_0.exe <data_10000.txt >>time_10000_5000_0.txt
	./app_1.exe <data_10000.txt >>time_10000_5000_1.txt
	./app_2.exe <data_10000.txt >>time_10000_5000_2.txt
done

python avg.py
python total.py
python data.py
python graphic.py