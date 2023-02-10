CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla
OUTDIR = ./out/
INCDIR = ./inc/
SRCDIR = ./src/
UNITDIR = ./unit_tests/
OBJECTS = $(OUTDIR)main.o $(OUTDIR)matrix.o
UNITOBJECTS = $(OUTDIR)check_main.o $(OUTDIR)matrix.o $(OUTDIR)check_unit_addition.o $(OUTDIR)check_unit_multiplication.o $(OUTDIR)check_unit_determinant.o

app.exe: $(OBJECTS)
	$(CC) $^ -o $@

unit_tests.exe: $(UNITOBJECTS)
	$(CC) $^ -o $@ -lcheck

debug.exe: CFLAGS += -g3 --coverage -ggdb
debug.exe: $(OBJECTS)
	$(CC) $^ -o $@ --coverage

$(OUTDIR)main.o: $(SRCDIR)main.c $(SRCDIR)matrix.c $(INCDIR)matrix.h
	mkdir -p out
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)matrix.o: $(SRCDIR)matrix.c $(INCDIR)matrix.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)check_main.o: $(UNITDIR)check_main.c $(INCDIR)matrix.h
	mkdir -p out
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)check_unit_addition.o: $(UNITDIR)check_unit_addition.c $(INCDIR)matrix.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)check_unit_multiplication.o: $(UNITDIR)check_unit_multiplication.c $(INCDIR)matrix.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)check_unit_determinant.o: $(UNITDIR)check_unit_determinant.c $(INCDIR)matrix.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

.PHONY: clean func unit realese
	
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

