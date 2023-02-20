#include "fecha.h"

Fecha::Fecha()
{
	
}

void Fecha::funcion()
{
	string resultado;
	time_t t;
	t = time(NULL);
	struct tm* fecha;
	fecha = localtime(&t);
	cout	<< "Fecha de Emision: " << fecha->tm_mday << "-" << fecha->tm_mon + 1 << "-" << fecha->tm_year + 1900 << "\t"
		<< "Hora: " << fecha->tm_hour << ":" << fecha->tm_min<< endl;
	
}
