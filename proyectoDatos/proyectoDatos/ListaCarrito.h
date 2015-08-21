#pragma once
#include "NodoCarrito.h" 
class ListaCarrito
{
private:
	//atributos
	int tamanio;
	NodoCarrito * cab;

	//metodos privados
	NodoCarrito * dirNodo(char *);
	char * dirCodigoDeNodo(NodoCarrito* nodo);
	NodoCarrito * dirUltimo();
	NodoCarrito * dirAnterior(char *);
	NodoCarrito * dirIndex(int);
	void agregarNodoDespuesDe(NodoCarrito *, NodoCarrito*);
	void agregarNodoAntesDe(NodoCarrito *, NodoCarrito*);
	void borrar(NodoCarrito * );


public:
	//constructores
	ListaCarrito();
	ListaCarrito(NodoCarrito *);
	~ListaCarrito();

	//metodos accesores de la lista
	void setTamanio(int);
	void setCab(NodoCarrito*);
	int getTamanio();
	NodoCarrito *getCab();
	
	void insetarInicio(InfoCarrito *);
	void insertarFinal(InfoCarrito*);
	bool insertarAntesDe(InfoCarrito*, char *);
	bool insertarDespuesDe(InfoCarrito*, char *);
	bool insertarAcendente(InfoCarrito*);
	bool insertarDecendente(InfoCarrito*);
	bool insertarIndex(InfoCarrito*, int);



	bool elimina(char *);
	bool eliminarIndex(int);
	void vaciar();

	bool estaVacia();

	InfoCarrito* obtenerDato(char *);
	InfoCarrito* obtenerPorIndex(int);

	bool modificarDatos(char *, InfoCarrito *);
	bool modificarDatoPorIndex(int, InfoCarrito*);

	void mostrarLista();



};

