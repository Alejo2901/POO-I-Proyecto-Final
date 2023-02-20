#pragma once
#include "cliente.h"


Cliente::Cliente()
{
	
}
Cliente::Cliente(int codCliente,string nomCliente,string apelCliente,string dniCliente)
{
	this->codCliente=codCliente;
	this->nomCliente=nomCliente;
	this->apelCliente=apelCliente;
	this->dniCliente=dniCliente;
	
	
}
//set
void Cliente::setCodCliente(int codCliente)
{
	this->codCliente=codCliente;
}
void Cliente::setNomCliente(string nomCliente)
{
	this->nomCliente=nomCliente;
}
void Cliente::setApeCliente(string apelCliente)
{
	this->apelCliente=apelCliente;
}
void Cliente::setDniCliente(string dniCliente)
{
	this->dniCliente=dniCliente;
}

//get
int Cliente::getCodCliente()
{
	return codCliente;
}
string Cliente::getNomCliente()
{
	return nomCliente;
}
string Cliente::getApeCliente()
{
	return apelCliente;
}
string Cliente::getDniCliente()
{
	return dniCliente;
}
