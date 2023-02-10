CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla
OUTDIR = ./out/
INCDIR = ./inc/
SRCDIR = ./src/
UNITDIR = ./unit_tests/
UNITOBJECTS = $(OUTDIR)check_main.o $(OUTDIR)my_snprintf.o $(OUTDIR)check_unit_my_snprintf.o

unit_tests.exe: $(UNITOBJECTS)
	$(CC) $^ -o $@ -lcheck

$(OUTDIR)my_snprintf.o: $(SRCDIR)my_snprintf.c $(INCDIR)my_snprintf.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)check_main.o: $(UNITDIR)check_main.c $(INCDIR)my_snprintf.h
	mkdir -p out
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)check_unit_my_snprintf.o: $(UNITDIR)check_unit_my_snprintf.c $(INCDIR)my_snprintf.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

.PHONY: clean unit
	
clean:
	rm -f -r ./out
	rm -f *.exe

unit: unit_tests.exe
	./unit_tests.exe
