IFLAG = -I /usr/include/GNUstep/
LFLAG = -L /usr/lib/GNUstep/ \
		-lgnustep-base -fconstant-string-class=NSConstantString

all:
	gcc -o hello hello.m $(IFLAG) $(LFLAG) 

clean:
	rm -f *~
	rm -f hello
