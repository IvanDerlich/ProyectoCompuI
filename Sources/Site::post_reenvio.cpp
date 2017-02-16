#include <iostream>
#include "Site.h"

using namespace std;

void Site::post_reenvio(MAP &Post){
	cout << "<input type='hidden' name='navegacion' 	value='"<< Post["navegacion"] 	<< "'>" << endl;
	cout << "<input type='hidden' name='flujo' 		value='"<< Post["flujo"]  		<< "'>" << endl;
	//cout << "<input type='hidden' name='parametrizacion' 	value='"<< Post["parametrizacion"]  	<< "'>" << endl;
	//cout << "<input type='hidden' name='prueba' 		value='"<< Post["prueba"]  		<< "'>"	<< endl;

}
