
#include "GestorInventario.h"

#include "stdlib.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

GestorInventario::GestorInventario(){}
GestorInventario::~GestorInventario(){}

ListaArticulo* GestorInventario::cargarArticulos() {
	ListaArticulo *listaTotal = leerFicheroArticulos();
	return listaTotal;
}

ListaArticulo * GestorInventario::leerFicheroArticulos() {
	ListaArticulo *lista = new ListaArticulo();
	
	std::ifstream lectura;
	char codigo[15], nombre[15], marca[15];
	double tamanio =0 , precio = 0;
	lectura.open("Ficheros/articulos.txt", std::ios::out | std::ios::in);
	//InfoArticulo *articulo;
	if (lectura.is_open()) {
		lectura >> codigo;  //primer registro de la linea
		std::string linea;		//contador de las lineas del documento
		while (getline(lectura, linea)){
			std::stringstream ss(linea); //nos da un el elemento por linea
			std::string palabraString;   // lo definimos para almacenar el dato del txt
			
			std::string str(codigo);
			str.erase(str.find(";"));
			strcpy_s(codigo, str.c_str());

			getline(ss, palabraString, ';');
			convertirAChar(nombre, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(marca, palabraString);
			
			double tamanio;
			ss >> tamanio;
			char ch; // ignora el siguiente campo
			ss >> ch;
			double precio;
			ss >> precio;
			ss >> ch;
			//creamos los objetos
			//articulo = new InfoArticulo(0,codigo, nombre, marca, tamanio, precio);
			//lista->insertarAcendente(articulo); //los anadimos a la lista
			lectura >> codigo;
		}
		lectura.close();
		return lista;
	}
	else {
		return NULL;
	}
}


ListaPasillos* GestorInventario::cargarPasillos() {
	ListaPasillos *listaTotal = leerFicheroPasillos();
	return listaTotal;
}

ListaPasillos * GestorInventario::leerFicheroPasillos() {
	ListaPasillos *lista = new ListaPasillos();

	std::ifstream lectura;
	char numero[5], codigo[15], descripcion[30];

	lectura.open("Ficheros/pasillos.txt", std::ios::out | std::ios::in);
	InfoPasillo *pasillo;

	if (lectura.is_open()) {
		lectura >> numero;  //primer registro de la linea
		std::string linea;		//contador de las lineas del documento

		while (getline(lectura, linea)) {
			std::stringstream ss(linea); //nos da un el elemento por linea
			std::string palabraString;   // lo definimos para almacenar el dato del txt
			
			std::string str(numero);
			str.erase(str.find(';'));
			strcpy_s(numero, str.c_str());

			getline(ss, palabraString, ';');
			convertirAChar(codigo, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(descripcion, palabraString);

			pasillo = new InfoPasillo(covertirAEntero(numero), codigo, descripcion);
			lista->insertarDecendente(pasillo); //los anadimos a la lista
			lectura >> numero;
		}
		lectura.close();
		return lista;
	}
	else {
		return NULL;
	}
}


void GestorInventario::convertirAChar(char *palabra, std::string palabraString){
	palabraString.erase(palabraString.find(' '), 1); //elimina los espacios en blanco que se hacen al principio
	std::memcpy(palabra, palabraString.c_str(), palabraString.size() + 1); // convierte el string en char array
}

int GestorInventario::covertirAEntero(char * pcodigo) {
	int num = atoi(pcodigo);
	return num;
}






