#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	printf("Database Management System -- Barebones\n");
	char command[256];

	while (1) {
		printf("DBMS >> Command: ");
		if (fgets(command, sizeof(command), stdin) == NULL) {
			printf("Exiting DBMS...\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0) {
			printf("Exiting DBMS...\n");
			break;
		}
	}
}
