#pragma once
#include "stdafx.h"

using namespace std;
template<class T>
class TInfoInventario
{
	char *codigo;
	char *descripcion;
	T    * listaInterna;

public:
	TInfoInventario();
	TInfoInventario(T * listaInterna);
	TInfoInventario(char*, char*, T *listaInterna);
	~TInfoInventario();

	
	void setCodigo(char *);
	void setDescripcion(char *);
	void setListaInterna(T *lista);

	char *getCodigo();
	char *getDescripcion();
	T	  getListaInterna();
	
};

