#pragma once
#include <iostream>
using namespace std;

class Venta
{
private:
	int codVenta;
	
	int numVenta;
	int totVenta;
	string estVenta;
	
public:
	Venta();
	Venta(int,int,int,string);
	
	//set
	void setCodVenta(int);
	
	void setNumVenta(int);
	void setTotVenta(int);
	void setEstVenta(string);
	//get
	int getCodVenta();

	int getNumVenta();
	int getTotVenta();
	string getEstVenta();
	
};
