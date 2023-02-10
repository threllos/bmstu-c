CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla
OBJECTS = ./out/main.o ./out/dynamic_array.o

app.exe: $(OBJECTS)
	$(CC) $^ -o $@

unit_tests.exe: ./out/check_main.o ./out/check_unit_count_len.o ./out/check_unit_read_array.o ./out/check_unit_key.o ./out/check_unit_mysort.o ./out/dynamic_array.o
	$(CC) $^ -lcheck -o $@

debug: CFLAGS += -g3 --coverage
debug: $(OBJECTS)
	$(CC) $^ -o debug.exe --coverage

./out/dynamic_array.o: ./src/dynamic_array.c ./inc/dynamic_array.h
	$(CC) $(CFLAGS) -c ./src/dynamic_array.c -o $@

./out/main.o: ./src/main.c ./src/dynamic_array.c ./inc/dynamic_array.h
	mkdir -p out
	$(CC) $(CFLAGS) -c ./src/main.c -o $@

./out/check_main.o: ./unit_tests/check_main.c ./inc/dynamic_array.h
	mkdir -p out
	$(CC) $(CFLAGS) -c ./unit_tests/check_main.c -o $@

./out/check_unit_count_len.o: ./unit_tests/check_unit_count_len.c ./inc/dynamic_array.h
	$(CC) $(CFLAGS) -c ./unit_tests/check_unit_count_len.c -o $@

./out/check_unit_read_array.o: ./unit_tests/check_unit_read_array.c ./inc/dynamic_array.h
	$(CC) $(CFLAGS) -c ./unit_tests/check_unit_read_array.c -o $@

./out/check_unit_key.o: ./unit_tests/check_unit_key.c ./inc/dynamic_array.h
	$(CC) $(CFLAGS) -c ./unit_tests/check_unit_key.c -o $@

./out/check_unit_mysort.o: ./unit_tests/check_unit_mysort.c ./inc/dynamic_array.h
	$(CC) $(CFLAGS) -c ./unit_tests/check_unit_mysort.c -o $@

.PHONY: clean

clean:
	rm -r ./out
	rm *.exe
	rm *.gcov

func: debug
	cd func_tests && ./all_tests.sh
	gcov -r ./out/main.c
	gcov -r ./out/dynamic_array.c

unit: unit_tests.exe
	./unit_tests.exe