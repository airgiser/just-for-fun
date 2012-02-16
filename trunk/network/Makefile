C = gcc -g
CPP = g++ -g
DFLAG = -D LINUX
OFLAG = -o
LFLAG = -lpthread

serversrc = server_test.c
clientsrc = client_test.c socket.c

all: \
	server_test \
	client_test 

server_test: $(serversrc)
	$(C) $(DFLAG) $(OFLAG) server_test $(serversrc)

client_test: $(clientsrc)
	$(C) $(DFLAG) $(OFLAG) client_test $(clientsrc)

clean:
	rm -f server_test
	rm -f client_test
	rm -f *~
