#include "record.h"
#include <stdio.h>
#include <string.h>

void join_records(Record table1[], size_t count1, Record table2[], size_t count2) {
    printf("ID\tName\tAge\n");
    printf("--------------------\n");

    for (size_t i = 0; i < count1; i++) {
        for (size_t j = 0; j < count2; j++) {
            if (table1[i].id == table2[j].id) {
                printf("%d\t%s\t%d\n", table1[i].id, table1[i].name, table1[i].age);
            }
        }
    }
}
