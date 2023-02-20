#include "usuario.h"
#include"../model/sha256.cpp"

Usuario::Usuario()
{
	
}
Usuario::Usuario(string usuario,string contra)
{
	this->usuario=usuario;
	this->contra=contra;

	
}

void Usuario::setUsuario(string usuario)
{
	this->usuario=usuario;
}
void Usuario::setContra(string contra)
{
	this->contra=contra;
}

string Usuario::getUsuario()
{
	return this->usuario;
}
string Usuario::getContra()
{
	
	
	return this->contra;
}

