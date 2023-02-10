CC = gcc
CFLAGS = -std=gnu99 -Wall -Werror -Wpedantic -Wextra -Wvla
OUTDIR = ./out/
INCDIR = ./inc/
SRCDIR = ./src/
UNITDIR = ./unit_tests/
OBJECTS = $(OUTDIR)main.o $(OUTDIR)item.o
UNITOBJECTS = $(OUTDIR)check_main.o $(OUTDIR)item.o $(OUTDIR)check_unit_sort_data.o


app.exe: $(OBJECTS)
	$(CC) $^ -o $@

unit_tests.exe: $(UNITOBJECTS)
	$(CC) $^ -o $@ -lcheck

debug.exe: CFLAGS += -g3 --coverage -ggdb
debug.exe: $(OBJECTS)
	$(CC) $^ -o $@ --coverage

$(OUTDIR)main.o: $(SRCDIR)main.c $(SRCDIR)item.c $(INCDIR)item.h
	mkdir -p out
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)item.o: $(SRCDIR)item.c $(INCDIR)item.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)check_main.o: $(UNITDIR)check_main.c $(INCDIR)item.h
	mkdir -p out
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)check_unit_sort_data.o: $(UNITDIR)check_unit_sort_data.c $(INCDIR)item.h
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
	gcov -r ./out/item.c

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
