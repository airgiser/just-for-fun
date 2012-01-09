CPP = g++
OFLAG = -o

all: \
	format \
	concat \
	numconv \
	callother \
	textfileio \
	vecintro \
	binary

format: format.cpp
	$(CPP) $(OFLAG) format format.cpp

concat: concat.cpp
	$(CPP) $(OFLAG) concat concat.cpp

numconv: numconv.cpp
	$(CPP) $(OFLAG) numconv numconv.cpp

callother: callother.cpp
	$(CPP) $(OFLAG) callother callother.cpp

textfileio: textfileio.cpp
	$(CPP) $(OFLAG) textfileio textfileio.cpp

vecintro: vectorintro.cpp
	$(CPP) $(OFLAG) vecintro vectorintro.cpp

binary: binary.cpp
	$(CPP) $(OFLAG) binary binary.cpp

clean:
	rm -f format
	rm -f concat
	rm -f numconv
	rm -f callother
	rm -f textfileio
	rm -f vecintro
	rm -f binary
	rm -f *.2
	rm -f *~
