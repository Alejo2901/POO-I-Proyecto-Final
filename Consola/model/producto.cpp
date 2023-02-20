#include "producto.h"

Producto::Producto()
{
	
}

Producto::Producto(int codigoPro,string nombrePro,string descriPro,float costoPro,int cantPro)
{
	this->codigoPro=codigoPro;
	this->nombrePro=nombrePro;
	this->descriPro=descriPro;
	this->costoPro=costoPro;
	this->cantPro=cantPro;
}
//Set
void Producto::setCodigoPro(int codigoPro)
{
	this->codigoPro=codigoPro;
}
void Producto::setNombrePro(string nombrePro)
{
	this->nombrePro=nombrePro;
}
void Producto::setDescriPro(string descriPro)
{
	this->descriPro=descriPro;
}
void Producto::setCostoPro(float costoPro)
{
	this->costoPro=costoPro;
}
void Producto::setCantPro(int cantPro)
{
	this->cantPro=cantPro;
}
//Get
int Producto::getCodigoPro()
{
	return codigoPro;
}
string Producto::getNombrePro()
{
	return nombrePro;
}
string Producto::getDescriPro()
{
	return descriPro;
}
float Producto::getCostoPro()
{
	return costoPro;
}
int Producto::getCantPro()
{
	return cantPro;
}
