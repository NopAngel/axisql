#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "record.h"

int where_filter(Record *record, int min_age);
void order_by_age(Record records[], size_t count);
void join_records(Record table1[], size_t count1, Record table2[], size_t count2);
void group_by_age(Record records[], size_t count);

#endif
