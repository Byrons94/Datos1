#pragma once
#include "stdafx.h"
class InfoArticulo
{
private:
	int     lineaEspecifica;
	char	codigo[15];
	char	nombre[30];
	char	marca[30];
	char	tamanio[30];
	double	precio;

public:
	InfoArticulo();
	~InfoArticulo();
	InfoArticulo(int, char*, char*, char*, char *, double);
	
	void   setCodLinea(int);	
	void   setCodigo(char *);
	void   setNombre(char *);
	void   setMarca(char *);
	void   setTamanio(char*);
	void   setPrecio(double);

	int    getCodlinea();
	char   *getCodigo();
	char   *getNombre();
	char   *getMarca();
	char    *getTamanio();
	double getPrecio();



};

