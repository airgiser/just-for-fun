IFLAG = -I /usr/include/GNUstep/
LFLAG = -L /usr/lib/GNUstep/ \
		-lgnustep-base -fconstant-string-class=NSConstantString
HelloSrc = hello.m
CSrc = onlyc.m

all:\
	hello\
	onlyc

hello: $(HelloSrc)
	gcc -o hello $(HelloSrc) $(IFLAG) $(LFLAG) 

onlyc: $(CSrc)
	gcc -o onlyc $(CSrc)

clean:
	rm -f *~
	rm -f hello
	rm -f onlyc
