#include <iostream>
#include "Site.h"

using namespace std;

void Site::page_listas(){
	this->headerCGI();
	this->menu_principal();
	cout << "		<p>Estoy en la pagina de Listas de supermercado</p>"<<endl;
	this->footerCGI();
}
