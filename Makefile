main: main.c user_interface.o
	gcc -ansi -pedantic -Wall main.c user_interface.o -o main

user_interface.o: user_interface.h user_interface.c
	gcc -g -c -ansi -pedantic -Wall user_interface.c

clean:
	rm -f main *.o *~ 
