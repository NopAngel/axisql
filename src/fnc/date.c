#include <stdio.h>
#include <time.h>
#include "record.h"

char* get_date() {
    static char buffer[11];
    time_t t = time(NULL);
    struct tm* tm_info = localtime(&t);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", tm_info);
    return buffer;
}
