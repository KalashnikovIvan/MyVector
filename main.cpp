// main.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "Test.h"
#include <iostream>


using namespace std;


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	{
		Test test;
	}
	cout << "Created: " << C::created << "\n";
	cout << "Destroyed: " << C::destroyed << "\n";

	system("pause");
    return 0;
}

