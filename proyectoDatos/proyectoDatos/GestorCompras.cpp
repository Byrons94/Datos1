#include "GestorCompras.h"
#include "colaEntregas.h"


GestorCompras::GestorCompras()
{}

GestorCompras::~GestorCompras()
{}
 

ListaCarrito * GestorCompras::crearCarrito(){
	return new ListaCarrito();  
}

ListaCompra * GestorCompras::creaListaCompras() {
	return new ListaCompra();
}

bool GestorCompras::agregarProductoALista(char *pasillo, char* lgeneral,
	char* lespecifica, char *codprod, int cantidad, double monto, ListaCompra * listaCompra) {
	InfoCompra *lista = new InfoCompra(pasillo, lgeneral, lespecifica, codprod, cantidad, monto);
	bool existe = listaCompra->agregarProducto(lista);
	return existe;
}

bool GestorCompras::sacarProducto(ListaCompra *lista, char *codProd) {
	return lista->elimina(codProd);
}

bool GestorCompras::editarCantProduc(int cantidad, InfoCompra * lista, double monto){
	lista->setCantidad(cantidad);
	lista->setMonto(monto);
	return true;
}

void GestorCompras::agregarListaCompras(ListaCarrito *carrito, char* codigo, char * nombre,
	char * codClie, bool estado, double monto, ListaCompra * listaCompra){
	carrito->agregarListaCompra(codigo, nombre, codClie, estado, monto, listaCompra);
	carrito->guardarCarritos();
}

void vaciarCarrito(ListaCarrito * carrito){
	carrito->vaciar();
}

ListaCarrito * GestorCompras::obtenerCarritoUsuario(char *codUsuario){
	ListaCarrito * lista = new ListaCarrito();
	lista->cargarCarritosUsuario(codUsuario);
	return lista;
}

ColaEntregas * GestorCompras::obtenerCarritosPendientes(){
	ColaEntregas *colaPendientes = new ColaEntregas();
	colaPendientes->cargarColaPendientes();
	return colaPendientes;
}




/*
***agregar un producto al carrito
***eliminar un producto del carrito
***modificar la cantidad de productos del carrito

***agregar una lista de compras al carrito
***eliminar la lista de compras del carrito
**vaciar el carrito

**buscar las compras de un usuario
**buscar las compras sin entregar


preparar entrega(recorre todos los pasillos)
aplicar entrega(cola)

guardar un carrito
eliminar un carrito no guardado
**comprar
*/
