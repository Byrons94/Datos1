#include "Utilitario.h"


char * Utilitario::toChar(System::String ^ variable){
	char * charReturn = (char*)(void*)Marshal::StringToHGlobalAnsi(variable);
	return charReturn;
}

int Utilitario::toInt(System::Int32 ^ variable){
	int intReturn = (int)variable;
	return intReturn;
}
