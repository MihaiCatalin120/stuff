#include "repository.h"
#include "gear.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Repository create_repository() {
	Repository* repository;
	repository = (Repository*)malloc(sizeof(repository));
	repository->length = 0;
	repository->capacity = 1;
	repository->elements = (Gear*)malloc(repository->capacity * sizeof(Gear));

	return *repository;
}

int search(Repository* repository, int catalogue_number)
{
	int i;
	for (i = 0; i < repository->length; i++) {
		if (repository->elements[i].catalogue_number == catalogue_number) {
			return 1;
		}
	}
	return 0;
}

int search_type(Repository* repository, char* target_type)
{
	int i;
	for (i = 0; i < repository->length; i++) {
		if (strcmp(repository->elements[i].type, target_type) == 0) {
			return 1;
		}
	}
	return 0;
}

void add_element(Repository* repository, Gear* gear)
{
	repository->elements[repository->length++] = *gear;
	if (repository->length >= repository->capacity) {
		resize(repository);
	}
}

void resize(Repository* repository)
{
	repository->capacity *= 2;
	int i;
	Gear* new_elements = (Gear*)malloc(repository->capacity * sizeof(Gear));
	for (i = 0; i <= repository->length; i++) {
		new_elements[i] = repository->elements[i];
	}
	repository->elements = new_elements;
	free(new_elements);
}

void update_element(Repository* repository, Gear* gear)
{
	int i;
	for (i = 0; i < repository->length; i++) {
		if (repository->elements[i].catalogue_number == gear->catalogue_number) {
			set_state(&repository->elements[i], gear->state);
			set_type(&repository->elements[i], gear->type);
			set_value(&repository->elements[i], gear->value);
			return;
		}
	}
}

void delete_element(Repository* repository, int target_catalogue_number)
{
	int i, j;
	for (i = 0; i < repository->length; i++) {
		if (repository->elements[i].catalogue_number == target_catalogue_number) {
			for (j = i; j < repository->length - 1; j++) {
				repository->elements[j] = repository->elements[j + 1];
			}
			repository->length--;
		}
	}
}

void list_all(Repository* repository, char output_string[])
{
	int i;
	for (i = 0; i < repository->length; i++) {
		strcat(output_string, gear_to_string(&repository->elements[i]));
		strcat(output_string, ";");
	}
}

void list_with_type(Repository* repository, char* type, char output_string[])
{
	int i;
	for (i = 0; i < repository->length; i++) {
		if (strcmp(repository->elements[i].type, type) == 0) {
			strcat(output_string, gear_to_string(&repository->elements[i]));
			strcat(output_string, ";");
		}
	}
}

void destroy_repository(Repository* repository)
{
	free(repository->elements);
}
