C = gcc -g
CPP = g++ -g
DFLAG = -D LINUX
OFLAG = -o

timesrc = time.c time_test.c
filesrc = file.c path.c string.c file_test.c
pathsrc = path.c string.c path_test.c
strsrc = string.c string_test.c
cppstrsrc = stringoper.cpp string_test.cpp
logsrc = log_test.cpp logger.cpp path.c string.c  time.c
tokensrc = parse_token_test.c parse_token.c

all: \
	time_test \
	file_test \
	path_test \
	str_test \
	cppstr_test \
	log_test \
	token_test

time_test: $(timesrc)
	$(C) $(DFLAG) $(OFLAG) time_test $(timesrc)

file_test: $(filesrc)
	$(C) $(DFLAG) $(OFLAG) file_test $(filesrc)

path_test: $(pathsrc)
	$(C) $(DFLAG) $(OFLAG) path_test $(pathsrc)

str_test: $(strsrc)
	$(C) $(DFLAG) $(OFLAG) str_test $(strsrc)

cppstr_test: $(cppstrsrc)
	$(CPP) $(OFLAG) cppstr_test $(cppstrsrc)

log_test: $(logsrc)
	$(CPP) $(DFLAG) $(OFLAG) log_test $(logsrc)

token_test: $(tokensrc)
	$(C) $(OFLAG) token_test $(tokensrc)

clean:
	rm -f *_test
	rm -f test.bin
	rm -f *.o
	rm -f *~
	rm -R logs
