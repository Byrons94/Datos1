#include "GestorUsuarios.h"
#include "ListaUsuario.h"

GestorUsuarios::GestorUsuarios()
{}

GestorUsuarios::~GestorUsuarios()
{}



void GestorUsuarios::agregarUsuario(char * pnombre, char * pcontrasenna, int prol)
{
	ListaUsuario *lista = new ListaUsuario();
	InfoUsuario *info = new InfoUsuario(pnombre, pcontrasenna, prol);
	lista->crearUsuario(info);
}

//retorna 0 en caso de no existir o el rol del usuario en caso de que exista
int GestorUsuarios::iniciarSesion(char *pcodigo, char *pcontrasena){
	ListaUsuario * lista = new ListaUsuario();
	InfoUsuario * usuario = lista->iniciarSesion(pcodigo, pcontrasena);
	
	if (usuario != NULL)
		return usuario->getRol();
	else
		return 0;
}



