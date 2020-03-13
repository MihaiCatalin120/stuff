#pragma once
#include <stdio.h>

typedef struct {
	int catalogue_number;
	char state[20];
	char type[20];
	int value;
} Gear;

//constructor
Gear create_gear(int catalogue_number, char* state, char* type, int value);

//getters & setters
int get_catalogue_number(Gear* gear);

char* get_state(Gear* gear);

char* get_type(Gear* gear);

int get_value(Gear* gear);

void set_state(Gear* gear, char* state);

void set_type(Gear* gear, char* type);

void set_value(Gear* gear, int value);

//converts a Gear type object into a string
char* gear_to_string(Gear* element);