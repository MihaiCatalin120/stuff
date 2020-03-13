#include <string.h>
#include "ui.h"
#include "service.h"

Console create_console(Service* service) {
	Console UI;
	UI.service = service;
	UI.running = 1;
	return UI;
}

void run(Console* UI) {
	while (UI->running == 1) {
		char input_data[5][20] = { 0 };
		int i, j;
		int wrong_command = 1;
		process_input(UI, input_data);
		if (strcmp(input_data[0], "add") == 0) {
			int catalogue_number = atoi(input_data[1]);
			char state[20];
			char type[20];
			int value = atoi(input_data[4]);
			strcpy(state, input_data[2]);
			strcpy(type, input_data[3]);
			if (add(UI->service, catalogue_number, state, type, value) == 0) {
				printf("No!\n");
			}
			wrong_command = 0;
		}
		if (strcmp(input_data[0], "update") == 0) {
			int catalogue_number = atoi(input_data[1]);
			char new_state[20];
			char new_type[20];
			int new_value = atoi(input_data[4]);
			strcpy(new_state, input_data[2]);
			strcpy(new_type, input_data[3]);
			if (update(UI->service, catalogue_number, new_state, new_type, new_value) == 0) {
				printf("No!\n");
			}
			wrong_command = 0;
		}
		if (strcmp(input_data[0], "delete") == 0) {
			int target_catalogue_number = atoi(input_data[1]);
			if (delete_gear(UI->service, target_catalogue_number) == 0) {
				printf("No!\n");
			}
			wrong_command = 0;
		}
		if (strcmp(input_data[0], "list") == 0) {
			if (input_data[1][0] != 0) {
				char output_string[400] = { 0 };
				char type[20];
				strcpy(type, input_data[1]);
				ui_list_type(UI, type, output_string);
			}
			else {
				char output_string[400] = { 0 };
				ui_list_all(UI, output_string);
			}
			wrong_command = 0;
		}
		if (strcmp(input_data[0], "exit") == 0) {
			UI->running = 0;
			delete_repository(UI->service);
			wrong_command = 0;
		}
		if (wrong_command == 1) {
			printf("Invalid command!\n");
		}
		for (i = 0; i < 5; i++) {
			for (j = 0; j < 20; j++) {
				input_data[i][j] = NULL;
			}
		}
	}
}

void process_input(Console* UI,char input_data[5][20]) {
	char input_string[100];
	char command[10];
	char* split_token;
	int i;
	int number_of_parameters = 0;
	gets(input_string);
	for (i = 0; i < strlen(input_string); i++) {
		if (input_string[i] == ',') {
			strcpy(input_string + i, input_string + i + 1);
			i--;
		}
	}
	split_token = strtok(input_string, " ");
	while (split_token != NULL) {
		strcpy(input_data[number_of_parameters++], split_token);
		split_token = strtok(NULL, " ");
	}
}

void ui_list_all(Console* UI, char output_string[]) {
	list(UI->service, output_string);
	int i; 
	char* output_word;
	output_word = strtok(output_string, ";");
	while (output_word != NULL) {
		printf("%s\n", output_word);
		output_word = strtok(NULL, ";");
	}
}

void ui_list_type(Console* UI, char* type, char output_string[]) {
	if (list_type(UI->service, type, output_string) == 0) {
		printf("No!\n");
		return;
	}
	int i;
	char* output_word;
	output_word = strtok(output_string, ";");
	while (output_word != NULL) {
		printf("%s\n", output_word);
		output_word = strtok(NULL, ";");
	}
}