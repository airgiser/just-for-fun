C = gcc -g
OFLAG = -o
slist_src = slist_test.c slist.c

all: \
	slist

slist : $(slist_src)
	$(C) $(OFLAG) slist $(slist_src)

clean:
	rm -f slist
	rm -f *~
