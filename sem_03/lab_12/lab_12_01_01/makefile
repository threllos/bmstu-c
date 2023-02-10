# Переменные
CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla
OUTDIR = ./out/
INCDIR = ./inc/
SRCDIR = ./src/
UNITDIR = ./unit_tests/
UNITOBJECTS = $(OUTDIR)check_main.o $(OUTDIR)dynamic_array.o $(OUTDIR)check_unit_count_len.o $(OUTDIR)check_unit_mysort.o $(OUTDIR)check_unit_key.o $(OUTDIR)check_unit_read_array.o

STATICOBJECTS = $(OUTDIR)main_static.o $(OUTDIR)dynamic_array_static.o

# Исполняемые файлы
app_static.exe: $(OUTDIR)main_static.o $(OUTDIR)libarr.a
	$(CC) $^ -o $@

app_dynamic_1.exe: $(OUTDIR)main_static.o arr.dll
	$(CC) $< -L. -larr -o $@

app_dynamic_2.exe: $(SRCDIR)main_dll.c out arr.dll
	$(CC) $< -L -larr -o $@

unit_tests_static.exe: $(UNITOBJECTS)
	$(CC) $^ -o $@ -lcheck

debug_static.exe: CFLAGS += -g3 --coverage -ggdb
debug_static.exe: $(STATICOBJECTS)
	$(CC) $^ -o $@ --coverage

# Объектные файлы
$(OUTDIR)main_static.o: $(SRCDIR)main_static.c
	mkdir -p out
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)libarr.a: $(OUTDIR)dynamic_array_static.o
	ar rc $@ $<

arr.dll: $(OUTDIR)dynamic_array_dll.o
	$(CC) -shared $< -Wl,--subsystem,windows -o $@

$(OUTDIR)dynamic_array_static.o: $(SRCDIR)dynamic_array_static.c $(INCDIR)dynamic_array_static.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)dynamic_array_dll.o: $(SRCDIR)dynamic_array_dll.c $(INCDIR)dynamic_array_dll.h
	$(CC) $(CFLAGS) -I$(INCDIR) -D ARR_EXPORTS -c $< -o $@

# Модульные
$(OUTDIR)check_main.o: $(UNITDIR)check_main.c $(INCDIR)dynamic_array.h
	mkdir -p out
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)check_unit_count_len.o: $(UNITDIR)check_unit_count_len.c $(INCDIR)dynamic_array.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)check_unit_mysort.o: $(UNITDIR)check_unit_mysort.c $(INCDIR)dynamic_array.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)check_unit_key.o: $(UNITDIR)check_unit_key.c $(INCDIR)dynamic_array.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OUTDIR)check_unit_read_array.o: $(UNITDIR)check_unit_read_array.c $(INCDIR)dynamic_array.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Фоновые команды
.PHONY: clean func unit realese

# Команды запуска	
clean:
	rm -f -r ./out
	rm -f *.exe
	rm -f *.gcov
	rm -f lastapp lastdebug lastunit
	rm -f *.dll

out:
	mkdir -p out

release_static: lastapp | app_static.exe

func: lastdebug | debug_static.exe
	cd func_tests && ./all_tests.sh
	@echo ""
	@echo "coverage report:"
	@echo ""
	gcov -r ./out/main_static.c
	gcov -r ./out/dynamic_array_static.c

unit: lastunit | unit_tests.exe
	./unit_tests.exe

# Флаги
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
