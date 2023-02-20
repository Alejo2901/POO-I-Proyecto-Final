#include <iostream>
#include <vector>
#include <fstream>
#include "../model/venta.cpp"
using std::stoi;
using namespace std;

class VentaController
{
private:
	vector<Venta> vectorVenta;
	
public:
	VentaController();
	int getCorrelativo();
	void add(Venta obj);
	Venta get(int pos);
	int size();
	int getPostArray(Venta obj);
	void remove(Venta obj);
	bool modificar(Venta obj,int,int,int,string);
	void grabarEnArchivo(Venta obj);
	void cargarDatosDelArchivo();
	
};
VentaController::VentaController()
{
	cargarDatosDelArchivo();
}
int VentaController::getCorrelativo()
{
	if(size()==0)
	{
		return 1;
	}
	else 
	{
		return vectorVenta[size()-1].getCodVenta()+1;
	}
}
void VentaController::add(Venta obj)
{
	vectorVenta.push_back(obj);
}
Venta VentaController::get(int pos)
{
	return vectorVenta[pos];
}
int VentaController::size()
{
	return vectorVenta.size();
}
int VentaController::getPostArray(Venta obj)
{
	for(int i=0;i<size();i++)
	{
		if(obj.getCodVenta()==get(i).getCodVenta())
		{
			return i;
		}
	}
	return -1;
}
void VentaController::remove(Venta obj)
{
	vectorVenta.erase(vectorVenta.begin()+getPostArray(obj));
}
bool VentaController::modificar(Venta obj,int cod,int num,int tot,string est)
{
	for(int i=0;i<size();i++)
	{
		if(obj.getCodVenta()==get(i).getCodVenta())
		{
			vectorVenta[i].setCodVenta(cod);	
			vectorVenta[i].setNumVenta(num);	
			vectorVenta[i].setTotVenta(tot);	
			vectorVenta[i].setEstVenta(est);	
			
			return true;
		}	
		
	}
	return false;
}
void VentaController::grabarEnArchivo(Venta obj)
{
	try
	{
		fstream archivoVenta;
		archivoVenta.open("venta.csv",ios::app);
		if(archivoVenta.is_open())
		{
			archivoVenta<<obj.getCodVenta()<<";"<<";"<<obj.getNumVenta()<<";"<<obj.getTotVenta()<<";"<<obj.getEstVenta()<<";"<<endl;
		}
		archivoVenta.close();
		
	}
	catch(exception e)
	{
		cout<<"Ocurrio un error al momento de Grabar Producto";
	}
}
void VentaController::cargarDatosDelArchivo()
{
	try
	{
		int i;
		size_t posi;
		string linea;
		string temporal[4];
		fstream archivoVenta;
		archivoVenta.open("venta.csv",ios::in);
		
		if(archivoVenta.is_open())
		{
			while(!archivoVenta.eof() && getline(archivoVenta,linea))
			{
				i=0;
				while((posi=linea.find(";")) !=string ::npos)
				{
					temporal[i]=linea.substr(0,posi);
					linea.erase(0,posi+1);
					i++;
				}
				Venta objVen;
				
				objVen.setCodVenta(std::stoi(temporal[0]));
				objVen.setNumVenta(std::stoi(temporal[2]));
				objVen.setTotVenta(std::stoi(temporal[3]));
				objVen.setEstVenta(temporal[4]);
				
				add(objVen);
				
			}
		}
		archivoVenta.close();
	}
	
	catch(exception e)
	{
		cout<<"Ocurrio un error al momento de Leer Producto";
	}
	
}
