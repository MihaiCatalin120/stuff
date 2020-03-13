#include "ui.h"
#include "service.h"
#include "repository.h"


int main() {
	Repository repository = create_repository();
	Service service = create_service(&repository);
	Console ui = create_console(&service);
	run(&ui);

	return 0;
}
