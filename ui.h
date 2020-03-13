#pragma once
#include "service.h"

typedef struct {
	Service* service;
	int running;
} Console;

Console create_console(Service* service);

//ui starter
void run(Console* UI);

//changes the raw user input into string of parameters
void process_input(Console* UI, char input_data[5][20]);

//prints all the elements of the repository
void ui_list_all(Console* UI, char output_string[]);

//prints all the elements in the repository which have the given type
void ui_list_type(Console* UI, char* type, char output_string[]);
