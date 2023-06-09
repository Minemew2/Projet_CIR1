exec: main.o create.o
	gcc main.o create.o -o exec
main.o: main.c create.h
	gcc -c -Wall main.c
create.o: create.c create.h
	gcc -c -Wall create.c