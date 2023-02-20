#pragma once
#include <iostream>
using namespace std;

class Cliente
{
private:
	int codCliente;
	string nomCliente;
	string apelCliente;
	string dniCliente;
	
public:
	Cliente();
	Cliente(int,string,string,string);
	//set
	void setCodCliente(int);
	void setNomCliente(string);
	void setApeCliente(string);
	void setDniCliente(string);
	
	//get
	int getCodCliente();
	string getNomCliente();
	string getApeCliente();
	string getDniCliente();
};
