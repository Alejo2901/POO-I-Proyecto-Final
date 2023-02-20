#include <fstream>
#include <vector>
#include <iostream>
#include "../model/vendedor.cpp"


class VendedorController
{
private:
	vector<Vendedor> vectorVendedor;
	
public:
	
	VendedorController();
	int getCorrelativo();
	void add(Vendedor obj);
	Vendedor get(int pos);
	int size();
	Vendedor buscarPorCodigo(int codigo);
	void grabarEnArchivo(Vendedor obj);
	int getPostArray(Vendedor obj);
	void remove(Vendedor obj);
	bool modificar(Vendedor obj,int,string,string,string,string);
	void grabarModificarEliminarArchivo();
	void cargarDatosDelArchivo();
	
	
};
VendedorController::VendedorController()
{
	cargarDatosDelArchivo();
}
int VendedorController::getCorrelativo()
{
	if(size()==0)
	{
		return 1;
	}
	else 
	{
		return vectorVendedor[size()-1].getCodVendedor()+1;
	}
}
void VendedorController::add(Vendedor obj)
{
	vectorVendedor.push_back(obj);
}
Vendedor VendedorController::get(int pos)
{
	return vectorVendedor[pos];
}
int VendedorController::size()
{
	return vectorVendedor.size();
}
Vendedor VendedorController::buscarPorCodigo(int codigo)
{
	Vendedor objError;
	objError.setNomVendedor("error");
	for(int i =0;i<vectorVendedor.size();i++)
	{
		if(codigo==vectorVendedor[i].getCodVendedor())
		{
			return vectorVendedor[i];
		}
	}
	return objError;
}
void VendedorController::grabarEnArchivo(Vendedor obj)
{
	try
	{
		fstream archivoVendedor;
		archivoVendedor.open("vendedor.csv",ios::app);
		if(archivoVendedor.is_open())
		{
			archivoVendedor<<obj.getCodVendedor()<<";"<<obj.getNomVendedor()<<";"<<obj.getApeVendedor()<<";"<<obj.getDireVendedor()<<";"<<obj.getDniVendedor()<<";"<<endl;
		}
		archivoVendedor.close();
		
	}
	catch(exception e)
	{
		cout<<"Ocurrio un error al momento de Grabar Cliente";
	}
}
int VendedorController::getPostArray(Vendedor obj)
{
	for(int i=0;i<size();i++)
	{
		if(obj.getCodVendedor()==get(i).getCodVendedor())
		{
			return i;
		}
	}
	return -1;
}
void VendedorController::remove(Vendedor obj)
{	
	vectorVendedor.erase(vectorVendedor.begin()+getPostArray(obj));
}
bool VendedorController::modificar(Vendedor obj,int cod,string nom,string ape,string dni,string dire)
{
	
	for(int i=0;i<size();i++)
	{
		if(obj.getCodVendedor()==get(i).getCodVendedor())
		{
			vectorVendedor[i].setCodVendedor(cod);	
			vectorVendedor[i].setNomVendedor(nom);	
			vectorVendedor[i].setApeVendedor(ape);	
			vectorVendedor[i].setDireVendedor(dire);
			vectorVendedor[i].setDniVendedor(dni);	
			
			
			return true;
		}	
		
	}
	return false;
}
void VendedorController::grabarModificarEliminarArchivo()
{
	try
	{
		fstream archivoVendedor;
		archivoVendedor.open("vendedor.csv",ios::out);
		if(archivoVendedor.is_open())
		{
			for(Vendedor x : vectorVendedor)
			{
				archivoVendedor<<x.getCodVendedor()<<";"<<x.getNomVendedor()<<";"<<x.getApeVendedor()<<";"<<x.getDireVendedor()<<";"<<x.getDniVendedor()<<";"<<endl;
			}
		}
		archivoVendedor.close();
	}
	catch(exception e)
	{
		cout<<"Ocurrio un error al Grabar Cliente";
	}
}
void VendedorController::cargarDatosDelArchivo()
{
	try
	{
		int i;
		size_t posi;
		string linea;
		string temporal[5];
		fstream archivoVendedor;
		archivoVendedor.open("vendedor.csv",ios::in);
		
		if(archivoVendedor.is_open())
		{
			while(!archivoVendedor.eof() && getline(archivoVendedor,linea))
			{
				i=0;
				while((posi=linea.find(";")) !=string ::npos)
				{
					temporal[i]=linea.substr(0,posi);
					linea.erase(0,posi+1);
					i++;
				}
				Vendedor objVen;
				
				objVen.setCodVendedor(std::stoi(temporal[0]));
				objVen.setNomVendedor(temporal[1]);
				objVen.setApeVendedor(temporal[2]);
				objVen.setDireVendedor(temporal[3]);
				objVen.setDniVendedor(temporal[4]);
				
				add(objVen);
				
			}
		}
		archivoVendedor.close();
	}
	
	catch(exception e)
	{
		cout<<"Ocurrio un error al momento de Leer Cliente";
	}
}
