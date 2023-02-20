#pragma once
#include <iostream>
using namespace std;

class Categoria
{
private:
	int codCategoria;
	string nomCategoria;
	
public:
	Categoria();
	Categoria(int,string);
	
	//SET
	void setCodCategoria(int);
	void setNomCategoria(string);
	//GET
	int getCodCategoria();
	string getNomCategoria();
	
	
};
