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

	InfoArticulo(int codigoLinea, char * pnombre, char * pmarca, char * ptamanio, double pprecio);

	InfoArticulo(char * pcodigo, char * pnombre, char * pmarca, char * ptamanio, double pprecio);

	InfoArticulo(char * pnombre, char * pmarca, char * ptamanio, double pprecio);
	
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

	char * autoIncrementar();

	int ultimoRegistro();

	void convertirAChar(char * palabra, std::string palabraString);

	int covertirAEntero(char * pcodigo);



};

