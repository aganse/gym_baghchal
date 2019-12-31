# Makefile for BaghChal game (both text-based cmdline version & WWW CGI version)
CC = gcc
CFLAGS = -Wall -O -g -Wno-format-security
LIBS = -lm

HEADERS = baghchal.h 

SHLSOURCES = main.c \
             gameInit.c \
             playOneTurn.c \
             displayTextBoard.c \
             moveStr2Array.c

PYSOURCES =  gameInit.c \
             playOneTurn.c \
             displayTextBoard.c \
             moveStr2Array.c \
             valCmdLine.c


SHLOBJECTS = $(SHLSOURCES:%.c=%.o)
WWWOBJECTS = $(WWWSOURCES:%.c=%.o)
PYOBJECTS = $(PYSOURCES:%.c=%.o)

.SUFFIXES: ${SUFFIXES} .

.c.o:
	${CC} -c ${CFLAGS} -o $@ $<

# text-based, interactive shell version
shell:  $(SHLOBJECTS) $(HEADERS) makefile
	# making text-based, interactive shell version of BaghChal
	$(CC)  $(CFLAGS)  -o baghchal  $(SHLOBJECTS)  $(LIBS)

libbc.a: $(PYOBJECTS) $(HEADERS) makefile
	ar rcs $@ $^

# tar file for shell version
shltar: 
	tar cvf baghchal.tar main.c gameInit.c playOneTurn.c displayTextBoard.c \
		moveStr2Array.c baghchal.h baghchal.readme Makefile notes

# clear the object files, temp files, and executable from the directory
clean:
	rm -f  *.o *%  *~ baghchal pybaghchal libbc.a
