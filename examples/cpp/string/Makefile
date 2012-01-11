CPP = g++
OFLAG = -o

all: \
	storage_demo \
	init_demo \
	oper_demo \
	search_demo \
	html_demo \
	strip_demo \
	cmp_demo \
	iter_demo \
	traits_demo

storage_demo: stringstorage.cpp
	$(CPP) $(OFLAG) storage_demo stringstorage.cpp 

# string substr
init_demo: stringinit.cpp
	$(CPP) $(OFLAG) init_demo stringinit.cpp 

# size capacity
# insert append
# reserve
# replace
oper_demo: stringoper.cpp
	$(CPP) $(OFLAG) oper_demo stringoper.cpp 

# find rfind
# find_first_of find_first_not_of
# find_last_of find_last_not_of
search_demo: stringsearch.cpp
	$(CPP) $(OFLAG) search_demo stringsearch.cpp 

# erase
html_demo: reprocesshtml.cpp
	$(CPP) $(OFLAG) html_demo reprocesshtml.cpp 

# erase replace
strip_demo: striphtml.cpp
	$(CPP) $(OFLAG) strip_demo striphtml.cpp 

# compare swap at
cmp_demo: stringcmp.cpp
	$(CPP) $(OFLAG) cmp_demo stringcmp.cpp 

# iterator
iter_demo: stringiter.cpp
	$(CPP) $(OFLAG) iter_demo stringiter.cpp

traits_demo: stringtraits.cpp
	$(CPP) $(OFLAG) traits_demo stringtraits.cpp
	
clean:
	rm -f *demo
	rm -f output
	rm -f output.html
	rm -f *~
