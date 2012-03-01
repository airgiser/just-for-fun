C = gcc -g
OFLAG = -o
slist_src = slist_test.c slist.c
dlist_src = dlist_test.c dlist.c

all: \
	slist \
	dlist

slist : $(slist_src)
	$(C) $(OFLAG) slist $(slist_src)

dlist : $(dlist_src)
	$(C) $(OFLAG) dlist $(dlist_src)

clean:
	rm -f slist
	rm -f dlist
	rm -f *~
