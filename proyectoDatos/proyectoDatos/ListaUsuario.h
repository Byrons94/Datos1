#pragma once
#include "NodoUsuario.h"
class ListaUsuario
{
private:
	NodoUsuario * cab;
	int tamanio;

	NodoUsuario * dirNodo(char *);
    char * dirCodigoDeNodo(NodoUsuario* nodo);
	NodoUsuario * dirUltimo();


public:
	ListaUsuario();
	~ListaUsuario();
	//sets gets
	void setCab(NodoUsuario *);
	void setTamanio(int);

	NodoUsuario *getCab();
	int getTamanio();

	
	//Metodos propios de clase lista

	void insertarInicio(InfoUsuario *);
	void insertarFinal(InfoUsuario *);
	bool insertarDespuesDe(InfoUsuario *, char*);
	bool insertarAcendente(InfoUsuario *);
	bool insertarDecendente(InfoUsuario *);
	bool insertarIndex(InfoUsuario*, int);


	//eliminar
	bool elimina(char *);
	void vaciar();

	//Estatus
	bool estaVacia();

	//obtener datos
	InfoUsuario* obtenerDato(char*);
	InfoUsuario* obtenerPorIndex( int);

	//Modificar

	bool modificarDatos(char*, InfoUsuario *);
	bool momodificarDatoPorIndex(int, InfoUsuario *);


};

