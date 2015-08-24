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
	InfoGenerales(int numero, char * descripcion, ListaEspecifica * lista);
	~InfoGenerales();

	void setNumero(int);
	void setCodigo(char *);
	void setDescripcionn(char *);
	void setListaEspecifica(ListaEspecifica *);

	int getNumero();
	char * getCodigo();
	char * getDescripcion();
	ListaEspecifica * getListaGeneral();

	void cargarEspecificas();

	char * autoIncrementar();

	int ultimoRegistro();

	void convertirAChar(char * palabra, std::string palabraString);

	int covertirAEntero(char * pcodigo);


};

