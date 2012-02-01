C = gcc
OFLAG = -o

all: \
	bytes_order \
	inplace_swap

bytes_order : bytes_order.c
	$(C) $(OFLAG) bytes_order bytes_order.c

inplace_swqp : inplace_swap.c
	$(C) $(OFLAG) inplace_swap inplace_swap.c

clean:
	rm -f bytes_order
	rm -f inplace_swap
	rm -f *~
