#include "service.h"
#include "repository.h"
#include "gear.h"
#include <string.h>

//constructor
Service create_service(Repository* repository) {
	Service service;
	service.repository = repository;
	return service;
}

//functions
int add(Service* service, int catalogue_number, char* state, char* type, int value)
{
	Gear element = create_gear(catalogue_number, state, type, value);
	if (search(service->repository, catalogue_number) == 1) {
		return 0;
	}
	else add_element(service->repository, &element);
	return 1;
}

int update(Service* service, int catalogue_number, char* new_state, char* new_type, int new_value)
{
	Gear element = create_gear(catalogue_number, new_state, new_type, new_value);
	if (service->repository->length == 0) {
		return 0;
	}
	if (search(service->repository, catalogue_number) == 0) {
		return 0;
	}
	else update_element(service->repository, &element);
	return 1;
}

int delete_gear(Service* service, int target_catalogue_number)
{
	if (service->repository->length == 0) {
		return 0;
	}
	if (search(service->repository, target_catalogue_number) == 0) {
		return 0;
	}
	else delete_element(service->repository, target_catalogue_number);
	return 1;
}

void list(Service* service, char output_string[])
{
	list_all(service->repository, output_string);
}

int list_type(Service* service, char* target_type, char output_string[])
{
	if (search_type(service->repository, target_type) == 0) {
		return 0;
	}
	list_with_type(service->repository, target_type, output_string);
	return 1;
}

void delete_repository(Service* service)
{
	destroy_repository(service->repository);
}