#include "record.h"
#include <stdio.h>

void group_by_age(Record records[], size_t count) {
    int age_counts[150] = {0};

    for (size_t i = 0; i < count; i++) {
        age_counts[records[i].age]++;
    }

    printf("Age\tCount\n");
    printf("----------------\n");

    for (int i = 0; i < 150; i++) {
        if (age_counts[i] > 0) {
            printf("%d\t%d\n", i, age_counts[i]);
        }
    }
}
