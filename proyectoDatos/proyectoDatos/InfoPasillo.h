#pragma once
#include "ListaGenerales.h"
#include "stdafx.h"

class InfoPasillo
{
private:
	int  numero;
	char codigo[15];
	char descripcion[30];
	ListaGenerales *lista;

public:
	InfoPasillo();
	InfoPasillo(int, char*, char*);
	InfoPasillo(int, char*, char*, ListaGenerales*);
	InfoPasillo(int pnumero, char * pdescripcion, ListaGenerales * plista);
	~InfoPasillo();

	void setNumero(int);
	void setCodigo(char *);
	void setDescripcionn(char *);
	void setListaGeneral(ListaGenerales * lista);


	int getNumero();
	char * getCodigo();
	char * getDescripcion();
	ListaGenerales * getListaGeneral();

	void cargarGeneralesPasillo();

	char * autoIncrementar();

	int ultimoRegistro();

	void convertirAChar(char * palabra, std::string palabraString);

	int covertirAEntero(char * pcodigo);

	

};
