#pragma once
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

/*
#ifdef INTERFACE_EXPORTS
#    define INTERFACE_API __declspec(dllexport)
#else
#    define INTERFACE_API __declspec(dllimport)
#endif
*/

extern "C" {

	__declspec(dllexport) int __cdecl GenerateInteger()
	{
		srand(time(NULL));
		int retval = rand() % 10 + 1;
		return retval;
	}
}

