#include <iostream>
#include "Site.h"

using namespace std;

void Site::page_parametrizacion(){
	this->headerCGI();
	this->menu_principal();
	cout << "		<p>Estoy en la pagina de Parametrizacion</p>"<<endl;
	this->footerCGI();
}
