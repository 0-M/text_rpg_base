# Makefile for text rpg
# created by mmarkman


CC=gcc

DBGFLAGS= -ggdb3

WARNINGS= -Wall

CFLAGS= $(WARNINGS) -ansi -pedantic \
	$(DBGFLAGS)

OBJS= user_interface.o

EXEC= main

$(EXEC): main.c user_interface.o
	$(CC) $(CFLAGS) main.c user_interface.o -o $@

user_interface.o: user_interface.h user_interface.c
	$(CC) $(CFLAGS) -c user_interface.c

clean:
	rm -f $(EXEC) $(OBJS) *.o *~ 
