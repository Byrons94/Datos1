#pragma once
#include <string> 
#include <iostream>
#include "stdafx.h"
#include <string> 
#include <iostream>
#include <stdio.h>
#include "ListaPasillos.h"
#include "ListaGenerales.h"
#include "ListaEspecifica.h"
#include "ListaArticulo.h"


using namespace System::Runtime::InteropServices;
namespace Utilitario {
	char * toChar(System::String^ );
	int toInt(System::Int32^ );

	System::String^ toSystemString(char *);
	System::Int32^ toInt32(int);
	char * intToChar(int);

	double toDouble(System::String ^ variable);

	System::String^ Contanenado(char *, char *);

	char * getElementCode(System::String ^ variable);

	ListaGenerales  * getGeneral(char * pcodigoPasillo, ListaPasillos *);
	ListaEspecifica * getEspecificas(char * pcodigoGenerales, ListaPasillos *);
	ListaArticulo   * getArticulos(char * pcodigoEspecifica, ListaPasillos *);

}

