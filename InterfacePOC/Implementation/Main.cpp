#include <iostream>
#include <windows.h>
#include <libloaderapi.h>

typedef int (__cdecl* GetRandomPointer)();

int main()
{
	HINSTANCE inst = NULL;
	inst = ::LoadLibrary(L"Interface.dll");
	if (inst)
	{
		GetRandomPointer p = (GetRandomPointer)GetProcAddress(inst, "GenerateInteger");
		if (p)
		{
			std::cout << "Random number is 1 : " << p() << "\n";
			std::cout << "Random number is 2 : " << p() << "\n";
			std::cout << "Random number is 3 : " << p() << "\n";
		}
	}
	return 0;
}

