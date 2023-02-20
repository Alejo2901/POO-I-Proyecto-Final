#include "../model/detalle_venta.cpp"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class Detalle_VentaController
{
private:
	vector<Detalle_Venta> vectorDeta_Venta;
	
public:
	Detalle_VentaController();
	int getCorrelativo();
	void add(Detalle_Venta obj);
	Detalle_Venta get(int pos);
	int size();
	Detalle_Venta buscarPorCodigo(int codigo);
	void grabarEnArchivo(Detalle_Venta obj);
	int getPostArray(Detalle_Venta obj);
	void remove(Detalle_Venta obj);
	bool modificar(Detalle_Venta obj,int,int,float);
	void grabarModificarEliminarArchivo();
	void cargarDatosDelArchivo();
	
	
};
Detalle_VentaController::Detalle_VentaController()
{
	cargarDatosDelArchivo();
}
int Detalle_VentaController::getCorrelativo()
{
	if(size()==0)
	{
		return 1;
	}
	else 
	{
		return vectorDeta_Venta[size()-1].getCodDetVenta()+1;
	}
}
void Detalle_VentaController::add(Detalle_Venta obj)
{
	vectorDeta_Venta.push_back(obj);
}
Detalle_Venta Detalle_VentaController::get(int pos)
{
	return vectorDeta_Venta[pos];
}
int Detalle_VentaController::size()
{
	return vectorDeta_Venta.size();
}
Detalle_Venta Detalle_VentaController::buscarPorCodigo(int codigo)
{
	Detalle_Venta objError;
	objError.setCodDetVenta(-1);
	for(int i =0;i<vectorDeta_Venta.size();i++)
	{
		if(codigo==vectorDeta_Venta[i].getCodDetVenta())
		{
			return vectorDeta_Venta[i];
		}
	}
	return objError;
}
void Detalle_VentaController::grabarEnArchivo(Detalle_Venta obj)
{
	try
	{
		fstream archivoDetalle_Venta;
		archivoDetalle_Venta.open("detalle_venta.csv",ios::app);
		if(archivoDetalle_Venta.is_open())
		{
			archivoDetalle_Venta<<obj.getCodDetVenta()<<";"<<obj.getCantDetVenta()<<";"<<obj.getPreDetVenta()<<";"<<endl;
		}
		archivoDetalle_Venta.close();
		
	}
	catch(exception e)
	{
		cout<<"Ocurrio un error al momento de Grabar Producto";
	}
}

int Detalle_VentaController::getPostArray(Detalle_Venta obj)
{
	for(int i=0;i<size();i++)
	{
		if(obj.getCodDetVenta()==get(i).getCodDetVenta())
		{
			return i;
		}
	}
	return -1;
}
void Detalle_VentaController::remove(Detalle_Venta obj)
{
	vectorDeta_Venta.erase(vectorDeta_Venta.begin()+getPostArray(obj));
}
bool Detalle_VentaController::modificar(Detalle_Venta obj,int cod,int cant,float prec)
{
	
	for(int i=0;i<size();i++)
	{
		if(obj.getCodDetVenta()==get(i).getCodDetVenta())
		{
			
			vectorDeta_Venta[i].setCodDetVenta(cod);	
			vectorDeta_Venta[i].setCantDetVenta(cant);	
			vectorDeta_Venta[i].setPreDetVenta(prec);	
			return true;
		}	
		
	}
	return false;
}
void Detalle_VentaController::grabarModificarEliminarArchivo()
{
	try
	{
		fstream archivoDetalle_Venta;
		archivoDetalle_Venta.open("detalle_venta.csv",ios::out);
		if(archivoDetalle_Venta.is_open())
		{
			for(Detalle_Venta x : vectorDeta_Venta)
			{
				archivoDetalle_Venta<<x.getCodDetVenta()<<";"<<x.getCantDetVenta()<<";"<<x.getPreDetVenta()<<";"<<endl;
			}
		}
		archivoDetalle_Venta.close();
	}
	catch(exception e)
	{
		cout<<"Ocurrio un error al Grabar Producto";
	}
}
void Detalle_VentaController::cargarDatosDelArchivo()
{
	try
	{
		int i;
		size_t posi;
		string linea;
		string temporal[3];
		fstream archivoDetalle_Venta;
		archivoDetalle_Venta.open("detalle_venta.csv",ios::in);
		
		if(archivoDetalle_Venta.is_open())
		{
			while(!archivoDetalle_Venta.eof() && getline(archivoDetalle_Venta,linea))
			{
				i=0;
				while((posi=linea.find(";")) !=string ::npos)
				{
					temporal[i]=linea.substr(0,posi);
					linea.erase(0,posi+1);
					i++;
				}
				Detalle_Venta objDet_Ven;
				
				objDet_Ven.setCodDetVenta(std::stoi(temporal[0]));
				objDet_Ven.setCantDetVenta(std::stoi(temporal[1]));
				objDet_Ven.setPreDetVenta(std::stoi(temporal[2]));
				objDet_Ven.getSubTotal();
				add(objDet_Ven);
				
			}
		}
		archivoDetalle_Venta.close();
	}
	
	catch(exception e)
	{
		cout<<"Ocurrio un error al momento de Leer Producto";
	}
	
}
