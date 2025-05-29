#include "../include/database.h"
void create_record(int id, const char *name) {
    if (record_count < MAX_RECORDS) {
        database[record_count].id = id;
        strncpy(database[record_count].name, name, sizeof(database[record_count].name));
        record_count++;
        printf("Registro creado: ID %d, Nombre %s\n", id, name);
    } else {
        printf("Base de datos llena.\n");
    }
}