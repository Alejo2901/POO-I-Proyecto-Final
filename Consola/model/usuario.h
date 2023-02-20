#pragma once
#include <iostream>
using namespace std;

class Usuario
{
private:
	string usuario;
	string contra;

public:
	Usuario();
	Usuario(string,string);
	
	void setUsuario(string);
	void setContra(string);
	
	string getUsuario();
	string getContra();

	
	
};
