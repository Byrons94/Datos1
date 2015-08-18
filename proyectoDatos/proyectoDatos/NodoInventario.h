#pragma once
#include "InfoInventario.h"
#include "stdafx.h"

class NodoInventario
{
private:
	NodoInventario *sgte;
	NodoInventario *ante;
	InfoInventario *info;

public:
	NodoInventario();
	NodoInventario(InfoInventario *);
	~NodoInventario();

	void setSgte(NodoInventario *);
	void setAnte(NodoInventario *);
	void setInfo(InfoInventario *);

	NodoInventario *getSgte();
	NodoInventario *getAnte();
	InfoInventario *getInfo();

};

