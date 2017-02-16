//#include "usuariocontroller.h"
//
#define MAP std::map <std::string, std::string>
#define NAVEGACION Post["navegacion"]
#define FLUJO Post["flujo"]
#define PARAMETRIZACION Post["parametrizacion"]

#include <iostream>

#include "Site.h"
#include "getpost.h"

using namespace std;

int main (int argc, char* const argv[]) {

	map <string, string> Post;
	initializePost(Post);

	Site site;
	MyConnection conn;
	//conn.connect();
	site.headerCGI(Post);

	if(NAVEGACION ==  "Inicio" || NAVEGACION == ""){
		site.page_inicio();
	}else if(NAVEGACION == "Listas"){
		site.page_listas();
	}else if(NAVEGACION == "Recordatorios"){
		site.page_recordatorios();
	}else if(NAVEGACION == "Flujo"){
		site.menu_flujo(Post);
		if(FLUJO == "")		{site.page_flujo();}
		else if(FLUJO == "Ingresos")	{site.page_flujo_ingresos();}
		else if(FLUJO == "Gastos")	{site.page_flujo_gastos();}
		else {/*Error de navegacion*/}
	}else if(NAVEGACION == "Parametrizacion"){
		site.menu_parametrizacion(Post);
		if(PARAMETRIZACION == ""){site.page_parametrizacion();}
		else if(PARAMETRIZACION == "Categoria Gastos"){site.page_parametrizacion_gastos(Post, conn );}
		else if(PARAMETRIZACION == "Categoria Ingresos"){site.page_parametrizacion_ingresos( Post, conn);}
		else {/*Error de navegacion*/}
	}else{//Error de navegacion 
		site.page_error("error en main, parametrizacion");
	}
	//crear un metodo que envie todas las variables post
	site.footerCGI(Post);
	return 0;
}
