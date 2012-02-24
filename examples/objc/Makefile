IFLAG = -I /usr/include/GNUstep/
LFLAG = -L /usr/lib/GNUstep/ \
		-lgnustep-base -fconstant-string-class=NSConstantString
DFLAG = -D _NATIVE_OBJC_EXCEPTIONS
HelloSrc = hello.m

all:\
	hello

hello: $(HelloSrc)
	gcc -o hello $(DFLAG) $(HelloSrc) $(IFLAG) $(LFLAG) 

clean:
	rm -f *~
	rm -f hello
	rm -f onlyc
