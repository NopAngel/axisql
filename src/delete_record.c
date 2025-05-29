#include "../include/database.h"

void delete_record(int id) {
    int found = 0;
    for (int i = 0; i < record_count; i++) {
        if (database[i].id == id) {
            found = 1;
            for (int j = i; j < record_count - 1; j++) {
                database[j] = database[j + 1];
            }
            record_count--;
            printf("Registro con ID %d eliminado.\n", id);
            return;
        }
    }
    if (!found) {
        printf("Registro con ID %d no encontrado.\n", id);
    }
}
