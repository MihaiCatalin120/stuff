#include "ui.h"
#include "service.h"
#include "repository.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>


int main() {
	Repository repository = create_repository();
	Service service = create_service(&repository);
	Console ui = create_console(&service);
	run(&ui);

	_CrtDumpMemoryLeaks();

	return 0;
}
