#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "nildb.h"

#define NUMENTRY 5000

int main(int argc, char **argv)
{
	unsigned int i;
    char key[25];
	char value[300];
	nildb db;
	int ret;

	printf("Opening new empty database test.db...\n");
    ret = nildb_open(&db, "test_string.db", 1024, sizeof(key), sizeof(value));
	if (ret)
    {
		printf("nildb_open failed\n");
		return -1;
	}

	for (i = 1; i <= NUMENTRY; ++i)
    {
		memset(key, 0, sizeof(key));
        snprintf(key, sizeof(key), "key:%u", i);

        memset(value, 0, sizeof(value));
        snprintf(value, sizeof(value), "key:%u,open_type:1,verify_method:1,salt:1234,start_time:123456,end_time:654321,"
		    "user_info:huangly,valid_count:-1", i);

        ret = nildb_put(&db, key, value);
		if (ret)
        {
			printf("nildb_put failed, key = %s, value = %s\n", key, value);
			return -1;
		}
	}

	for (i = 1; i <= NUMENTRY; ++i)
    {
        memset(key, 0, sizeof(key));
        snprintf(key, sizeof(key), "key:%u", i);

        memset(value, 0, sizeof(value));
        ret = nildb_get(&db, key, value);
		if (ret)
        {
			printf("nildb_get failed, key = %s\n", key);
			return -1;
		}
        printf("nildb_get success, key = %s, value = %s\n", key, value);
	}

    /*
    memset(key, 0, sizeof(key));
    snprintf(key, sizeof(key), "key:%u", 25);
    nildb_delete(&db, key);
    */
   
	nildb_close(&db);
	printf("All tests OK!\n");

	return 0;
}

