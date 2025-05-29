#include "../include/database.h"

void read_records() {
    printf("Registros actuales:\n");
    for (int i = 0; i < record_count; i++) {
        printf("ID %d - Nombre: %s\n", database[i].id, database[i].name);
    }
}
