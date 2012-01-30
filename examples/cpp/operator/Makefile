CPP = g++ -g
OFLAG = -o
smartsrc = smartptr.cpp
opersrc = integer.cpp testoper.cpp byte.cpp
assignsrc = assignoper.cpp
refsrc = refcount.cpp

all: \
	smart \
	oper \
	assign \
	ref

smart: $(smartsrc)
	$(CPP) $(OFLAG) smart $(smartsrc)

oper: $(opersrc)
	$(CPP) $(OFLAG) oper $(opersrc)

assign: $(assignsrc)
	$(CPP) $(OFLAG) assign $(assignsrc)

ref: $(refsrc)
	$(CPP) $(OFLAG) ref $(refsrc)

clean:
	rm -f smart
	rm -f oper
	rm -f assign
	rm -f ref
	rm -f *~
