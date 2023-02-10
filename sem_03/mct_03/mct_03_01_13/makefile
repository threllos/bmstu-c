CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla
OBJECTS = ./out/main.o ./out/matrix.o
UNITOBJECTS = ./out/check_main.o ./out/matrix.o ./out/check_unit_swap_columns.o 

app.exe: $(OBJECTS)
	$(CC) $^ -o $@

unit_tests.exe: $(UNITOBJECTS)
	$(CC) $^ -o $@ -lcheck

debug.exe: CFLAGS += -g3 --coverage -ggdb
debug.exe: $(OBJECTS)
	$(CC) $^ -o $@ --coverage

./out/main.o: ./src/main.c ./src/matrix.c ./inc/matrix.h
	mkdir -p out
	$(CC) $(CFLAGS) -I"./inc/" -c $< -o $@

./out/matrix.o: ./src/matrix.c ./inc/matrix.h
	$(CC) $(CFLAGS) -I"./inc/" -c $< -o $@

./out/check_main.o: ./unit_tests/check_main.c ./inc/matrix.h
	mkdir -p out
	$(CC) $(CFLAGS) -I"./inc/" -c $< -o $@

./out/check_unit_swap_columns.o: ./unit_tests/check_unit_swap_columns.c ./inc/matrix.h
	$(CC) $(CFLAGS) -I"./inc/" -c $< -o $@

.PHONY: clean func unit realese
	
clean:
	rm -f -r ./out
	rm -f *.exe
	rm -f *.gcov
	rm -f lastapp lastdebug lastunit

release: lastapp | app.exe

func: lastdebug | debug.exe
	cd func_tests && ./all_tests.sh
	gcov -r ./out/main.c
	gcov -r ./out/matrix.c

unit: lastunit | unit_tests.exe
	./unit_tests.exe

lastapp:
	touch lastapp
	rm -f app.exe
	rm -f out/*
	rm -f *.gcov
	rm -f lastdebug lastunit

lastdebug:
	touch lastdebug
	rm -f debug.exe
	rm -f out/*
	rm -f *.gcov
	rm -f lastapp lastunit

lastunit:
	touch lastunit
	rm -f unit_tests.exe
	rm -f out/*
	rm -f *.gcov
	rm -f lastapp lastdebug
