CC = gcc
CFLAGS = -Wall -g
LFLAGS = -lm

PROG = terminalGoL 
OBJPROG = GoL_main.o GoL_func.o GoL_pattern.o
PREFIX = /usr/local

all: $(PROG)

$(PROG): $(OBJPROG)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

clean:
	-rm -f $(PROG) *~ *.o

install: 
	cp $(PROG) $(PREFIX)/bin
	chmod 755 $(PREFIX)/bin/$(PROG)

uninstall:
	rm $(PREFIX)/bin/$(PROG)