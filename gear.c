#include <stdio.h>
#include "gear.h"

//constructor
Gear create_gear(int catalogue_number, char* state, char* type, int value) {
	Gear gear;
	gear.catalogue_number = catalogue_number;
	strcpy(gear.state, state);
	strcpy(gear.type, type);
	gear.value = value;
	return gear;
}

//getters & setters
int get_catalogue_number(Gear* gear) {
	return gear->catalogue_number;
}

char* get_state(Gear* gear) {
	return gear->state;
}

char* get_type(Gear* gear) {
	return gear->type;
}

int get_value(Gear* gear) {
	return gear->value;
}

void set_state(Gear* gear, char* state) {
	strcpy(gear->state, state);
}

void set_type(Gear* gear, char* type) {
	strcpy(gear->type, type);
}

void set_value(Gear* gear, int value) {
	gear->value = value;
}

char* gear_to_string(Gear* element)
{
	char result[50] = { 0 };
	sprintf(result, "%d, %s, %s, %d", element->catalogue_number, element->state, element->type, element->value);
	return result;
}