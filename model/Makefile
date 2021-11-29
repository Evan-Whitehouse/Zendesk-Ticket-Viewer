CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -g
MAINFILE = modelUnitTests
$(MAINFILE): $(MAINFILE).o
	$(CC) $(LDFLAGS) $(MAINFILE).o -o $(MAINFILE)
$(MAINFILE).o: $(MAINFILE).c
	$(CC) $(CFLAGS) -c $(MAINFILE).c
.PHONY: clean
clean:
	rm -rf $(MAINFILE) *.o
.PHONY: all
all: clean $(MAINFILE)
