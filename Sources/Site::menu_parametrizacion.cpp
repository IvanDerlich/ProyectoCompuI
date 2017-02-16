#include <iostream>
#include "Site.h"

using namespace std;

void Site::menu_parametrizacion(MAP &Post){
	//cout << "<hr>"<<endl;
	post_ufb("parametrizacion", "Categoria Ingresos",Post);
	post_ufb("parametrizacion", "Categoria Gastos",Post);
}
