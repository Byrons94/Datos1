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
	int	precio;

public:
	InfoArticulo();
	~InfoArticulo();
	InfoArticulo(int, char*, char*, char*, char *, int);



	void   setCodLinea(int);	
	void   setCodigo(char *);
	void   setNombre(char *);
	void   setMarca(char *);
	void   setTamanio(char*);
	void   setPrecio(int);

	int    getCodlinea();
	char   *getCodigo();
	char   *getNombre();
	char   *getMarca();
	char    *getTamanio();
	int getPrecio();


	void convertirAChar(char * palabra, std::string palabraString);

	int covertirAEntero(char * pcodigo);



};

