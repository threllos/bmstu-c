CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla
OUTDIR = ./out/
INCDIR = ./inc/
SRCDIR = ./src/
UNITDIR = ./unit_tests/
UNITOBJECTS = $(OUTDIR)check_main.o $(OUTDIR)check_unit_fibonacci_fill.o $(OUTDIR)check_unit_filter.o 

array.dll: $(OUTDIR)array.o
	$(CC) -shared $< -Wl,--subsystem,windows -o $@

$(OUTDIR)array.o: $(SRCDIR)array.c $(INCDIR)array.h
	mkdir -p out
	$(CC) $(CFLAGS) -I$(INCDIR) -D ARRAY_EXPORTS -c $< -o $@

unit_tests.exe: $(UNITOBJECTS) array.dll
	$(CC) $^ -lcheck -L. -larray -o $@

$(OUTDIR)check_main.o: $(UNITDIR)check_main.c $(INCDIR)array.h
	mkdir -p out
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)check_unit_fibonacci_fill.o: $(UNITDIR)check_unit_fibonacci_fill.c $(INCDIR)array.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)check_unit_filter.o: $(UNITDIR)check_unit_filter.c $(INCDIR)array.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

.PHONY: clean run test_py unit
	
clean:
	rm -f -r ./out
	rm -f *.exe
	rm -f lastapp lastunit
	rm -f *.dll
	rm -f -r ./src/__pycache__

run: lastrun | array.dll
	python $(SRCDIR)main.py

test_py:
	python $(SRCDIR)myarray.py

unit: lastunit | unit_tests.exe
	./unit_tests.exe

lastrun:
	touch lastrun
	rm -f unit_tests.exe
	rm -f out/*
	rm -f lastunit

lastunit:
	touch lastunit
	rm -f out/*
	rm -f lastrun
