#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "../fnc/record.h"
#include "../fnc/functions.h"

#define RED   "\033[1;31m"
#define RESET "\033[0m"

typedef struct {
    char name[50];
    char body[200];
} Function;

Function udf_list[20];  
int udf_count = 0;


void create_function(const char* name, const char* body) {
    if (udf_count >= 20) {
        printf(RED "Error: Maximum number of functions reached.\n" RESET);
        return;
    }
    strcpy(udf_list[udf_count].name, name);
    strcpy(udf_list[udf_count].body, body);
    udf_count++;
    printf("Function '%s' has been created.\n", name);
}

void execute_function(const char* name) {
    for (int i = 0; i < udf_count; i++) {
        if (strcmp(udf_list[i].name, name) == 0) {
            printf("Executing function '%s': %s\n", name, udf_list[i].body);
            return;
        }
    }
    printf(RED "Error: Function '%s' not found.\n" RESET, name);
}

int is_axisql_file(const char* filename) {
    const char* ext = strrchr(filename, '.');
    return (ext && strcmp(ext, ".axisql") == 0);
}


void process_axisql_file(const char* filepath) {
    if (!is_axisql_file(filepath)) {
        printf(RED "Error: The file does not have the .axisql extension\n" RESET);
        return;
    }

    FILE* file = fopen(filepath, "r");
    if (!file) {
        printf(RED "Error: Could not open file %s\n" RESET, filepath);
        return;
    }

    char line[256];
    char current_table[50] = "";
    char current_db[50] = "";
    Record results[100];
    size_t result_count = 10;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;

        if (strncmp(line, "--", 2) == 0 || (strstr(line, "/*") && strstr(line, "*/"))) {
            continue;
        }

        
        if (strlen(line) == 0) {
            continue;
        }

       
        if (strncmp(line, "CREATE DATABASE", 15) == 0) {
            sscanf(line, "CREATE DATABASE %49s", current_db);
            current_db[strcspn(current_db, ";")] = '\0'; 
            printf("Database '%s' has been created successfully.\n", current_db);
        } else if (strncmp(line, "USE DATABASE", 12) == 0) {
            sscanf(line, "USE DATABASE %49s", current_db);
            current_db[strcspn(current_db, ";")] = '\0';  
            printf("Switched to database '%s'.\n", current_db);
        } else if (strncmp(line, "CREATE TABLE", 12) == 0) {
            if (strlen(current_db) == 0) {
                printf(RED "Error: No database selected. Use 'USE DATABASE <name>' before creating a table.\n" RESET);
            } else {
                sscanf(line, "CREATE TABLE %49s", current_table);
                current_table[strcspn(current_table, ";")] = '\0';  
                printf("Table '%s' has been created in database '%s'.\n", current_table, current_db);
            }
        } else if (strncmp(line, "INSERT INTO", 11) == 0) {
            sscanf(line, "INSERT INTO %49s", current_table);
            printf("Record inserted into table '%s' in database '%s'.\n", current_table, current_db);
        } else if (strncmp(line, "SELECT", 6) == 0) {
            sscanf(line, "SELECT * FROM %49s", current_table);
            printf("Query executed on table '%s' in database '%s': displaying results.\n", current_table, current_db);

            if (strstr(line, "WHERE")) {
                for (size_t i = 0; i < result_count; i++) {
                    if (!where_filter(&results[i], 25)) {
                        continue;
                    }
                }
            }

            if (strstr(line, "ORDER BY")) {
                order_by_age(results, result_count);
            }

            if (strstr(line, "JOIN")) {
                char join_table[50] = "";
                sscanf(line, "SELECT * FROM %49s JOIN %49s", current_table, join_table);
                printf("Executing JOIN between '%s' and '%s' in database '%s'.\n", current_table, join_table, current_db);
                join_records(results, result_count, results, result_count);
            }

            if (strstr(line, "GROUP BY")) {
                group_by_age(results, result_count);
            }
        } else if (strncmp(line, "UPDATE", 6) == 0) {
            char table[50], column[50], value[50], condition_column[50], condition_value[50];
            int matched = sscanf(line, "UPDATE %49s SET %49s = %49s WHERE %49s = %49s", table, column, value, condition_column, condition_value);

            table[strcspn(table, ";")] = '\0';  
            condition_value[strcspn(condition_value, ";")] = '\0';  

            if (matched < 5 || strlen(table) == 0) {
                printf(RED "Error: Invalid UPDATE syntax or missing table name.\n" RESET);
                return;
            }

            int updated = 0;
            for (size_t i = 0; i < result_count; i++) {
                if (strcmp(condition_column, "name") == 0 && strcmp(results[i].name, condition_value) == 0) {
                    if (strcmp(column, "age") == 0) {
                        results[i].age = atoi(value);
                        updated++;
                    }
                }
            }
            printf(updated > 0 ? "Updated %d record(s) in table '%s'.\n" : RED "Error: No matching records found in table '%s'.\n" RESET, updated, table);
        }
    }

    fclose(file);
    printf("File processed successfully.\n");
}


int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "en_US.UTF-8");

    if (argc != 2) {
        printf("Usage: axisql ./PATH/TO/AXISQL.axisql\n");
        return 1;
    }

    process_axisql_file(argv[1]);
    return 0;
}
