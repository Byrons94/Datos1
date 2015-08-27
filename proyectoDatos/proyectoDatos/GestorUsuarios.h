#pragma once

class GestorUsuarios
{
public:
	GestorUsuarios();
	~GestorUsuarios();


	void agregarUsuario(char * , char * , char * , int );
	int iniciarSesion(char *, char *);
};

