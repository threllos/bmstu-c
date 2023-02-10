gcc -std=c99 -Wall -Werror -g3 -Wpedantic -Wextra -c --coverage str.c
gcc -std=c99 -Wall -Werror -g3 -Wpedantic -Wextra -c --coverage main.c
gcc -o app.exe --coverage str.o main.o