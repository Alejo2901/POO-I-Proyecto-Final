#include "detalle_venta.h"


Detalle_Venta::Detalle_Venta()
{
	
}
Detalle_Venta::Detalle_Venta(int codDetVenta,int cantDetVenta,float preDetVenta)
{
	this->codDetVenta=codDetVenta;
	this->cantDetVenta=cantDetVenta;
	this->preDetVenta=preDetVenta;
}


void Detalle_Venta::setCodDetVenta(int codDetVenta)
{
	this->codDetVenta=codDetVenta;
}
void Detalle_Venta::setCantDetVenta(int cantDetVenta)
{
	this->cantDetVenta=cantDetVenta;
}
void Detalle_Venta::setPreDetVenta(float preDetVenta)
{
	this->preDetVenta=preDetVenta;
}

int Detalle_Venta::getCodDetVenta()
{
	return codDetVenta;
}
int Detalle_Venta::getCantDetVenta()
{
	return cantDetVenta;
}
float Detalle_Venta::getPreDetVenta()
{
	return preDetVenta;
}

float Detalle_Venta::getSubTotal()
{
	float total;
	
	total= getPreDetVenta()*getCantDetVenta();
	return total;
}
