C = gcc -g
CPP = g++ -g
OFLAG = -o

memtest_src = memcheck.cpp memtest.cpp

all: memtest

memtest: $(memtest_src)
	$(CPP) $(OFLAG) memtest $(memtest_src)

clean:
	rm -f *~
	rm -f memtest
