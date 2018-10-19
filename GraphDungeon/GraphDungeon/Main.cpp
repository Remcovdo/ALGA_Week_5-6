#include "Application.h"

#define _CRTDBG_MAP_ALLOC   
#include <crtdbg.h>

int main()
{
	{
		Application application;
		application.start();
	}

	_CrtDumpMemoryLeaks();
	return 0;
}