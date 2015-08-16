#pragma once
#include "stdafx.h"
class InfoArticulo
{
private:
	char	codigo[15];
	char	nombre[15];
	char	marca[15];
	double	tamanio;
	double	precio;

public:
	InfoArticulo();
	~InfoArticulo();
	InfoArticulo(char*, char*, char*, double, double);
	void   setCodigo(char *);
	void   setNombre(char *);
	void   setMarca(char *);
	void   setTamanio(double);
	void   setPrecio(double);
	
	char   *getCodigo();
	char   *getNombre();
	char   *getMarca();
	double getTamanio();
	double getPrecio();

};

