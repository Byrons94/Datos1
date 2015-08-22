#pragma once
#include "ListaCarrito.h"
class GestorCompras
{
public:
	GestorCompras();
	~GestorCompras();

	ListaCarrito * crearPedido();
	void * almacenarPedido();
	ListaCarrito * cargarPedidosUsuario(char * codigoUsuario);
};

