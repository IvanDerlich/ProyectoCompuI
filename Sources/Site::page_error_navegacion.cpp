#include <iostream>
#include "Site.h"

using namespace std;

void Site::page_error_navegacion(){
	this->headerCGI();
	this->menu_principal();
	cout << "		<p>Error de navegacion</p>"<<endl;
	cout << "		<p>Post[\"navegacion\"] carece de un valor entendible</p>"<<endl;
	cout << "		<p>Post[\"navegacion\"]: "<<this->get_navegacion()<<"</p>"<<endl;
	this->footerCGI();
}
