#include <iostream>
#include "Site.h"

using namespace std;

Site::Site(){
	//default ctor
}
void Site::set_navegacion(string value){
	this->navegacion = value;
}
string Site::get_navegacion(){
	return this->navegacion;
}

void Site::set_flujo(string value){
	this->flujo = value;
}
string Site::get_flujo(){
	return this->flujo;
}

