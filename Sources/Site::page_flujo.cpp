#include <iostream>
#include "Site.h"

using namespace std;

void Site::page_flujo(){
	this->headerCGI();
	this->menu_principal();
	cout << "		<p>Estoy en la pagina de Flujo de dinero</p>"<<endl;
	this->footerCGI();
}
