# http://creativecommons.org/publicdomain/zero/1.0/

all:
	gcc -Wall -O2 -o nildb_test_string nildb.c nildb_test_string.c
	gcc -Wall -O2 -o nildb_test_int nildb.c nildb_test_int.c

clean:
	rm -f nildb_test_string nildb_test_int *.o test_string.db test_int.db
