all:
	gcc -g cucb_time.c cucb_time_test.c -D LINUX -o time_test
	gcc -g cucb_file.c cucb_path.c cucb_string.c cucb_file_test.c -D LINUX -o file_test
	gcc -g cucb_path.c cucb_string.c cucb_path_test.c -D LINUX -o path_test
	gcc -g cucb_string.c cucb_string_test.c -D LINUX -o str_test
	gcc -g cucb_locker_normal.c cucb_thread.c cucb_locker_test.c -D LINUX -lpthread -o locker_test

clean:
	rm -f time_test
	rm -f file_test
	rm -f path_test
	rm -f str_test
	rm -f locker_test
	rm -f test.bin
	rm -f *~
