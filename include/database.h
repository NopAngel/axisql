#ifndef AXISQL_DATABASE_H
#define AXISQL_DATABASE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLES 10
#define MAX_RECORDS 100

typedef enum { TYPE_STRING, TYPE_NUMBER, TYPE_BOOLEAN, TYPE_BINARY } DataType;

typedef struct {
    char name[50];
    DataType type;
} Column;

typedef struct {
    int id;
    char name[50];
} Record;


typedef struct {
    char name[50];
    Column columns[10];  // Definimos un máximo de 10 columnas por tabla
    int column_count;
} Table;

typedef struct {
    char name[50];
    Table tables[MAX_TABLES];  // La base de datos puede contener varias tablas
    int table_count;
} Database;

// Variables globales
extern Database main_db;

// Funciones principales
void create_database(const char *name);
void create_table(const char *name);
void add_column_to_table(const char *table_name, const char *column_name, DataType type);
void show_database();

#endif // AXISQL_DATABASE_H
