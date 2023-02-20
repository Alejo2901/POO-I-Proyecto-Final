//Carpetas Extraidas
//libreria MD5
#include "../model/fecha.cpp"
#include "../controller/usuarioController.h"
#include "../controller/clienteController.h"
#include "../controller/vendedorController.h"
#include "../controller/categoriaController.h"
#include "../controller/productoController.h"
#include "../controller/ventaController.h"
#include "../controller/detalle_ventaController.h"

//Librerias
#include <iostream>
#include <conio.h>//activar el [.getch()] del lenguaje C
#include <stdio.h>
#include <windows.h>
#include <algorithm>
#include <iomanip>
using namespace std;

//Controller
UsuarioController usuController;
ClienteController cliController;
VendedorController vendController;
CategoriaController cateController;
ProductoController prodController;
VentaController ventController;
Detalle_VentaController deta_venController;

//MENU 
void menuInicio();

//MENU ADMINISTRADOR
void menuAdmin();
void loginAdmin();
void loginUsuario();
void addNewUsuario();

//Menu de Inicio
void menuOpciones();

//MENU CLIENTE
void menuCliente();
void addCliente();
void buscarCliente();
void eliminarCliente();
void modificarCliente();
void listarCliente();

//MENU VENDEDOR
void menuVendedor();
void addVendedor();
void buscarVendedor();
void eliminarVendedor();
void modificarVendedor();
void listarVendedor();

//MENU PRODUCTO
void menuProducto();
void addProducto();
void buscarProducto();
void eliminarProducto();
void modificarProducto();
void listarProducto();
void categoria();
//Venta
void generaVenta();

//marco
void limite();
void gotoxy(int,int);

//Fecha
void fecha();

int main(int argc, char *argv[]) 
{
	menuInicio();
	return 0;
}
//MENU DE INICIO
void menuInicio()
{
	
	int opt;
	do
	{
		fecha();
		limite();
		gotoxy(24,10);
		cout<<"--MENU PRINCIPAL-------------\n";
		gotoxy(24,11);
		cout<<"--Ingresar----------------[1]\n";
		gotoxy(24,12);
		cout<<"--Agregar-----------------[2]\n";
		gotoxy(24,13);
		cout<<"--Salir-------------------[3]\n";
		gotoxy(24,14);
		cout<<"--Ingresar Opcion[1-3]:";
		cin>>opt;
		switch(opt)
		{  
			
		case 1:system("cls");loginUsuario();break;			
		case 2:system("cls");addNewUsuario();break;
		case 3:system("cls");limite();gotoxy(10,13);cout<<"\t#####Gracias por usar nuestro servicio#####\n\n\n\n\n\n\n\n\n\n";break;
		default:system("cls");limite();gotoxy(10,13);cout<<"\t\tIngrese una opcion valida[1-3]\n\n\n\n\n\n\n\n\n\n\n";system("PAUSE");system("cls");
		}
		
		
	} while(opt!=3);
	
}

//MENU ADMINISTRADOR
void menuAdmin()
{
	
	int opt;
	do
	{
		fecha();
		limite();
		gotoxy(10,10);
		cout<<"\t\t--MENU ADMINISTRADOR-------\n";
		cout<<"\t\t\t--AGREGAR NEW USUARIO-----[1]\n";
		cout<<"\t\t\t--CLIENTE-----------------[2]\n";
		cout<<"\t\t\t--PRODUCTOS---------------[3]\n";
		cout<<"\t\t\t--GENERAR VENTA-----------[4]\n";
		cout<<"\t\t\t--SALIR-------------------[5]\n";
		cout<<"\t\t\t--Ingresar Opcion[1-5]:";
		cin>>opt;
		switch(opt)
		{  
		case 1:system("cls");addNewUsuario();break;
		case 2:system("cls");menuCliente();break;
		case 3:system("cls");menuProducto();break;
		case 4:system("cls");break;
		case 5:system("cls");cout<<"\n\n\n\t#####Gracias por usar nuestro servicio#####\n\n\n";break;
		default:system("cls");limite();gotoxy(10,13);cout<<"Ingrese una opcion valida[1-3]";gotoxy(10,24);system("PAUSE");system("cls");
		}
		system("cls");
	} while(opt!=5);
}
//ADMIN


//CREAR NUEVO USUARIO
void loginUsuario()
{
	fecha();
	limite();
	gotoxy(10,10);
	string usuario; 
	string contra;
	char caracter;
	bool ingresa = false;
	cout<<"\t\tIngrese su usuario: ";
	
	cin>>usuario;
	cout<<"\t\t\tIngrese su contraseña: ";
	caracter=getch();
	while(caracter !=13)
	{
		contra.push_back(caracter);
		cout<<"*";
		caracter=getch();
	}
	for(int i=0; i<usuController.size();i++)
	{
		string encrip;
		
		encrip=sha256(contra);
		
		if(usuController.get(i).getUsuario()==usuario && usuController.get(i).getContra() == encrip)
		{
			ingresa = true; 
			break;
		}
		
	}
	
	if(!ingresa)
	{
		
		system("cls");
		limite();gotoxy(10,13);cout<<"\tEl usuario o la contraseña son incorrectos intento # \n\n";gotoxy(10,24);
		system("PAUSE");
		system("cls");
		
	}
	
	else
	{
		
		system("cls");
		gotoxy(10,7);cout<<"\n\t\t\t\tBienvenido\n\n";
		gotoxy(10,10);menuOpciones();
		
	}
	
}
void addNewUsuario()
{
	
	string usuario;
	string cont;
	string flag;
	
	do
	{
		fecha();
		limite();
		gotoxy(10,10);
		cout<<"\t\tUsuario:";
		cin>>usuario;
		
		cout<<"\t\t\tContraseña:";
		cin.ignore();
		
		char caracter;
		
		caracter=getch();
		
		while(caracter !=13)
		{
			cont.push_back(caracter);
			cout<<"*";
			caracter=getch();
		}
		
		//Creacion de Objetos
		Usuario objUsu(usuario,cont);
		
		//Creacion de Objeto Arreglo
		usuController.add(objUsu);
		
		//Graba en el Archivo
		usuController.grabarEnArchivo(objUsu);
		
		system ("cls");
		fecha();
		limite();
		gotoxy(10,10);
		addVendedor();
		cout<<"\n\t\t\tCONTINUAR[S/N]:";
		cin>>flag;
		
		system("cls");
	} while(flag=="S"||flag=="s");
}


//MENU DE PRINCIPAL
void menuOpciones()
{
	
	int opt;
	do
	{
		fecha();
		limite();
		gotoxy(10,10);
		cout<<"\t\t--MENU DE USUARIO----------\n";
		cout<<"\t\t\t--CLIENTE----------------[1]\n";
		cout<<"\t\t\t--PRODUCTOS--------------[2]\n";
		cout<<"\t\t\t--GENERAR VENTA----------[3]\n";
		cout<<"\t\t\t--Salir------------------[4]\n";
		cout<<"\t\t\t--Ingresar Opcion[1-4]:";
		cin>>opt;
		switch(opt)
		{ 

		case 1:system("cls");menuCliente();break;
		case 2:system("cls");menuProducto();break;
		case 3:system("cls");generaVenta();break;
		case 4:system("cls");cout<<"\n\n\n\t\t#####Gracias por usar nuestro servicio#####\n\n\n";break;
		default:system("cls");limite();gotoxy(10,13);cout<<"\t\tIngrese una opcion valida[1-4]";gotoxy(10,24);system("PAUSE");system("cls");
		}
		
	} while(opt!=4);
	system("cls");
	
}
void adicionar()
{
	string usuario;
	string cont;
	string flag;
	
	do
	{
		fecha();
		limite();
		gotoxy(10,10);
		cout<<"\t\tUsuario:";
		cin>>usuario;
		
		cout<<"\t\t\tContraseña:";
		cin.ignore();
		
		char caracter;
		
		caracter=getch();
		
		while(caracter !=13)
		{
			cont.push_back(caracter);
			cout<<"*";
			caracter=getch();
		}
		
		//Creacion de Objetos
		Usuario objUsu(usuario,cont);
		
		//Creacion de Objeto Arreglo
		usuController.add(objUsu);
		
		//Graba en el Archivo
		usuController.grabarEnArchivo(objUsu);
		
		cout<<"\n\t\t\tCONTINUAR[S/N]:";
		cin>>flag;
		
		system("cls");
	} while(flag=="S"||flag=="s");
	
	
}

//MENU CLIENTE
void menuCliente()
{
	int opt;
	do
	{
		fecha();
		limite();
		gotoxy(10,10);
		cout<<"\t\t--MENU DE CLIENTES--------\n";
		cout<<"\t\t\t--Agregar----------------[1]\n";
		cout<<"\t\t\t--Buscar-----------------[2]\n";
		cout<<"\t\t\t--Eliminar---------------[3]\n";
		cout<<"\t\t\t--Modificar--------------[4]\n";
		cout<<"\t\t\t--Listar-----------------[5]\n";
		cout<<"\t\t\t--Salir------------------[6]\n";
		cout<<"\t\t\t--Ingresar Opcion[1-6]:";
		cin>>opt;
		switch(opt)
		{  
		case 1:system("cls");addCliente();break;
		case 2:system("cls");buscarCliente();break;
		case 3:system("cls");eliminarCliente();break;
		case 4:system("cls");modificarCliente();break;
		case 5:system("cls");listarCliente();break;
		case 6:system("cls");cout<<"\n\n\n\t\t#####Gracias por usar nuestro servicio#####\n\n\n";break;
		default:system("cls");limite();gotoxy(10,13);cout<<"\t\tIngrese una opcion valida[1-6]";gotoxy(10,24);system("PAUSE");system("cls");
		}
		
	} while(opt!=6);
	system("cls");
}
void addCliente()
{
	int codCliente;
	string nomCliente;
	string apeCliente;
	string dniCliente;
	
	string flag;
	
	do
	{
		fecha();
		limite();
		gotoxy(10,5);
		cout<<"\n\t\t\tINGRESE LOS DATOS DEL Cliente\n";
		codCliente=cliController.getCorrelativo();
		cout<<"\n\t\t\tCODIGO:"<<"[ C-0" <<codCliente<<" ]\n";
		cin.ignore();
		cout<<"\n\t\t\tIngrese Nombre: ";
		getline(cin,nomCliente);
		cin.ignore();
		cout<<"\n\t\t\tIngrese Apellido: ";
		getline(cin,apeCliente);
		cout<<"\n\t\t\tIngrese DNI: ";
		cin>>dniCliente;
		
		//Creacion de Objetos
		Cliente objCli(codCliente,nomCliente,apeCliente,dniCliente);
		//Creacion de Objeto Arreglo
		cliController.add(objCli);
		//Graba en el Archivo
		cliController.grabarEnArchivo(objCli);
		
		cout<<"\n\t\t\tCONTINUAR[S/N]:";
		cin>>flag;
		
		system("cls");
	} while(flag=="S"||flag=="s");
}
void buscarCliente()
{
	fecha();
	
	limite();
	gotoxy(10,13);
	int codigoBuscar;
	cout<<"\t\tIngrese Codigo a Buscar:C-0";
	cin>>codigoBuscar;
	system("cls");
	limite();
	gotoxy(10,10);
	Cliente obj = cliController.buscarPorCodigo(codigoBuscar);
	
	
	if(obj.getNomCliente()=="error")
	{	
		fecha();
		
		gotoxy(10,10);
		cout<<"\n\n\n\t\t\tEl codigo Ingresado no Existe!!!\n\n\n\n\n\n\n\n\n\n\n";
		system("pause");
		system("cls");
	}
	else
	{
		fecha();
		cout<<"\n\t\t\tREGISTRO ENCONTRADO\n\n\n";
		cout<<"\n\t\t\tCODIGO DEL CLIENTE: C-0"<<obj.getCodCliente();
		cout<<"\n\t\t\tNOMBRE DEL CLIENTE: "<<obj.getNomCliente();
		cout<<"\n\t\t\tAPELLIDO DEL CLIENTE: "<<obj.getApeCliente();
		cout<<"\n\t\t\tDNI DEL CLIENTE: "<<obj.getDniCliente();
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		system("pause");
	}	
	
	system("cls");
}
void eliminarCliente()
{
	fecha();
	limite();
	gotoxy(10,10);
	int cod;
	cout<<"\n\n\n\t\t\tINGRESAR EL CODIGO A ELIMINAR:  C-0";
	cin>>cod;
	system("cls");
	limite();
	gotoxy(10,10);
	Cliente objEliminar = cliController.buscarPorCodigo(cod);
	
	if(objEliminar.getNomCliente() !="error")
	{
		fecha();
		gotoxy(10,10);
		cliController.remove(objEliminar);
		cout<<"\n\n\n\t\t\tREGISTRO ELIMINADO SATISFACTORIAMENTE\n\n\n\n\n\n\n\n\n\n\n";
		cliController.grabarModificarEliminarArchivo();
		system("pause");
	}
	else
	{
		fecha();
		gotoxy(10,10);
		cout<<"\n\n\n\t\t\tNo se encontro el Registro!!!";
		cout<<"\n\n\n\n\n\n\n\n\n\n\n";
		system("pause");
	}
	system("cls");
}
void modificarCliente()
{
	fecha();
	limite();
	gotoxy(10,4);
	int cod;
	cout<<"\n\n\t\t\tIngresar el codigo a modificar: C-0";
	cin>>cod;
	Cliente objModificar= cliController.buscarPorCodigo(cod);
	cout<<"\n\n\t\t\tREGISTRO ENCONTRADO\n\n\n";
	cout<<"\t\t\tCODIGO: C-0"<<objModificar.getCodCliente();
	cout<<"\n\n\t\t\tNOMBRE: "<<objModificar.getNomCliente();
	cout<<"\n\n\t\t\tAPELLIDO: "<<objModificar.getApeCliente();
	cout<<"\n\n\t\t\tDNI: "<<objModificar.getDniCliente();
	cout<<"\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	system("cls");
	
	string nomModificado;
	string apeModificado;
	string dniModificar;
	fecha();
	limite();
	gotoxy(10,7);
	cout<<"\n\t\t\t\tMODIFICAR CLIENTE\n";
	cin.ignore();
	cout<<"\n\t\t\tMODIFICAR NOMBRE: ";getline(cin,nomModificado);
	cin.ignore();
	cout<<"\n\t\t\tMODIFICAR APELLIDO: ";getline(cin,apeModificado);
	
	cout<<"\n\t\t\tMODIFICAR DNI: ";cin>>dniModificar;
	
	cout<<"\n\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	
	
	bool estado = cliController.modificar(objModificar,cod,nomModificado,apeModificado,dniModificar);
	
	if(estado = true)
	{
		system("cls");
		fecha();
		limite();
		gotoxy(10,13);
		cout<<"\t\tREGISTRO MODIFICADO SATISFACTORIAMENTE";
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cliController.grabarModificarEliminarArchivo();
	}
	else
	{
		fecha();
		cout<<"\t\t\tNo se edito el Registro!!!\n";
		system("pause");
		
	}
	system("pause");
	system("cls");
	
	
}
void listarCliente()
{
	fecha();
	limite();
	gotoxy(6,6);
	cout<<"CODIGO\tNOMBRE\t\tAPELLIDO\tDNI\n";
	for(int i=0;i<cliController.size();i++)
	{
		
		cout<<"\t"<<cliController.get(i).getCodCliente()<<"\t"<<cliController.get(i).getNomCliente()<<"\t"<<cliController.get(i).getApeCliente()<<"\t"<<cliController.get(i).getDniCliente()<<"\t"<<endl;
		
		
	}
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	system("cls");
}
//MENU VENDEDOR
void menuVendedor()
{
	int opt;
	do
	{
		fecha();
		limite();
		gotoxy(10,10);
		cout<<"\t\t--MENU DE VENDEDORES--------\n";
		cout<<"\t\t\t--Agregar----------------[1]\n";
		cout<<"\t\t\t--Buscar-----------------[2]\n";
		cout<<"\t\t\t--Eliminar---------------[3]\n";
		cout<<"\t\t\t--Modificar--------------[4]\n";
		cout<<"\t\t\t--Listar-----------------[5]\n";
		cout<<"\t\t\t--Salir------------------[6]\n";
		cout<<"\t\t\t--Ingresar Opcion[1-6]:";
		cin>>opt;
		switch(opt)
		{  
		case 1:system("cls");addVendedor();break;
		case 2:system("cls");buscarVendedor();break;
		case 3:system("cls");eliminarVendedor();break;
		case 4:system("cls");modificarVendedor();break;
		case 5:system("cls");listarVendedor();break;
		case 6:system("cls");cout<<"\n\n\n\t\t#####Gracias por usar nuestro servicio#####\n\n\n";break;
		default:system("cls");limite();gotoxy(10,13);cout<<"\t\tIngrese una opcion valida[1-6]";gotoxy(10,24);system("PAUSE");system("cls");
		}
		
	} while(opt!=6);
	system("cls");
}
void addVendedor()
{
	int codVendedor;
	string nomVendedor,apeVendedor,dniVendedor,direVendedor;
	
	string flag;
	

		fecha();
		limite();
		gotoxy(10,5);
		cout<<"\n\t\tINGRESE LOS DATOS DEL VENDEDOR\n";
		codVendedor=vendController.getCorrelativo();
		cout<<"\n\t\t\tCODIGO:"<<"[ V-0" <<codVendedor<<" ]\n";
		cin.ignore();
		cout<<"\n\t\t\tIngrese Nombre: ";
		getline(cin,nomVendedor);
		cin.ignore();
		cout<<"\n\t\t\tIngrese Apellido: ";
		getline(cin,apeVendedor);
		cin.ignore();
		cout<<"\n\t\t\tIngrese DIRECION: ";
		getline(cin,direVendedor);
		cout<<"\n\t\t\tIngrese DNI: ";
		cin>>dniVendedor;		
		
		//Creacion de Objetos
		Vendedor objVen(codVendedor,nomVendedor,apeVendedor,direVendedor,dniVendedor);
		//Creacion de Objeto Arreglo
		vendController.add(objVen);
		//Graba en el Archivo
		vendController.grabarEnArchivo(objVen);
		
	
}
void buscarVendedor()
{
	
	fecha();
	limite();
	gotoxy(10,13);
	int codigoBuscar;
	
	cout<<"\t\tIngrese Codigo a Buscar: ";
	cin>>codigoBuscar;
	
	system("cls");
	limite();
	gotoxy(10,10);
	Vendedor obj = vendController.buscarPorCodigo(codigoBuscar);
	
	if(obj.getNomVendedor()=="error")
	{
		fecha();		
		gotoxy(10,10);
		cout<<"\n\n\n\n\t\t\tEl codigo Ingresado no Existe!!!\n\n\n\n\n\n\n\n\n\n\n";
		system("pause");
		system("cls");
	}
	else
	{
		fecha();
		gotoxy(10,10);
		cout<<"\t\t\tREGISTRO ENCONTRADO DEL VENDEDOR\n";
		cout<<"\n\t\t\tCODIGO :"<<obj.getCodVendedor();
		cout<<"\n\t\t\tNOMBRE :"<<obj.getNomVendedor();
		cout<<"\n\t\t\tAPELLIDO:"<<obj.getApeVendedor();
		cout<<"\n\t\t\tDIRECCION:"<<obj.getDireVendedor();
		cout<<"\n\t\t\tDNI:"<<obj.getDniVendedor();
		cout<<"\n\n\n\n\n\n\n\n";
		system("pause");
	}	
	
	system("cls");
}
void eliminarVendedor()
{
	fecha();
	limite();
	gotoxy(10,10);
	int cod;
	cout<<"\n\n\n\t\t\tINGRESAR EL CODIGO A ELIMINAR:";
	cin>>cod;
	system("cls");
	limite();
	gotoxy(10,10);
	Vendedor objEliminar = vendController.buscarPorCodigo(cod);
	
	if(objEliminar.getNomVendedor() !="error")
	{
		fecha();
		
		vendController.remove(objEliminar);
		cout<<"\n\n\n\t\t\tREGISTRO ELIMINADO SATISFACTORIAMENTE\n\n\n\n\n\n\n\n\n\n\n";
		vendController.grabarModificarEliminarArchivo();
		system("pause");
	}
	else
	{
		fecha();
		gotoxy(10,10);
		cout<<"\n\n\n\t\t\tNo se encontro el Registro!!!";
		cout<<"\n\n\n\n\n\n\n\n\n\n\n";
		system("pause");
	}
	system("cls");
}
void modificarVendedor()
{
	fecha();
	limite();
	gotoxy(10,4);
	int cod;
	cout<<"\n\n\t\t\tIngresar el codigo a modificar:";
	cin>>cod;
	Vendedor objModificar= vendController.buscarPorCodigo(cod);
	cout<<"\n\n\t\t\tREGISTRO ENCONTRADO\n\n\n";
	cout<<"\t\t\tCODIGO:"<<objModificar.getCodVendedor();
	cout<<"\n\n\t\t\tNOMBRE: "<<objModificar.getNomVendedor();
	cout<<"\n\n\t\t\tAPELLIDO: "<<objModificar.getApeVendedor();
	cout<<"\n\n\t\t\tDIRECCION: "<<objModificar.getDireVendedor();
	cout<<"\n\n\t\t\tDNI: "<<objModificar.getDniVendedor();
	cout<<"\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	system("cls");
	
	string nomModificado;
	string apeModificado;
	string dniModificar;
	string direModificar;
	fecha();
	limite();
	gotoxy(10,7);
	cout<<"\n\t\t\t\tMODIFICAR PRODUCTO\n";
	cout<<"\n\t\t\tMODIFICAR NOMBRE: ";cin>>nomModificado;
	cout<<"\n\t\t\tMODIFICAR APELLIDO: ";cin>>apeModificado;
	cout<<"\n\t\t\tMODIFICAR DIRECCION: ";cin>>direModificar;
	cout<<"\n\t\t\tMODIFICAR DNI: ";cin>>dniModificar;
	
	cout<<"\n\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	
	
	bool estado = vendController.modificar(objModificar,cod,nomModificado,apeModificado,direModificar,dniModificar);
	
	if(estado = true)
	{
		system("cls");
		fecha();
		limite();
		gotoxy(10,13);
		cout<<"\t\tREGISTRO MODIFICADO SATISFACTORIAMENTE";
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		vendController.grabarModificarEliminarArchivo();
	}
	else
	{
		fecha();
		cout<<"\t\t\tNo se edito el Registro!!!\n";
		system("pause");
		
	}
	system("pause");
	system("cls");
	
}
void listarVendedor()
{
	fecha();
	limite();
	gotoxy(6,6);
	cout<<"CODIGO\tNOMBRE\t\tAPELLIDO\tDIRECCION\t    DNI\n";
	for(int i=0;i<vendController.size();i++)
	{
		
		cout<<"\t"<<vendController.get(i).getCodVendedor()<<"\t"<<vendController.get(i).getNomVendedor()<<"\t"<<vendController.get(i).getApeVendedor()<<"\t"<<vendController.get(i).getDireVendedor()<<"\t    "<<vendController.get(i).getDniVendedor()<<"\t"<<endl;
		
	}
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	system("cls");
}


//MENU PRODUCTOS
void menuProducto()
{
	int opt;
	do
	{
		fecha();
		limite();
		gotoxy(10,10);
		cout<<"\t\t--MENU DE PRODUCTOS-------\n";
		cout<<"\t\t\t--Agregar----------------[1]\n";
		cout<<"\t\t\t--Buscar-----------------[2]\n";
		cout<<"\t\t\t--Eliminar---------------[3]\n";
		cout<<"\t\t\t--Modificar--------------[4]\n";
		cout<<"\t\t\t--Listar-----------------[5]\n";
		cout<<"\t\t\t--Salir------------------[6]\n";
		cout<<"\t\t\t--Ingresar Opcion[1-6]:";
		cin>>opt;
		switch(opt)
		{  
		case 1:system("cls");addProducto();break;
		case 2:system("cls");buscarProducto();break;
		case 3:system("cls");eliminarProducto();break;
		case 4:system("cls");modificarProducto();break;
		case 5:system("cls");listarProducto();break;
		case 6:system("cls");cout<<"\n\n\n\t\t#####Gracias por usar nuestro servicio#####\n\n\n";break;
		default:system("cls");limite();gotoxy(10,13);cout<<"\t\tIngrese una opcion valida[1-6]";gotoxy(10,24);system("PAUSE");system("cls");
		}
		
	} while(opt!=6);
	system("cls");
}
void addProducto()
{
	int codPro;
	int cantPro;
	string desPro;
	string nomPro;
	float costo;
	string flag;
	
	do
	{
		fecha();
		limite();
		gotoxy(10,4);
		cout<<"\n\n\t\t\tINGRESE LOS DATOS DEL PRODUCTO\n";
		codPro=prodController.getCorrelativo();
		cout<<"\n\t\t\tCODIGO:"<<"[ " <<codPro<<" ]\n";
		cout<<"\t\t\tIngrese nombre del Producto: ";
		cin>>nomPro;
		cout<<"\t\t\tIngrese descripcion del Producto: ";
		cin>>desPro;
		cout<<"\t\t\tIngrese Precio del Producto: ";
		cin>>costo;
		cout<<"\t\t\tIngrese Cantidad del Producto: ";
		cin>>cantPro;
		
		categoria();
		//Creacion de Objetos
		Producto objPro(codPro,nomPro,desPro,costo,cantPro);
		
		//Creacion de Objeto Arreglo
		prodController.add(objPro);
		
		//Graba en el Archivo
		prodController.grabarEnArchivo(objPro);
		
		
		cout<<"\t\t\tCONTINUAR[S/N]:";
		cin>>flag;
		
		system("cls");
	} while(flag=="S"||flag=="s");
}
void categoria()
{
	int codCate;
	string nomCate;
	cout<<"\n\n\t\t\t*******CATEGORIAS*********\n";
	cout<<"\n\t\t\t[1]PRODUCTOS DE ESCRITORIO";
	cout<<"\n\t\t\t[2]PRODUCTOS TECNOLOGIA";
	cout<<"\n\t\t\tElige una categoria: ";
	cin>>codCate;
	
	Categoria objCate(codCate,nomCate);
	
}
void buscarProducto()
{
	fecha();
	limite();
	gotoxy(10,13);
	int codigoBuscar;
	
	cout<<"\t\tIngrese Codigo a Buscar: P-0";
	cin>>codigoBuscar;
	
	system("cls");
	limite();
	gotoxy(10,10);
	Producto obj = prodController.buscarPorCodigo(codigoBuscar);
	
	if(obj.getNombrePro()=="error")
	{
		fecha();		
		gotoxy(10,10);
		cout<<"\n\n\n\n\t\t\tEl codigo Ingresado no Existe!!!\n\n\n\n\n\n\n\n\n\n\n";
		system("pause");
		system("cls");
	}
	else
	{
		fecha();
		gotoxy(10,10);
		cout<<"\t\t\tREGISTRO ENCONTRADO\n";
		cout<<"\n\t\t\tCODIGO DEL PRODUCTO: P-0"<<obj.getCodigoPro();
		cout<<"\n\t\t\tNOMBRE DEL PRODUCTO:"<<obj.getNombrePro();
		cout<<"\n\t\t\tDESCRIPCION DEL PRODUCTO:"<<obj.getDescriPro();
		cout<<"\n\t\t\tPRECIO DEL PRODUCTO:"<<obj.getCostoPro();
		cout<<"\n\t\t\tCANTIDAD DEL PRODUCTO:"<<obj.getCantPro();
		cout<<"\n\n\n\n\n\n\n\n";
		system("pause");
	}	
	
	system("cls");
	
}
void eliminarProducto()
{
	fecha();
	limite();
	gotoxy(10,10);
	int cod;
	cout<<"\n\n\n\t\t\tINGRESAR EL CODIGO A ELIMINAR:";
	cin>>cod;
	system("cls");
	limite();
	gotoxy(10,10);
	Producto objEliminar = prodController.buscarPorCodigo(cod);
	if(objEliminar.getNombrePro() !="error")
	{
		fecha();
		gotoxy(10,10);
		prodController.remove(objEliminar);
		cout<<"\n\n\n\t\t\tREGISTRO ELIMINADO SATISFACTORIAMENTE\n\n\n\n\n\n\n\n\n\n\n";
		prodController.grabarModificarEliminarArchivo();
		system("pause");
	}
	else
	{
		fecha();
		gotoxy(10,10);
		cout<<"\n\n\n\t\t\tNo se enconctro el Registro!!!";
		cout<<"\n\n\n\n\n\n\n\n\n\n\n";
		system("pause");
	}
	system("cls");
}
void modificarProducto()
{
	fecha();
	limite();
	gotoxy(10,5);
	int cod;
	cout<<"\n\t\t\tIngresar el codigo a modificar: P-0";
	cin>>cod;
	Producto objModificar= prodController.buscarPorCodigo(cod);
	
	cout<<"\n\n\n\t\t\tREGISTRO ENCONTRADO\n\n\n";
	cout<<"\t\t\tCODIGO: P-0"<<objModificar.getCodigoPro();
	cout<<"\n\t\t\tNOMBRE:"<<objModificar.getNombrePro();
	cout<<"\n\t\t\tDESCRIPCION:"<<objModificar.getDescriPro();
	cout<<"\n\t\t\tCOSTO:"<<objModificar.getCostoPro();
	cout<<"\n\t\t\tCANTIDAD:"<<objModificar.getCantPro();
	
	
	
	
	cout<<"\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	system("cls");
	
	
	string nomModificado;
	string descriModificado;
	float costoModificar;
	int cantModificar;
	
	fecha();
	
	limite();
	gotoxy(10,4);
	cout<<"\n\n\t\t\t\tMODIFICAR PRODUCTO\n";
	cout<<"\n\t\t\tMODIFICAR NOMBRE:";cin>>nomModificado;
	cout<<"\n\t\t\tMODIFICAR DESCRIPCION:";cin>>descriModificado;
	cout<<"\n\t\t\tMODIFICAR COSTO:";cin>>costoModificar;
	cout<<"\n\t\t\tMODIFICAR CANTIDAD:";cin>>cantModificar;
	cout<<"\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	
	
	bool estado = prodController.modificar(objModificar,cod,nomModificado,descriModificado,costoModificar,cantModificar);
	
	if(estado = true)
	{
		system("cls");
		fecha();
		gotoxy(10,10);
		limite();
		gotoxy(10,13);
		cout<<"\t\tREGISTRO MODIFICADO SATISFACTORIAMENTE";
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		prodController.grabarModificarEliminarArchivo();
	}
	else
	{
		fecha();
		gotoxy(10,10);
		cout<<"\t\t\tNo se edito el Registro!!!\n";
		system("pause");
		
	}
	system("pause");
	system("cls");
	
}
void listarProducto()
{
	fecha();
	gotoxy(10,10);
	limite();
	gotoxy(10,6);
	cout<<"CODIGO\tNOMBRE\t\tDESCRIPCION\tCOSTO\tCANTIDAD\n";
	for(int i=0;i<prodController.size();i++)
	{
		
		cout<<"\t    "<<prodController.get(i).getCodigoPro()<<"\t\t"<<prodController.get(i).getNombrePro()<<"\t\t"<<prodController.get(i).getDescriPro()<<"\t\t "<<prodController.get(i).getCostoPro()<<"\t  "<<prodController.get(i).getCantPro()<<endl;
		
		
	}
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	system("cls");
}
void generaVenta()
{
	int cantidaPro;
	string flag, arg, busqPro, nombreCli, nombrePro,codPro;
	int cod, cantidad,codVenta;
	float total;
	fecha();
	gotoxy(10,10);
	
	limite();
	gotoxy(10,6);
	
	cout << "\t\t\tCODIGO VENTA ( V-0"<<ventController.getCorrelativo()<<" )"<<endl;
	cin.ignore();
	cout << "\n\n\n\t\t\tNombre del cliente: ";
	getline(cin,nombreCli);
	
	Cliente objCli = cliController.buscarPorNombre(nombreCli);
	cout << "\n\n\t\t\tDNI: " << objCli.getDniCliente()<<endl;
	cout << "\n\n\t\t\tCodigo Cliente: C-0"<<objCli.getCodCliente()<<endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	system("cls");
	
	Detalle_Venta objDetVen;
	
	if(objCli.getNomCliente()=="error")
	{	
		fecha();
		limite();
		gotoxy(10,10);
		cout<<"\n\n\n\t\t\tEl Cliente no Existe!!!\n\n\n\n\n\n\n\n\n\n\n";
		system("pause");
		system("cls");
	}
	else
	{
		
		string cant;
		string grow;
		do
		{
			fecha();
			gotoxy(10,10);
			
			limite();
			gotoxy(10,6);
			
			cout << "\t\t\tGENERANDO VENTA\n";
			cout << "\t\t\t\t----------------\n";
			
			cin.ignore();
		
			system("cls");
			
			fecha();
			gotoxy(10,10);
			
			limite();
			gotoxy(10,6);
			
			
			do
			{
				cout << "\n\t\t\tNombre de Producto: ";
				
				
				cin >> codPro;
				Producto objPro = prodController.buscarPorNombre(codPro);
				
				if (objPro.getNombrePro() != "ERROR")
				{
					cout << "\n\t\t\t*** SE ANADIO A SU CARRITO ***\n\n";
					cout << "\t\tCODIGO\t\tPRODUCTO\t\tPRECIO\n\t";
					
					cout << "\tP-0" <<objPro.getCodigoPro() 
						<< "\t\t"<< objPro.getNombrePro()
						<< "\t\t\t" << objPro.getCostoPro() << endl;
				}
				else
				{
					cout << "\t\t\tNO SE ENCONTRO EL PRODUCTO\n"; break;
				}
				
				cout << "\n\t\tCANTIDAD: "; 
				cin >> cantidad;
				
				
				
				cout<<"\n\n\t\t\tContinuar(S/N):";
				cin>>grow;
				
				
				objDetVen.setCodDetVenta(ventController.getCorrelativo());
				
				objDetVen.setCantDetVenta(cantidad);
				
				
				objDetVen.setPreDetVenta(objPro.getCostoPro());
				
				total=objPro.getCostoPro()*cantidad;
				
				
			
				
				
				
			}while(grow=="S"||grow=="s");
			
			
			
			
		
	
			
			
			deta_venController.add(objDetVen);
			deta_venController.getPostArray(objDetVen);
			
			cout << "\n\n\t\t\tDesea continuar?(S/N): ";
			cin >> flag;
			system("cls");
			
		} while (flag == "S" || flag == "s");
		
		deta_venController.grabarEnArchivo(objDetVen);
		
		Venta objVen;
		objVen.setCodVenta(ventController.getCorrelativo());
		objCli.setCodCliente(cod);
		codVenta=ventController.getCorrelativo();
		
		
		objVen.setTotVenta(total);
		fecha();
		gotoxy(10,10);
		
		limite();
		gotoxy(10,6);
		cout << "\t\t******** BOLETA ********\n\n";
		
		cout << "\t\tCODIGO: V-0" << codVenta << endl;
		cout << "\t\tDNI: " << objCli.getDniCliente() << endl;
		cout << "\t\tCLIENTE: " << objCli.getNomCliente() << " " << objCli.getApeCliente() << endl;
		
		
		cout << "\n\tCOD\t\tNOMBRE\t\tCANT\t\tSUBTOTAL\n"; 
		
		float importeTotal=0;
		
		
		
	
		
		for (int i = 0; i < prodController.size(); i++)
		{
			cout	<< "\tP-0" << prodController.get(i).getCodigoPro()
					<<"\t\t" << prodController.get(i).getNombrePro()  
					<<"\t\t " << cantidad
					<<"\t\t " << total
					<<"\n"; 
			
		}
		importeTotal = total + importeTotal;
		
		
		
		
		
		
		
		
		
		
		
		
		cout<<"\n\t\t___________________________________\n";
		
		cout<<"\t\tIMPORTE TOTAL S/: \t"<<importeTotal;
		
		cout<<"\n\n\n\n\n\n\n\n\n\n";
		
		
		
		ventController.add(objVen);
	
	}
	system("pause");
	system("cls");
	
	
	
	
}


//MARCO
void gotoxy(int x,int y)
{  
	HANDLE hcon;  
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
	COORD dwPos;  //cordenadas 
	dwPos.X = x;  
	dwPos.Y= y;  
	SetConsoleCursorPosition(hcon,dwPos);  
} 

void limite()
{
	for(int i=2;i<78;i++)
	{
		gotoxy(i,3);printf("%c",205);
		gotoxy(i,23);printf("%c",205);
	}
	
	for(int i=4;i<23;i++)
	{
		gotoxy(2,i);printf("%c",186);
		gotoxy(77,i);printf("%c",186);
	}
	gotoxy(2,3);printf("%c",201);
	gotoxy(2,23);printf("%c",200);
	gotoxy(77,3);printf("%c",187);
	gotoxy(77,23);printf("%c",188);
}


//Fecha
void fecha()
{
	//FECHA
	Fecha objFecha;
	
	gotoxy(4,4);
	objFecha.funcion();
}
