#include "record.h"
#include <stdio.h>

int where_filter(Record *record, int min_age) {
    return record->age >= min_age;
}
