#include <iostream>
#include <windows.h>
#include <libloaderapi.h>

typedef int (__cdecl* GetFuncPointer)();

extern "C" {

	//This is the interface function, which really just returns a pointer to the actual function. 
	//We can give them the same name, but... this returns a pointer and not an integer. 
	__declspec(dllexport) int __cdecl GenerateInteger()
	{
		HINSTANCE inst = NULL;
		inst = ::LoadLibrary(L"RandomNumberGenerator.dll");
		GetFuncPointer p = NULL;
		if (inst)
			p = (GetFuncPointer)GetProcAddress(inst, "GenerateInteger");
		if (p)	return p();
		else return 999;

	}
}

