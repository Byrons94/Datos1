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

	void crearUsuario(InfoUsuario * info);

	bool almacenarUsuarioEnFichero(InfoUsuario * usuario);

	InfoUsuario * iniciarSesion(char * pcodigo, char * pcontrasenna);

	void  cargarUsuarios();

	void ListaUsuario::modificarUsuario(InfoUsuario * usr);

	void  leerFicheroUsuarios();

	void convertirAChar(char * palabra, std::string palabraString);

	int covertirAEntero(char * pcodigo);

};

