#pragma once
#include "ListaArticulo.h"

class InfoEspecifica
{
	int  numero;
	char codigo[15];
	char descripcion[30];
	ListaArticulo * lista;

public:
	InfoEspecifica();
	InfoEspecifica(int, char *, char * ,ListaArticulo *);
	InfoEspecifica(int pnumero, char * pdescripcion, ListaArticulo * plista);
	InfoEspecifica(int, char *, char *);

	~InfoEspecifica();
	
	//sets
	void setNumero(int);
	void setCodigo(char*);
	void setDescripcion(char*);
	void setListaArticulos(ListaArticulo*);
	
	//gets
	int getNumero();
	char * getCodigo();
	char * getDescripcion();
	ListaArticulo * getListaArticulos();

	void cargarArticulos();

	char * autoIncrementar();

	int ultimoRegistro();

	void convertirAChar(char * palabra, std::string palabraString);

	int covertirAEntero(char * pcodigo);

};

