#pragma once
#include "stdafx.h"

using namespace std;
template<class T>
class TInfoInventario
{
	int  jerarquia;
	char *codigo;
	char *descripcion;
	T    * listaInterna;

public:
	TInfoInventario();
	TInfoInventario(T * listaInterna);
	TInfoInventario(char*, char*, int, T *listaInterna);
	~TInfoInventario();

	
	void setJerarquia(int );
	void setCodigo(char *);
	void setDescripcion(char *);
	void setListaInterna(T *lista);

	int getJerarquia();
	char *getCodigo();
	char *getDescripcion();
	T	  getListaInterna();
	
};

