#include "InfoArticulo.h"
#include "stdafx.h"


class NodoArticulo
{
private:
	InfoArticulo *info;
	NodoArticulo *sgte;
	NodoArticulo *ante;

public:
	NodoArticulo();
	~NodoArticulo();

	NodoArticulo(InfoArticulo * );

	void setSgte(NodoArticulo *);
	void setAnte(NodoArticulo *);
	void setInfo(InfoArticulo *);

	NodoArticulo * getSgte();
	NodoArticulo * getAnte();
	InfoArticulo * getInfo();
};

