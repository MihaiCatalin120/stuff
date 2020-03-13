#pragma once
#include "repository.h"


typedef struct {
	Repository* repository;
} Service;

//constructor
Service create_service(Repository* repository);

//functions

//adds a new element
//returns 1 if the element is not already in the repository, 0 otherwise
int add(Service* service, int catalogue_number, char* state, char* type, int value);

//updates an existing element
//returns 1 if the element exists in the repository, 0 otherwise
int update(Service* service, int catalogue_number, char* new_state, char* new_type, int new_value); 

//deletes an existing element from the repository
//returns 1 if the element was found, 0 otherwise
int delete_gear(Service* service, int target_catalogue_number);

//puts all the gear from the repository as a continuous string in the output_string
void list(Service* service, char output_string[]);

//puts all the available gear with the given type as a continuous string in the output_string
//returns 0 if no element with the given type was found, 1 otherwise
int list_type(Service* service, char* target_type, char output_string[]);

//frees the memory allocated in the repository
void delete_repository(Service* service)