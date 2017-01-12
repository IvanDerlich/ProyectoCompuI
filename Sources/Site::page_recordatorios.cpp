#include <iostream>
#include "Site.h"

using namespace std;

void Site::page_recordatorios(){
	this->headerCGI();
	this->menu_principal();
	cout << "		<p>Estoy en la pagina de Recordatorio</p>"<<endl;
	this->footerCGI();
}
