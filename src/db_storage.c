#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "db_storage.h"

#define DATA_FILE "data/table.dat"

typedef struct Row {
	int index;
	char name[50];
} Row;

void create_table() {
	FILE *table = fopen(DATA_FILE, "wb");
	if (table == NULL) {
		perror("Error creating table file.");
		return;
	}

	fclose(table);
	printf("Table created: %s", DATA_FILE);
}

void insert_row(int index, const char* name) {
	FILE *table = fopen(DATA_FILE, "ab");
	if (table == NULL) {
		perror("Error opening table file.");
		return;
	}

	Row row = {index, ""};
	strncpy(row.name, name, sizeof(row.name) - 1);	
	fwrite(&row, sizeof(Row), 1, table);

	printf("Row inserted: Index=%d, Name=%s\n", index, name);
}
