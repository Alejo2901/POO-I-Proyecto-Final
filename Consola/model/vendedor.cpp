#include "vendedor.h"


Vendedor::Vendedor()
{
	
}
Vendedor::Vendedor(int codVendedor,string nomVendedor,string apeVendedor,string direVendedor,string dniVendedor)
{
	this->codVendedor=codVendedor;
	this->nomVendedor=nomVendedor;
	this->apeVendedor=apeVendedor;
	this->direVendedor=direVendedor;
	this->dniVendedor=dniVendedor;
}
//SET

void Vendedor::setCodVendedor(int codVendedor)
{
	this->codVendedor=codVendedor;
}
void Vendedor::setNomVendedor(string nomVendedor)
{
	this->nomVendedor=nomVendedor;
}
void Vendedor::setApeVendedor(string apeVendedor)
{
	this->apeVendedor=apeVendedor;
}
void Vendedor::setDireVendedor(string direVendedor)
{
	this->direVendedor=direVendedor;
}
void Vendedor::setDniVendedor(string dniVendedor)
{
	this->dniVendedor=dniVendedor;
}

//GET
int Vendedor::getCodVendedor()
{
	return codVendedor;
}
string Vendedor::getNomVendedor()
{
	return nomVendedor;
}
string Vendedor::getApeVendedor()
{
	return apeVendedor;
}
string Vendedor::getDireVendedor()
{
	return direVendedor;
}
string Vendedor::getDniVendedor()
{
	return dniVendedor;
}
