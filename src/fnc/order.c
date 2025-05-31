#include "record.h"
#include <stdio.h>
#include <stdlib.h>

int compare_by_age(const void* a, const void* b) {
    return ((Record*)a)->age - ((Record*)b)->age;
}

void order_by_age(Record records[], size_t count) {
    qsort(records, count, sizeof(Record), compare_by_age);
}
