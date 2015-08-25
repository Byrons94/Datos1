#pragma once
#include "stdafx.h"
class InfoUsuario
{
private: 
	char  codigo[15];
	char nombre[15];
	char contrasenna[15];
	int rol; //1 admin, 2 // dependiente, // 3 cliente


public:
	InfoUsuario();
	InfoUsuario(char *, char * , char*, int);
	InfoUsuario(char * pnombre, char * pcontrasenna, int prol);
	~InfoUsuario();
	
	void setCodigo(char *);
	void setNombre(char *);
	void setContrasenna(char *);
	void setRol(int);

	char * getCodigo();
	char * getNombre();
	char * getContrasenna();
	int    getRol();

	char  * autoIncrementar();

	int ultimoRegistro();

	void convertirAChar(char * palabra, std::string palabraString);

	int covertirAEntero(char * pcodigo);

};

