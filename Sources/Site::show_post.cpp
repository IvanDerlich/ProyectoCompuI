#include <iostream>

#include "Site.h"

using namespace std;

void Site::show_post(MAP &Post){
	//imprime todas las variables post y sus respectivos valores
	cout<<"Debugging info:"<< endl;
	cout<<"<p>navegacion: 		"<< Post["navegacion"]<<"</p>"<<endl;
	cout<<"<p>flujo: 		"<< Post["flujo"]<<"</p>"<<endl;
	cout<<"<p>parametrizacion: 	"<< Post["parametrizacion"]<<"</p>"<<endl;
	cout << "<hr>"<<endl;
}
