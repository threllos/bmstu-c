gcc -std=c99 -Wall -Werror -g3 -Wpedantic -Wextra -c --coverage student.c
gcc -std=c99 -Wall -Werror -g3 -Wpedantic -Wextra -c --coverage main.c
gcc -o app.exe --coverage student.o main.o