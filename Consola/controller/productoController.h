#include <iostream>
#include<fstream>
#include<vector>
#include "../model/producto.cpp"
using std::stoi;
using namespace std;

class ProductoController
{
private:
	vector<Producto> vectorProducto;

	
public:
	ProductoController();
	int getCorrelativo();
	void add(Producto obj);
	Producto get(int pos);
	int size();
	Producto buscarPorCodigo(int codigo);
	Producto buscarPorNombre(string nombre);
	void grabarEnArchivo(Producto obj);
	int getPostArray(Producto obj);
	void remove(Producto obj);
	bool modificar(Producto obj,int,string,string,float,int);
	void grabarModificarEliminarArchivo();
	void cargarDatosDelArchivo();
	
};
ProductoController::ProductoController()
{
	cargarDatosDelArchivo();
}
int ProductoController::getCorrelativo()
{
	if(size()==0)
	{
		return 1;
	}
	else 
	{
		return vectorProducto[size()-1].getCodigoPro()+1;
	}
}
void ProductoController::add(Producto obj)
{
	vectorProducto.push_back(obj);
}
Producto ProductoController::get(int pos)
{
	return vectorProducto[pos];
}
int ProductoController::size()
{
	return vectorProducto.size();
}
Producto ProductoController::buscarPorCodigo(int codigo)
{
	Producto objError;
	objError.setNombrePro("error");
	for(int i =0;i<vectorProducto.size();i++)
	{
		if(codigo==vectorProducto[i].getCodigoPro())
		{
			return vectorProducto[i];
		}
	}
	return objError;
}
Producto ProductoController::buscarPorNombre(string nombre)
{
	Producto objError;
	objError.setNombrePro("error");
	for(int i =0;i<vectorProducto.size();i++)
	{
		if(nombre==vectorProducto[i].getNombrePro())
		{
			return vectorProducto[i];
		}
	}
	return objError;
}
//Grabar
void ProductoController::grabarEnArchivo(Producto obj)
{
	try
	{
		fstream archivoProducto;
		archivoProducto.open("producto.csv",ios::app);
		if(archivoProducto.is_open())
		{
			archivoProducto<<obj.getCodigoPro()<<";"<<obj.getNombrePro()<<";"<<obj.getDescriPro()<<";"<<obj.getCostoPro()<<";"<<obj.getCantPro()<<";"<<endl;
		}
		archivoProducto.close();
		
	}
	catch(exception e)
	{
		cout<<"Ocurrio un error al momento de Grabar Producto";
	}
}
int ProductoController::getPostArray(Producto obj)
{
	for(int i=0;i<size();i++)
	{
		if(obj.getCodigoPro()==get(i).getCodigoPro())
		{
			return i;
		}
	}
	return -1;
}
void ProductoController::remove(Producto obj)
{
	vectorProducto.erase(vectorProducto.begin()+getPostArray(obj));
}
bool ProductoController::modificar(Producto obj,int cod,string nom,string des,float cost,int cant)
{

	for(int i=0;i<size();i++)
	{
		if(obj.getCodigoPro()==get(i).getCodigoPro())
		{
			
			vectorProducto[i].setCodigoPro(cod);	
			vectorProducto[i].setNombrePro(nom);	
			vectorProducto[i].setDescriPro(des);	
			vectorProducto[i].setCostoPro(cost);	
			vectorProducto[i].setCantPro(cant);	
			
			return true;
		}	
		
	}
	return false;
}

void ProductoController::grabarModificarEliminarArchivo()
{
	try
	{
		fstream archivoProducto;
		archivoProducto.open("producto.csv",ios::out);
		if(archivoProducto.is_open())
		{
			for(Producto x : vectorProducto)
			{
				archivoProducto<<x.getCodigoPro()<<";"<<x.getNombrePro()<<";"<<x.getDescriPro()<<";"<<x.getCostoPro()<<";"<<x.getCantPro()<<";"<<endl;
			}
		}
		archivoProducto.close();
	}
	catch(exception e)
	{
		cout<<"Ocurrio un error al Grabar Producto";
	}
}
void ProductoController::cargarDatosDelArchivo()
{
	
	try
	{
		int i;
		size_t posi;
		string linea;
		string temporal[5];
		fstream archivoProducto;
		archivoProducto.open("producto.csv",ios::in);
		
		if(archivoProducto.is_open())
		{
			while(!archivoProducto.eof() && getline(archivoProducto,linea))
			{
				i=0;
				while((posi=linea.find(";")) !=string ::npos)
				{
					temporal[i]=linea.substr(0,posi);
					linea.erase(0,posi+1);
					i++;
				}
				Producto objPro;
				
				objPro.setCodigoPro(std::stoi(temporal[0]));
				objPro.setNombrePro(temporal[1]);
				objPro.setDescriPro(temporal[2]);
				objPro.setCostoPro(std::stoi(temporal[3]));
				objPro.setCantPro(std::stoi(temporal[4]));
				
				add(objPro);
				
			}
		}
		archivoProducto.close();
	}
	
	catch(exception e)
	{
		cout<<"Ocurrio un error al momento de Leer Producto";
	}
	
	
	
	
	
	
}
