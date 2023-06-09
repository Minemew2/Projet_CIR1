projet.exe : main.o research.o create.o
	gcc main.o research.o create.o -o projet.exe
main.o : main.c create.h research.h
	gcc -c -Wall main.c
research.o : research.c research.h create.h
	gcc -c -Wall research.c
create.o :  create.c create.h
	gcc -c -Wall create.c

clean :
	rm *.o projet.exe