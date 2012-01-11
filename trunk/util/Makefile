C = gcc
DFLAG = -D LINUX
OFLAG = -o
LFLAG = -lpthread

timesrc = time.c time_test.c
filesrc = ucb_file.c ucb_path.c string.c ucb_file_test.c
pathsrc = ucb_path.c string.c ucb_path_test.c
strsrc = string.c string_test.c
lockersrc = locker_normal.c thread.c locker_test.c
eventsrc = event_test.c event.c thread.c
serversrc = server_test.c
clientsrc = client_test.c socket.c

all: \
	time_test \
	file_test \
	path_test \
	str_test \
	locker_test \
	event_test \
	server_test \
	client_test

time_test: $(timesrc)
	$(C) $(DFLAG) $(OFLAG) time_test $(timesrc)

file_test: $(filesrc)
	$(C) $(DFLAG) $(OFLAG) file_test $(filesrc)

path_test: $(pathsrc)
	$(C) $(DFLAG) $(OFLAG) path_test $(pathsrc)

str_test: $(strsrc)
	$(C) $(DFLAG) $(OFLAG) str_test $(strsrc)

locker_test: $(lockersrc)
	$(C) $(DFLAG) $(OFLAG) locker_test $(lockersrc) $(LFLAG) 

event_test: $(eventsrc)
	$(C) $(DFLAG) $(OFLAG) event_test $(eventsrc) $(LFLAG)

server_test: $(serversrc)
	$(C) $(DFLAG) $(OFLAG) server_test $(serversrc)

client_test: $(clientsrc)
	$(C) $(DFLAG) $(OFLAG) client_test $(clientsrc)

clean:
	rm -f time_test
	rm -f file_test
	rm -f path_test
	rm -f str_test
	rm -f locker_test
	rm -f event_test
	rm -f server_test
	rm -f client_test
	rm -f test.bin
	rm -f *.o
	rm -f *~
