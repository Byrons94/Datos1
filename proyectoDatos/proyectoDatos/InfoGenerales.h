#pragma once
#include "ListaEspecifica.h"
#include "stdafx.h"

class InfoGenerales
{

private:
	int  numero;
	char codigo[15];
	char descripcion[30];
	ListaEspecifica * lista;

public:
	InfoGenerales();
	InfoGenerales(int, char*, char*);
	InfoGenerales(int, char*, char*, ListaEspecifica*);
	~InfoGenerales();

	void setNumero(int);
	void setCodigo(char *);
	void setDescripcionn(char *);
	void setListaEspecifica(ListaEspecifica *);

	int getNumero();
	char * getCodigo();
	char * getDescripcion();
	ListaEspecifica * getListaEspecifica();

	void cargarEspecificas();


};

