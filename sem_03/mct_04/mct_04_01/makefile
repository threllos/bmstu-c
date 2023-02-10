CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla
OBJECTS = ./out/main.o ./out/queue.o
UNITOBJECTS = ./out/check_main.o ./out/queue.o ./out/check_unit_pop.o 

app.exe: $(OBJECTS)
	$(CC) $^ -o $@

unit_tests.exe: $(UNITOBJECTS)
	$(CC) $^ -o $@ -lcheck

./out/main.o: ./src/main.c ./src/queue.c ./inc/queue.h
	mkdir -p out
	$(CC) $(CFLAGS) -I"./inc/" -c $< -o $@

./out/queue.o: ./src/queue.c ./inc/queue.h
	$(CC) $(CFLAGS) -I"./inc/" -c $< -o $@

./out/check_main.o: ./unit_tests/check_main.c ./inc/queue.h
	mkdir -p out
	$(CC) $(CFLAGS) -I"./inc/" -c $< -o $@

./out/check_unit_pop.o: ./unit_tests/check_unit_pop.c ./inc/queue.h
	$(CC) $(CFLAGS) -I"./inc/" -c $< -o $@

.PHONY: clean unit realese
	
clean:
	rm -f -r ./out
	rm -f *.exe
	rm -f lastapp lastunit

release: lastapp | app.exe

unit: lastunit | unit_tests.exe
	./unit_tests.exe

lastapp:
	touch lastapp
	rm -f app.exe
	rm -f out/*
	rm -f lastunit

lastunit:
	touch lastunit
	rm -f unit_tests.exe
	rm -f out/*
	rm -f lastapp
