#pragma once
#include "ListaCarrito.h"
class GestorCompras
{
public:
	GestorCompras();
	~GestorCompras();

	ListaCarrito * crearCarrito();

	ListaCompra * creaListaCompras();

	bool agregarProductoALista(char * pasillo, char * lgeneral, char * lespecifica, char * codprod, int cantidad, double monto, ListaCompra * lista);

	bool sacarProducto(ListaCompra * lista, char * codProd);

	bool editarCantProduc(int cantidad, InfoCompra * lista, double monto);

	void agregarListaCompras(ListaCarrito * carrito, char * codigo, char * nombre, char * codClie, bool estado, double monto, ListaCompra * listaCompra);


	ListaCarrito * crearPedido();
	void * almacenarPedido();
	ListaCarrito * cargarPedidosUsuario(char * codigoUsuario);
};
