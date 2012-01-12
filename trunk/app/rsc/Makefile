CPP = g++
OFLAG = -o
rscfile = rsc.h rsc.cpp rscoper.h rscoper.cpp main.cpp

all: \
	RSC

RSC : $(rscfile)
	$(CPP) $(OFLAG) RSC $(rscfile)

clean:
	rm -f RSC
	rm -f *~
