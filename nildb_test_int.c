#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "nildb.h"

#define NUMENTRY 5000
int main(int argc, char **argv)
{
	unsigned int i;
    unsigned int key_id;
	char key_value[256];
	nildb db;
	int ret;

	printf("Opening new empty database test.db...\n");
    ret = nildb_open(&db, "test_int.db", 1024, 32, sizeof(key_value));
	if (ret)
    {
		printf("nildb_open failed\n");
		return -1;
	}

	for (i = 1; i <= NUMENTRY; ++i)
    {
		key_id = i;
        memset(key_value, 0, sizeof(key_value));
        sprintf(key_value, "user_info:%u", i);

        ret = nildb_put(&db, &key_id, key_value);
		if (ret)
        {
			printf("nildb_put failed, key_id = %u, key_value = %s\n", key_id, key_value);
			return -1;
		}
	}

	for (i = 1; i <= NUMENTRY; ++i)
    {
        key_id = i;
        memset(key_value, 0, sizeof(key_value));

        ret = nildb_get(&db, &key_id, key_value);
		if (ret)
        {
			printf("nildb_get failed, key_id = %u\n", key_id);
			return -1;
		}
        printf("nildb_get success, key_id = %u, key_value = %s\n", key_id, key_value);
	}

    for (i = 1; i <= NUMENTRY; i++)
    {
        key_id = i;

        ret = nildb_delete(&db, &key_id);
        if (ret)
        {
            printf("nildb_delete failed, key_id = %u\n", key_id);
            return -1;
        }
    }

    for (i = 1; i <= NUMENTRY; ++i)
    {
        key_id = i;
        memset(key_value, 0, sizeof(key_value));

        ret = nildb_get(&db, &key_id, key_value);
		if (ret)
        {
			printf("nildb_get failed, key_id = %u\n", key_id);
			return -1;
		}
        printf("nildb_get success, key_id = %u, key_value = %s\n", key_id, key_value);
	}

	nildb_close(&db);
	printf("All tests OK!\n");

	return 0;
}

