C = gcc -g
CPP = g++ -g
OFLAG = -o

memtest_src = memcheck.cpp memtest.cpp
mempool_src = pool.c pooltest.c

all: memtest pooltest

memtest: $(memtest_src)
	$(CPP) $(OFLAG) memtest $(memtest_src)

pooltest: $(mempool_src)
	$(C) $(OFLAG) pooltest $(mempool_src)

clean:
	rm -f *~
	rm -f memtest
	rm -f pooltest
