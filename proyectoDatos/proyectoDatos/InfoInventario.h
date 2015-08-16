#pragma once
class InfoInventario
{
private:
	char *codigo;
	char *descripcion;
	int  largo;

public:
	InfoInventario();
	InfoInventario(char*, char*, int);
	~InfoInventario();

	void setCodigo(char *);
	void setDescripcion(char *);
	void setLargo(int);

	char *getCodigo();
	char *getDescripcion();
	int getLargo();
};

