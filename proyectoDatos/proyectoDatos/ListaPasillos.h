#pragma once
#include "NodoPasillo.h"
#include "stdafx.h"
#include "stdlib.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

class ListaPasillos
{
private:
	//atributos
	NodoPasillo * cab;
	int tamanio;

	//dir
	NodoPasillo * dirNodo(char *);
	NodoPasillo * dirUltimo();
	NodoPasillo * dirAnterior(char *);
	NodoPasillo * dirIndex(int);
	char* dirCodigoDePasillo(NodoPasillo *);
	// agregar
	void agregarNodoDespuesDe(NodoPasillo *, NodoPasillo *);
	void agregarNodoAntesDe(NodoPasillo *, NodoPasillo *);

	int convertirAEntero(char * pcodigo);

public:
	ListaPasillos();
	~ListaPasillos();
	
	//sets
	void setCab(NodoPasillo *);
	void setTamanio(int);

	//gets
	NodoPasillo * getCab();
	int getTamanio();

	//insertar
	void insetarInicio(InfoPasillo *);
	void insertarFinal(InfoPasillo *);
	bool insertarAntesDe(InfoPasillo *, char *);
	bool insertarDespuesDe(InfoPasillo *, char *);
	bool insertarAcendente(InfoPasillo *);
	bool insertarDecendente(InfoPasillo *);


	void cargarPasillos();

	int leerFicheroPasillos();

	
	void convertirAChar(char * palabra, std::string palabraString);

	int covertirAEntero(char * pcodigo);



	//eliminar
	bool elimina(char *);
	bool eliminarIndex(int);
	void vaciar();
	void eliminarNodo(NodoPasillo *);

	// obtener 
	InfoPasillo* obtenerDato(char *);
	InfoPasillo* obtenerPorIndex(int );
	bool estaVacia();

	//modificar
	bool modificarDatos(char *, InfoPasillo * );

};

