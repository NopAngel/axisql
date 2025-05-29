#include "../include/database.h"

Record database[MAX_RECORDS];  
int record_count = 0;

Database main_db;



void create_database(const char *name) {
    strncpy(main_db.name, name, sizeof(main_db.name));
    main_db.table_count = 0;
    printf("AXISQL:: Data base '%s' created!.\n", main_db.name);
}

void create_table(const char *name) {
    if (main_db.table_count < MAX_TABLES) {
        Table *new_table = &main_db.tables[main_db.table_count];
        strncpy(new_table->name, name, sizeof(new_table->name));
        new_table->column_count = 0;
        main_db.table_count++;
        printf("AXISQL:: Table '%s' created in the data base '%s'.\n", name, main_db.name);
    } else {
        printf("ERROR:: No more tables can be added.\n");
    }
}

void add_column_to_table(const char *table_name, const char *column_name, DataType type) {
    for (int i = 0; i < main_db.table_count; i++) {
        if (strcmp(main_db.tables[i].name, table_name) == 0) {
            if (main_db.tables[i].column_count < 10) {
                Column *new_col = &main_db.tables[i].columns[main_db.tables[i].column_count];
                strncpy(new_col->name, column_name, sizeof(new_col->name));
                new_col->type = type;
                main_db.tables[i].column_count++;
                printf("AXISQL:: Column '%s' added to the table '%s'.\n", column_name, table_name);
                return;
            } else {
                printf("ERROR:: The table already has the maximum number of columns allowed.\n");
                return;
            }
        }
    }
    printf("Table '%s' not found.\n", table_name);
}

void show_database() {
    printf("\nData base: %s\n", main_db.name);
    for (int i = 0; i < main_db.table_count; i++) {
        printf("  Table: %s\n", main_db.tables[i].name);
        for (int j = 0; j < main_db.tables[i].column_count; j++) {
            printf("    - %s (%d)\n", main_db.tables[i].columns[j].name, main_db.tables[i].columns[j].type);
        }
    }
}
