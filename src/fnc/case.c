#include <stdio.h>
#include <string.h>
#include "record.h"

typedef struct {
    char condition[50];
    char result[50];
} CaseCondition;

const char* case_when(const char* value, CaseCondition conditions[], size_t count) {
    for (size_t i = 0; i < count; i++) {
        if (strcmp(value, conditions[i].condition) == 0) {
            return conditions[i].result;
        }
    }
    return "DEFAULT";
}
