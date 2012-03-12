C = gcc -g
CPP = g++ -g
DFLAG = -D LINUX
OFLAG = -o
LFLAG = -lpthread

lockersrc = locker_normal.c thread.c locker_test.c
eventsrc = event_test.c event.c thread.c

all: \
	locker_test \
	event_test 

locker_test: $(lockersrc)
	cp locker.h ../algorithms/datastruct/locker.h
	$(C) $(DFLAG) $(OFLAG) locker_test $(lockersrc) $(LFLAG) 

event_test: $(eventsrc)
	$(C) $(DFLAG) $(OFLAG) event_test $(eventsrc) $(LFLAG)

clean:
	rm -f *_test
	rm -f *.o
	rm -f *~
