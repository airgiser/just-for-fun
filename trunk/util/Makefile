C = gcc
DFLAG = -D LINUX
OFLAG = -o
LFLAG = -lpthread

timesrc = ucb_time.c ucb_time_test.c
filesrc = ucb_file.c ucb_path.c ucb_string.c ucb_file_test.c
pathsrc = ucb_path.c ucb_string.c ucb_path_test.c
strsrc = ucb_string.c ucb_string_test.c
lockersrc = locker_normal.c thread.c locker_test.c

all: \
	time_test \
	file_test \
	path_test \
	str_test \
	locker_test

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

clean:
	rm -f time_test
	rm -f file_test
	rm -f path_test
	rm -f str_test
	rm -f locker_test
	rm -f test.bin
	rm -f *~
