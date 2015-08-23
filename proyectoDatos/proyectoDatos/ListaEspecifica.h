#pragma once
#include "NodoEspecifica.h"
class ListaEspecifica
{
private:
	NodoEspecifica * cab;
	int tamanio;

	NodoEspecifica * dirNodo(char *);
	NodoEspecifica * dirUltimo();
	NodoEspecifica * dirAnterior(char *);
	NodoEspecifica * dirIndex(int);
	char* dirCodigoDePasillo(NodoEspecifica *);
	// agregar
	void agregarNodoDespuesDe(NodoEspecifica *, NodoEspecifica *);
	void agregarNodoAntesDe(NodoEspecifica *, NodoEspecifica *);


public:
	ListaEspecifica();
	ListaEspecifica(NodoEspecifica *);
	~ListaEspecifica();

	void setTamanio(int);
	void setCab(NodoEspecifica *);

	int getTamanio();
	NodoEspecifica * getCab();
	

	//insertar
	void insetarInicio(InfoEspecifica *);
	void insertarFinal(InfoEspecifica *);
	bool insertarAntesDe(InfoEspecifica *, char *);
	bool insertarDespuesDe(InfoEspecifica *, char *);
	bool insertarAcendente(InfoEspecifica *);
	bool insertarDecendente(InfoEspecifica *);

	void cargarEspecificas(int numLineaGeneral);

	int leerFicheroEspecificas(int numLineaGeneral);

	void convertirAChar(char * palabra, std::string palabraString);

	int covertirAEntero(char * pcodigo);


	//eliminar
	bool elimina(char *);
	bool eliminarIndex(int);
	void vaciar();
	void eliminarNodo(NodoEspecifica *);

	// obtener 
	InfoEspecifica * obtenerDato(char *);
	InfoEspecifica * obtenerPorIndex(int);
	bool estaVacia();

	//modificar
	bool modificarDatos(char *, InfoEspecifica *);

};

