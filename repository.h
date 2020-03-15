#pragma once
#include "gear.h"

typedef struct {
	Gear* elements;
	int length;
	int capacity;
} Repository;

//constructor
Repository create_repository();

//functions

//searches for an element with the given catalogue number in the repository
//returns 1 if the element is found, 0 otherwise
int search(Repository* repository, int catalogue_number);

//searches for elements with the given type
//returns 1 if at least one element with the given type was found, otherwise 0
int search_type(Repository* repository, char* target_type);

//adds the element in the repository
void add_element(Repository* repository, Gear* gear);

//updates the given element in the repository
void update_element(Repository* repository, Gear* gear);

//deletes the given element in the repository
void delete_element(Repository* repository, int target_catalogue_number);

//puts all the gear from the repository as a continuous string in the output_string
void list_all(Repository* repository, char output_string[]);

//puts all the available gear with the given type as a continuous string in the output_string
void list_with_type(Repository* repository, char* type, char output_string[]);

//doubles the size of the elements array
void resize(Repository* repository);

//frees the memory allocated in the repository
void destroy_repository(Repository* repository);