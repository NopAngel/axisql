#include "../include/database.h"


void update_record(int id, const char *new_name) {
    for (int i = 0; i < record_count; i++) {
        if (database[i].id == id) {
            strncpy(database[i].name, new_name, sizeof(database[i].name));
            printf("Registro actualizado: ID %d, Nuevo Nombre %s\n", id, new_name);
            return;
        }
    }
    printf("Registro con ID %d no encontrado.\n", id);
}