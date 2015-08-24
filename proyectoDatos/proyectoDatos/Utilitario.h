#pragma once
#include <string> 
#include <iostream>

using namespace System::Runtime::InteropServices;
namespace Utilitario {
	char * toChar(System::String^ );
	int toInt(System::Int32^ );

	System::String^ toSystemString(char *);
	System::Int32^ toInt32(int);
	char * intToChar(int);

}


