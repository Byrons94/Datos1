#pragma once
#include "stdafx.h"
#include "InfoGenerales.h"

class NodoGenerales
{

private:
	NodoGenerales *sgte;
	NodoGenerales *ante;
	InfoGenerales *infoGenerales;

public:
	NodoGenerales();
	NodoGenerales(InfoGenerales *);
	~NodoGenerales();

	void setSgte(NodoGenerales *);
	void setAnte(NodoGenerales *);
	void setInfoGenerales(InfoGenerales *);

	NodoGenerales *getSgte();
	NodoGenerales *getAnte();
	InfoGenerales *getInfo();

};

