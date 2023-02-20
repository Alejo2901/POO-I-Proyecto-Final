#include <iostream>
#include <fstream>
#include <vector>
#include "../model/categoria.cpp"

using std::stoi;
using namespace std;

class CategoriaController
{
private:
	vector<Categoria> vectorCategoria;
	
	
public:
	CategoriaController();
	int getCorrelativo();
	void add(Categoria obj);
	Categoria get(int pos);
	int size();
	Categoria buscarPorCodigo(int codigo);
	void grabarEnArchivo(Categoria obj);
	int getPostArray(Categoria obj);
	void remove(Categoria obj);
	bool modificar(Categoria obj,int,string);
	void grabarModificarEliminarArchivo();
	void cargarDatosDelArchivo();
	
};
CategoriaController::CategoriaController()
{
	cargarDatosDelArchivo();
}
int CategoriaController::getCorrelativo()
{
	if(size()==0)
	{
		return 1;
	}
	else 
	{
		return vectorCategoria[size()-1].getCodCategoria()+1;
	}
}
void CategoriaController::add(Categoria obj)
{
	vectorCategoria.push_back(obj);
}
Categoria CategoriaController::get(int pos)
{
	return vectorCategoria[pos];
}
int CategoriaController::size()
{
	return vectorCategoria.size();
}
Categoria CategoriaController::buscarPorCodigo(int codigo)
{
	Categoria objError;
	objError.setNomCategoria("error");
	for(int i =0;i<vectorCategoria.size();i++)
	{
		if(codigo==vectorCategoria[i].getCodCategoria())
		{
			return vectorCategoria[i];
		}
	}
	return objError;
}
//Grabar
void CategoriaController::grabarEnArchivo(Categoria obj)
{
	try
	{
		fstream archivoCategoria;
		archivoCategoria.open("categoria.csv",ios::app);
		if(archivoCategoria.is_open())
		{
			archivoCategoria<<obj.getCodCategoria()<<";"<<obj.getNomCategoria()<<";"<<endl;
		}
		archivoCategoria.close();
		
	}
	catch(exception e)
	{
		cout<<"Ocurrio un error al momento de Grabar Producto";
	}
}
int CategoriaController::getPostArray(Categoria obj)
{
	for(int i=0;i<size();i++)
	{
		if(obj.getCodCategoria()==get(i).getCodCategoria())
		{
			return i;
		}
	}
	return -1;
}
void CategoriaController::remove(Categoria obj)
{
	vectorCategoria.erase(vectorCategoria.begin()+getPostArray(obj));
}
bool CategoriaController::modificar(Categoria obj,int cod,string nom)
{
	
	for(int i=0;i<size();i++)
	{
		if(obj.getCodCategoria()==get(i).getCodCategoria())
		{
			vectorCategoria[i].setCodCategoria(cod);	
			vectorCategoria[i].setNomCategoria(nom);
			
			return true;
		}	
		
	}
	return false;
}

void CategoriaController::grabarModificarEliminarArchivo()
{
	try
	{
		fstream archivoCategoria;
		archivoCategoria.open("categoria.csv",ios::out);
		if(archivoCategoria.is_open())
		{
			for(Categoria x : vectorCategoria)
			{
				archivoCategoria<<x.getCodCategoria()<<";"<<x.getNomCategoria()<<";"<<endl;
			}
		}
		archivoCategoria.close();
	}
	catch(exception e)
	{
		cout<<"Ocurrio un error al Grabar Producto";
	}
}
void CategoriaController::cargarDatosDelArchivo()
{
	
	try
	{
		int i;
		size_t posi;
		string linea;
		string temporal[2];
		fstream archivoCategoria;
		archivoCategoria.open("categoria.csv",ios::in);
		
		if(archivoCategoria.is_open())
		{
			while(!archivoCategoria.eof() && getline(archivoCategoria,linea))
			{
				i=0;
				while((posi=linea.find(";")) !=string ::npos)
				{
					temporal[i]=linea.substr(0,posi);
					linea.erase(0,posi+1);
					i++;
				}
				Categoria objPro;
				
				objPro.setCodCategoria(std::stoi(temporal[0]));
				objPro.setNomCategoria(temporal[1]);
				
				add(objPro);
				
			}
		}
		archivoCategoria.close();
	}
	
	catch(exception e)
	{
		cout<<"Ocurrio un error al momento de Leer Producto";
	}
	
	
	
	
	
	
}
