#include <iostream>
#include "Site.h"

using namespace std;

void Site::page_inicio(){
	this->headerCGI();
	this->menu_principal();
	cout << "		<p>Estoy en la pagina de Inicio</p>"<<endl;
	this->footerCGI();
}
