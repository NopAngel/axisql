#include <stdio.h>
#include <time.h>
#include "record.h"


char* get_now() {
    static char buffer[20];
    time_t t = time(NULL);
    struct tm* tm_info = localtime(&t);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    return buffer;
}
