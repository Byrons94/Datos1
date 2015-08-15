#pragma once
class InfoArticulo
{
private:
	char	*codigo;
	char	*nombre;
	char	*marca ;
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

