exec: main.o create.o communication.o research.o delete.o
	gcc main.o create.o communication.o research.o delete.o -o exec
main.o: main.c create.h communication.h research.h
	gcc -c -Wall main.c
create.o: create.c create.h
	gcc -c -Wall create.c
communication.o: communication.c communication.h
	gcc -c -Wall communication.c
research.o: research.c research.h
	gcc -c -Wall research.c
delete.o: delete.c delete.h
	gcc -c -Wall delete.c