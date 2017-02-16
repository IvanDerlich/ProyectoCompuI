#include <iostream>
#include "Site.h"

using namespace std;

void Site::menu_flujo(MAP &Post){
	//cout << "<hr>"<<endl;
	post_ufb("flujo", "Ingresos",Post);
	post_ufb("flujo", "Gastos",Post);
}
