# file Makefile
CC= gcc
RM= rm -vf
CFLAGS= -Wall -g
DEPS = msgsysutils.h
CPPFLAGS= -I.
SRCFILES= msgsys.c criautilizador.c listautilizador.c removeutilizador.c entregamsg.c consultamsg.c retiramsg.c ## or perhaps $(wildcard *.c)
OBJFILES= $(patsubst %.c, %.o, $(SRCFILES))
PROGFILES= $(patsubst %.c, %, $(SRCFILES))

.PHONY: all clean count

all: $(PROGFILES)
clean:
	$(RM) $(OBJFILES) $(PROGFILES) *~
## eof Makefile
