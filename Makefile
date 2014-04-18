# Makefile for text rpg
# created by mmarkman


CC=gcc

DBGFLAGS= -ggdb3

WARNINGS= -Wall -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith \
        -Wcast-align -Wstrict-overflow=5 -Wwrite-strings \
        -Waggregate-return -Wcast-qual -Wswitch-default -Wswitch-enum \
        -Wconversion -Wunreachable-code -Wformat=2 -Winit-self \
        -Wuninitialized -Werror-implicit-function-declaration

INCLUDE= -I .

CFLAGS= $(WARNINGS) -std=c11 -pedantic -c \
	$(DBGFLAGS)

TESTFLAGS= $(WARNINGS) -std=c11 -pedantic \
	   $(DBGFLAGS)

LDFLAGS=

SOURCES= main.c map.c user_interface.c world.c location.c list.c

OBJS= $(SOURCES:.c=.o)

EXEC= main

TESTS= maptest locationtest

all: $(SOURCES) $(EXEC) $(TESTS)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $(INCLUDE) $(OBJS) -o $@

$(TESTS): $(@:test=.o) 
	$(CC) $(LDFLAGS) $(INCLUDE) $(TESTFLAGS) \
	$(@:test=_test.c) $(@:test=.o) -o $@

.c.o: 
	$(CC) $(CFLAGS) $(INCLUDE) $< -o $@

clean:
	rm -f $(EXEC)
	rm -f $(OBJS) 
	rm -f $(TESTS)
	rm -f *.o
	rm -f *~ 
