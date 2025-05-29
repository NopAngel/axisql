#include "../include/database.h"

int main() {
    printf("AXISQL - SQL Database Engine\n\n");

    create_database("potato_express");
    create_table("user");
    add_column_to_table("user", "1", TYPE_NUMBER);
    add_column_to_table("user", "Nombre", TYPE_STRING);
    add_column_to_table("user", "true", TYPE_BOOLEAN);
    add_column_to_table("user", "avatar", TYPE_BINARY);

    show_database();

    return 0;
}
