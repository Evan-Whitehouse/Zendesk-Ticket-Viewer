CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -g
INCLUDE = -I./model -I./view -I./controller
LINKD = -L./model -L./view -L./controller
LDFLAGS += $(LINKD)
CFLAGS += $(INCLUDE)
FILENAME = ztv
MODEL = model
VIEW = view
CONTROLLER = controller

$(FILENAME): $(MODEL).o $(VIEW).o $(CONTROLLER).o
	$(CC) $(LDFLAGS) $(MODEL).o $(VIEW).o $(CONTROLLER).o -o $(FILENAME)
$(MODEL).o:
	$(CC) $(CFLAGS) -c ./model/$(MODEL).c
$(VIEW).o:
	$(CC) $(CFLAGS) -c ./view/$(VIEW).c
$(CONTROLLER).o:
	$(CC) $(CFLAGS) -c ./controller/$(CONTROLLER).c
.PHONY: clean 
clean:
	rm -rf $(FILENAME) *.o
.PHONY: all
all: clean $(FILENAME)

