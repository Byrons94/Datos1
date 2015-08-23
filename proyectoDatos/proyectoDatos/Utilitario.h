#pragma once

#include <string> 
#include <iostream>
#include <msclr\marshal_cppstd.h>
using namespace System::Runtime::InteropServices;
namespace Utilitario{
	char * toChar(System::String^ variable) {
		char * charReturn = (char*)(void*)Marshal::StringToHGlobalAnsi(variable);
		return charReturn;
	}

	int toInt(System::Int32^ variable) {
		int intReturn = (int)variable;
		return intReturn;
	}
}

