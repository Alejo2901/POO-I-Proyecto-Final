#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
#include <iostream>
#include "venta.h"

Venta::Venta()
{
	
}
Venta::Venta(int codVenta,int numVenta,int totVenta,string estVenta)
{
	this->codVenta=codVenta;

	this->numVenta=numVenta;
	this->totVenta=totVenta;
	this->estVenta=estVenta;
}

//set
void Venta::setCodVenta(int codVenta)
{
	this->codVenta=codVenta;
}
void Venta::setNumVenta(int numVenta)
{
	this->numVenta=numVenta;
}
void Venta::setTotVenta(int totVenta)
{
	this->totVenta=totVenta;
}
void Venta::setEstVenta(string estVenta)
{
	this->estVenta=estVenta;
}
//get
int Venta::getCodVenta()
{
	return this->codVenta;
}

int Venta::getNumVenta()
{
	return this->numVenta;
}
int Venta::getTotVenta()
{
	return this->totVenta;
}
string Venta::getEstVenta()
{
	return this->estVenta;
}
