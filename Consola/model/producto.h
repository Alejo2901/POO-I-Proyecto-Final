#pragma once
#include <iostream>

using namespace std;


class Producto
{
private:
	int codigoPro;
	string nombrePro;
	string descriPro;
	float costoPro;
	int cantPro;
	
public:
	Producto();
	Producto(int,string,string,float,int);
	//Set
	void setCodigoPro(int);
	void setNombrePro(string);
	void setDescriPro(string);
	void setCostoPro(float);
	void setCantPro(int);
	//Get
	int getCodigoPro();
	string getNombrePro();
	string getDescriPro();
	float getCostoPro();
	int getCantPro();
	
	
};
