#include <iostream>
#include<fstream>
#include<vector>
#include "../model/cliente.cpp"
using std::stoi;
using namespace std;


class ClienteController
{
private:
	vector<Cliente> vectorCliente;
	
public:	
	ClienteController();
	int getCorrelativo();
	void add(Cliente obj);
	Cliente get(int pos);
	int size();
	Cliente buscarPorCodigo(int codigo);
	Cliente buscarPorNombre(string nombre);
	void grabarEnArchivo(Cliente obj);
	int getPostArray(Cliente obj);
	void remove(Cliente obj);
	bool modificar(Cliente obj,int,string,string,string);
	void grabarModificarEliminarArchivo();
	void cargarDatosDelArchivo();
	
	
};
ClienteController::ClienteController()
{
	cargarDatosDelArchivo();
}
int ClienteController::getCorrelativo()
{
	if(size()==0)
	{
		return 1;
	}
	else 
	{
		return vectorCliente[size()-1].getCodCliente()+1;
	}
}
void ClienteController::add(Cliente obj)
{
	vectorCliente.push_back(obj);
}
Cliente ClienteController::get(int pos)
{
	return vectorCliente[pos];
}
int ClienteController::size()
{
	return vectorCliente.size();
}
Cliente ClienteController::buscarPorCodigo(int codigo)
{
	Cliente objError;
	objError.setNomCliente("error");
	for(int i =0;i<vectorCliente.size();i++)
	{
		if(codigo==vectorCliente[i].getCodCliente())
		{
			return vectorCliente[i];
		}
	}
	return objError;
}
Cliente ClienteController::buscarPorNombre(string nombre)
{
	Cliente objError;
	objError.setNomCliente("error");
	for(int i =0;i<vectorCliente.size();i++)
	{
		if(nombre==vectorCliente[i].getNomCliente())
		{
			return vectorCliente[i];
		}
	}
	return objError;
}
void ClienteController::grabarEnArchivo(Cliente obj)
{
	try
	{
		fstream archivoCliente;
		archivoCliente.open("cliente.csv",ios::app);
		if(archivoCliente.is_open())
		{
			archivoCliente<<obj.getCodCliente()<<";"<<obj.getNomCliente()<<";"<<obj.getApeCliente()<<";"<<obj.getDniCliente()<<";"<<endl;
		}
		archivoCliente.close();
		
	}
	catch(exception e)
	{
		cout<<"Ocurrio un error al momento de Grabar Cliente";
	}
}
int ClienteController::getPostArray(Cliente obj)
{
	for(int i=0;i<size();i++)
	{
		if(obj.getCodCliente()==get(i).getCodCliente())
		{
			return i;
		}
	}
	return -1;
}
void ClienteController::remove(Cliente obj)
{
	vectorCliente.erase(vectorCliente.begin()+getPostArray(obj));
}
bool ClienteController::modificar(Cliente obj,int cod,string nom,string ape,string dni)
{
	
	for(int i=0;i<size();i++)
	{
		if(obj.getCodCliente()==get(i).getCodCliente())
		{
			vectorCliente[i].setCodCliente(cod);	
			vectorCliente[i].setNomCliente(nom);	
			vectorCliente[i].setApeCliente(ape);	
			vectorCliente[i].setDniCliente(dni);	
	
			
			return true;
		}	
		
	}
	return false;
}
void ClienteController::grabarModificarEliminarArchivo()
{
	try
	{
		fstream archivoCliente;
		archivoCliente.open("cliente.csv",ios::out);
		if(archivoCliente.is_open())
		{
			for(Cliente x : vectorCliente)
			{
				archivoCliente<<x.getCodCliente()<<";"<<x.getNomCliente()<<";"<<x.getApeCliente()<<";"<<x.getDniCliente()<<";"<<endl;
			}
		}
		archivoCliente.close();
	}
	catch(exception e)
	{
		cout<<"Ocurrio un error al Grabar Cliente";
	}
}
void ClienteController::cargarDatosDelArchivo()
{
	try
	{
		int i;
		size_t posi;
		string linea;
		string temporal[4];
		fstream archivoCliente;
		archivoCliente.open("cliente.csv",ios::in);
		
		if(archivoCliente.is_open())
		{
			while(!archivoCliente.eof() && getline(archivoCliente,linea))
			{
				i=0;
				while((posi=linea.find(";")) !=string ::npos)
				{
					temporal[i]=linea.substr(0,posi);
					linea.erase(0,posi+1);
					i++;
				}
				Cliente objClie;
				
				objClie.setCodCliente(std::stoi(temporal[0]));
				objClie.setNomCliente(temporal[1]);
				objClie.setApeCliente(temporal[2]);
				objClie.setDniCliente(temporal[3]);

				
				add(objClie);
				
			}
		}
		archivoCliente.close();
	}
	
	catch(exception e)
	{
		cout<<"Ocurrio un error al momento de Leer Cliente";
	}
}
