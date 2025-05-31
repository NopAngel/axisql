#include <stdio.h>
#include "record.h"

#include <time.h>

char* get_time() {
    static char buffer[10];
    time_t t = time(NULL);
    struct tm* tm_info = localtime(&t);
    strftime(buffer, sizeof(buffer), "%H:%M:%S", tm_info);
    return buffer;
}
