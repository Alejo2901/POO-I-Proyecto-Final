#include "categoria.h"

Categoria::Categoria()
{
	
}
Categoria::Categoria(int codCategoria,string nomCategoria)
{
	this->codCategoria=codCategoria;
	this->nomCategoria=nomCategoria;
}

//SET
void Categoria::setCodCategoria(int codCategoria)
{
	this->codCategoria=codCategoria;
}
void Categoria::setNomCategoria(string nomCategoria)
{
	this->nomCategoria=nomCategoria;
}
//GET
int Categoria::getCodCategoria()
{
	return codCategoria;
}
string Categoria::getNomCategoria()
{
	return nomCategoria;
}
