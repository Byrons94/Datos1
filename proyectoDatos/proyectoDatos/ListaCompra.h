#pragma once
#include "NodoCompra.h"

class ListaCompra
{
private:
	NodoCompra *cab;
	int tamanio;

	NodoCompra * dirNodo(char *);
	char * dirCodigoDeNodo(NodoCompra* nodo);
	NodoCompra * dirUltimo();

public:
	ListaCompra();
	ListaCompra(NodoCompra *);
	~ListaCompra();

	void setCab(NodoCompra *);
	void setTamanio(int);

	NodoCompra *getCab();
	int getTamanio();

	//Metodos propios de clase lista

	void insertarInicio(InfoCompra *);
	void insertarFinal(InfoCompra *);
	bool insertarDespuesDe(InfoCompra *, char*);
	bool insertarAcendente(InfoCompra *);
	bool insertarDecendente(InfoCompra *);
	bool insertarIndex(InfoCompra*, int);


	//eliminar
	bool elimina(char *);
	bool agregarProducto(InfoCompra * lineaDetallle);
	bool agregarProductoEspecifico(char * pasillo, char * general, char * especifica, char * producto, int cantidad, double monto);
	void vaciar();

	//Estatus
	bool estaVacia();

	//obtener datos
	InfoCompra* obtenerDato(char*);
	InfoCompra* obtenerPorIndex(int);

	//Modificar

	bool modificarDatos(char*, InfoCompra *);
	bool momodificarDatoPorIndex(int, InfoCompra *);
	void guardarListas();
	bool almacenarListaEnFichero(InfoCompra * lista);
	void cargarCompras(char * codCarrito);
	int leerFicheroCompras(char * codCarrito);
	void convertirAChar(char * palabra, std::string palabraString);
	int covertirAEntero(char * pcodigo);
};

