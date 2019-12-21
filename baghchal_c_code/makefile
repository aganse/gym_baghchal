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

WWWSOURCES = mainWWW.c \
             gameInit.c \
             outputHTML.c \
             displayWWWError.c \
             playOneTurn.c \
             valCmdLine.c \
             moveStr2Array.c

PYSOURCES =  mainPy.c \
             gameInit.c \
             outputString.c \
             playOneTurn.c \
             valCmdLine.c \
             moveStr2Array.c \
             displayTextBoard.c


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

# WWW CGI version meant to be called from WWW page, references *.jpg files
www:    $(WWWOBJECTS) $(HEADERS) makefile
	# making WWW CGI version of BaghChal
	$(CC)  $(CFLAGS)  -o baghchalw  $(WWWOBJECTS)  $(LIBS)

# text-based version callable from shell for testing but mainly meant to be called from python
# py:    $(PYOBJECTS) $(HEADERS) makefile libbc.a
# 	# making Python version of BaghChal
# 	$(CC)  $(CFLAGS)  -o pybaghchal  $(PYOBJECTS)  $(LIBS)

libbc.a: $(PYOBJECTS) $(HEADERS) makefile
	ar rcs $@ $^

# tar file for shell version
shltar: 
	tar cvf baghchal.tar main.c gameInit.c playOneTurn.c displayTextBoard.c \
		moveStr2Array.c baghchal.h baghchal.readme Makefile notes

# clear the object files, temp files, and executable from the directory
clean:
	rm -f  *.o *%  *~ baghchal pybaghchal libbc.a
