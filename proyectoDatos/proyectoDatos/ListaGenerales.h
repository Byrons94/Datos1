#pragma once
#include "NodoGenerales.h"

class ListaGenerales
{
private:
	NodoGenerales *cab;
	int tamanio;

	NodoGenerales * dirNodo(char *);
	NodoGenerales * dirUltimo();
	NodoGenerales * dirAnterior(char *);
	NodoGenerales * dirIndex(int);
	char* dirCodigoDePasillo(NodoGenerales *);
	// agregar
	void agregarNodoDespuesDe(NodoGenerales *, NodoGenerales *);
	void agregarNodoAntesDe(NodoGenerales *, NodoGenerales *);


public:
	ListaGenerales();
	~ListaGenerales();

	//sets
	void setCab(NodoGenerales *);
	void setTamanio(int);

	//gets
	NodoGenerales * getCab();
	int getTamanio();

	//insertar
	void insetarInicio(InfoGenerales *);
	void insertarFinal(InfoGenerales *);
	bool insertarAntesDe(InfoGenerales *, char *);
	bool insertarDespuesDe(InfoGenerales *, char *);
	bool insertarAcendente(InfoGenerales *);
	bool insertarDecendente(InfoGenerales *);


	//eliminar
	bool elimina(char *);
	bool eliminarIndex(int);
	void vaciar();
	void eliminarNodo(NodoGenerales *);

	// obtener 
	InfoGenerales * obtenerDato(char *);
	InfoGenerales * obtenerPorIndex(int);
	bool estaVacia();

	//modificar
	bool modificarDatos(char *, InfoGenerales *);

};

