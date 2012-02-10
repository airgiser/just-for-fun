C = gcc -g
OFLAG = -o
LFLAG = -lm
sort_src = sort_test.c sort.c
search_src = search_test.c search.c

all: \
	sort_test \
	search_test \
	prime_test \
	nmath_test \
	queen_test \
	compos_test \
	loop_test \
	bag_test

sort_test: $(sort_src)
	$(C) $(OFLAG) sort_test $(sort_src)

search_test: $(search_src)
	$(C) $(OFLAG) search_test $(search_src)

prime_test: prime.c
	$(C) $(OFLAG) prime_test prime.c $(LFLAG)

nmath_test: nmath.c
	$(C) $(OFLAG) nmath_test nmath.c

queen_test: queen.c
	$(C) $(OFLAG) queen_test queen.c

compos_test: strcomposition.c
	$(C) $(OFLAG) compos_test strcomposition.c

loop_test: loop.c
	$(C) $(OFLAG) loop_test loop.c

bag_test: bag01.c
	$(C) $(OFLAG) bag_test bag01.c

clean:
	rm -f *test
	rm -f *~
