#pragma once
#include"../model/usuario.cpp"

#include <vector>
#include <conio.h>
#include <fstream>
using namespace std;

class UsuarioController
{
private:
	vector<Usuario> vectorUsuario;

	
public:
	UsuarioController();
	void add(Usuario obj);
	Usuario get(int pos);
	int size();
	void grabarEnArchivo(Usuario obj);	
	void cargaEnArchivo();
	
	void grabarEnArchivoAdmin(Usuario obj);
	void cargaEnArchivoAdmin();
	
};
UsuarioController::UsuarioController()
{
	cargaEnArchivo();
}
void UsuarioController::add(Usuario obj)
{
	vectorUsuario.push_back(obj);//agregar nuevos elementos al vector
}
Usuario UsuarioController::get(int pos)
{
	return vectorUsuario[pos];
}
int UsuarioController::size()
{
	return vectorUsuario.size();
}
//GRABAR DATOS
void UsuarioController::grabarEnArchivo(Usuario obj)
{
	try
	{
		fstream archivoUsuario;
		archivoUsuario.open("usuario.bin",ios::app|ios::binary);
		if(archivoUsuario.is_open())
		{
			string encrip;
			encrip=sha256(obj.getContra());
			
			archivoUsuario<<obj.getUsuario()<<";"
				<<encrip<<";"<<endl;
		}

	

		
		archivoUsuario.close();
		
	}
	catch(exception e)
	{
		cout<<"Ocurrio un error al momento de grabar Usuario en el archivo";
	}
}
//REVISAR DATOS GRABADOS
void UsuarioController::cargaEnArchivo()
{
	try
	{
		int i;
		size_t posi;//Cantidad maxima
		string linea;
		string temporal[2];//Cantidad de columnas
		fstream archivoUsuario;
		archivoUsuario.open("usuario.bin", ios::in);
		
		
		
		if (archivoUsuario.is_open())
		{
			while (!archivoUsuario.eof() && getline(archivoUsuario, linea)) 
			{
				i = 0;
				while ((posi = linea.find(";")) != string::npos) 
				{/*string::npos es -1, termina cuando llega a este punto*/
					temporal[i] = linea.substr(0, posi);/*posi = Es la cantidad de caracteres antes del ;*/
					linea.erase(0, posi + 1);//borra la palabra de la primera posición encontrada   y con el +1 incluye hasta el ; y luego borra ese elemento, para que en la siguiente iteracion iniciar con la siguiente palabra y de ese modo seguir el proceso , 
					i++;
				}
				//Asignando los valores al vector
				Usuario objUsu;
				objUsu.setUsuario(temporal[0]);
				objUsu.setContra(temporal[1]);
				
				
				
				
				add(objUsu);
			}
		}
		archivoUsuario.close();
	}
	catch (exception e)
	{
		cout << "Ocurrio un error al leer el archivo";
	}
	
	
}

void UsuarioController::grabarEnArchivoAdmin(Usuario obj)
{
	try
	{
		fstream archivoUsuario;
		archivoUsuario.open("admin.bin",ios::app);
		if(archivoUsuario.is_open())
		{
			archivoUsuario<<obj.getUsuario()<<";"<<obj.getContra()<<";"<<endl;
		}
		
		archivoUsuario.close();
		
	}
	catch(exception e)
	{
		cout<<"Ocurrio un error al momento de grabar Usuario en el archivo";
	}
}
void UsuarioController::cargaEnArchivoAdmin()
{
	try
	{
		int i;
		size_t posi;//Cantidad maxima
		string linea;
		string temporal[2];//Cantidad de columnas
		fstream archivoUsuario;
		archivoUsuario.open("admin.bin", ios::in);
		if (archivoUsuario.is_open())
		{
			while (!archivoUsuario.eof() && getline(archivoUsuario, linea)) 
			{
				i = 0;
				while ((posi = linea.find(";")) != string::npos) 
				{
					/*string::npos es -1, termina cuando llega a este punto*/
					temporal[i] = linea.substr(0, posi);/*posi = Es la cantidad de caracteres antes del ;*/
					linea.erase(0, posi + 1);//borra la palabra de la primera posición encontrada   y con el +1 incluye hasta el ; y luego borra ese elemento, para que en la siguiente iteracion iniciar con la siguiente palabra y de ese modo seguir el proceso , 
					i++;
				}
				//Asignando los valores al vector
				Usuario objUsu;
				objUsu.setUsuario(temporal[0]);
				objUsu.setContra(temporal[1]);
				
				
				
				
				
				add(objUsu);
			}
		}
		archivoUsuario.close();
	}
	catch (exception e)
	{
		cout << "Ocurrio un error al leer el archivo";
	}
	
	
}



