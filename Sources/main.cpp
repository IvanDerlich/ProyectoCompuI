//#include "usuariocontroller.h"
#include <iostream>

#include "getpost.h"
#include "Site.h"

using namespace std;

int main (int argc, char* const argv[]) {

	map <string, string> Post;
	initializePost(Post);
	Site site;
	site.set_navegacion(Post["navegacion"]); 
	site.set_flujo(Post["flujo"]);

	if(site.get_navegacion() ==  "Inicio" || site.get_navegacion() == ""){
		site.page_inicio();
	}else if(site.get_navegacion() == "Listas"){
		site.page_listas();
	}else if(site.get_navegacion() == "Recordatorios"){
		site.page_recordatorios();
	}else if(site.get_navegacion() == "Flujo"){
		if(site.get_flujo == "")		{site.page_flujo();}
		else if(site.get_flujo == "Ingresos")	{/*Ingresos*/}
		else if(site.get_flujo == "Gastos")	{/*Gastos*/}
		else {/*Error de navegacion*/}
	}else if(site.get_navegacion() == "Parametrizacion"){
		site.page_parametrizacion();
	}else{//Error de navegacion 
		site.page_error_navegacion();
	}
	return 0;
}
