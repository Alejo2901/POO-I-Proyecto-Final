#pragma once
#include <iostream>
using namespace std;

class Detalle_Venta
{
private:
	int codDetVenta;
	int cantDetVenta;
	float preDetVenta; 
public:
	Detalle_Venta();
	Detalle_Venta(int,int,float);
	
	
	void setCodDetVenta(int);
	void setCantDetVenta(int);
	void setPreDetVenta(float);
	
	
	int getCodDetVenta();
	int getCantDetVenta();
	float getPreDetVenta();
	
	float getSubTotal();
	
};
