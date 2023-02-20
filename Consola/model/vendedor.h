#pragma once
#include <iostream>
using namespace std;

class Vendedor
{
private:
	int codVendedor;
	string nomVendedor;
	string apeVendedor;
	string direVendedor;
	string dniVendedor;
	
public:
	Vendedor();
	Vendedor(int,string,string,string,string);
	//SET
	
	void setCodVendedor(int);
	void setNomVendedor(string);
	void setApeVendedor(string);
	void setDireVendedor(string);
	void setDniVendedor(string);
	
	//GET
	int getCodVendedor();
	string getNomVendedor();
	string getApeVendedor();
	string getDireVendedor();
	string getDniVendedor();
};
