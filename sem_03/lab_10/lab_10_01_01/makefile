CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla
OUTDIR = ./out/
INCDIR = ./inc/
SRCDIR = ./src/
UNITDIR = ./unit_tests/
OBJECTS = $(OUTDIR)main.o $(OUTDIR)list.o
UNITOBJECTS = $(OUTDIR)check_main.o $(OUTDIR)list.o $(OUTDIR)check_unit_pop_front.o $(OUTDIR)check_unit_insert.o $(OUTDIR)check_unit_append.o $(OUTDIR)check_unit_sorted_insert.o $(OUTDIR)check_unit_sort.o

app.exe: $(OBJECTS)
	$(CC) $^ -o $@

unit_tests.exe: $(UNITOBJECTS)
	$(CC) $^ -o $@ -lcheck

debug.exe: CFLAGS += -g3 --coverage -ggdb
debug.exe: $(OBJECTS)
	$(CC) $^ -o $@ --coverage

$(OUTDIR)main.o: $(SRCDIR)main.c $(SRCDIR)list.c $(INCDIR)list.h
	mkdir -p out
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)list.o: $(SRCDIR)list.c $(INCDIR)list.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)check_main.o: $(UNITDIR)check_main.c $(INCDIR)list.h
	mkdir -p out
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)check_unit_pop_front.o: $(UNITDIR)check_unit_pop_front.c $(INCDIR)list.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)check_unit_insert.o: $(UNITDIR)check_unit_insert.c $(INCDIR)list.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)check_unit_append.o: $(UNITDIR)check_unit_append.c $(INCDIR)list.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)check_unit_sorted_insert.o: $(UNITDIR)check_unit_sorted_insert.c $(INCDIR)list.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)check_unit_sort.o: $(UNITDIR)check_unit_sort.c $(INCDIR)list.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

.PHONY: clean func unit release
	
clean:
	rm -f -r ./out
	rm -f *.exe
	rm -f *.gcov
	rm -f lastapp lastdebug lastunit

release: lastapp | app.exe

func: lastdebug | debug.exe
	cd func_tests && ./all_tests.sh
	@echo ""
	@echo "coverage report:"
	@echo ""
	gcov -r ./out/main.c
	gcov -r ./out/list.c

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

