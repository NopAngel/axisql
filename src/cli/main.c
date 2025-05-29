#include "../include/database.h"
#include <stdio.h>
#include <string.h>

void process_command(const char *command) {
    if (strncmp(command, "CREATE DATABASE ", 16) == 0) {
        create_database(command + 16);
    } else if (strncmp(command, "CREATE TABLE ", 13) == 0) {
        create_table(command + 13);
    } else if (strncmp(command, "ADD COLUMN ", 11) == 0) {
        char table_name[50], column_name[50], type_str[20];
        sscanf(command + 11, "%s %s %s", table_name, column_name, type_str);

        DataType type;
        if (strcmp(type_str, "STRING") == 0) type = TYPE_STRING;
        else if (strcmp(type_str, "NUMBER") == 0) type = TYPE_NUMBER;
        else if (strcmp(type_str, "BOOLEAN") == 0) type = TYPE_BOOLEAN;
        else if (strcmp(type_str, "BINARY") == 0) type = TYPE_BINARY;
       
        else {
            printf("Error: Unknown data type '%s'\n", type_str);
            return;
        }

        add_column_to_table(table_name, column_name, type);
    } else if (strcmp(command, "SHOW DATABASE") == 0) {
        show_database();
    } else {
        printf("Error: Unknown command '%s'\n", command);
    }
}

int main(void) {
    char input[256];

    printf("AXISQL CLI - Enter commands:\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Remover el salto de línea si existe
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "EXIT") == 0) break;

        process_command(input);
    }

    printf("Exiting AXISQL CLI...\n");
    return 0;
}
