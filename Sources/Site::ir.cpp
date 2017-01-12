#include <iostream>
#include "Site.h"

using namespace std;

void Site::ir(string direccion){
	cout << "		<form method='POST'>" << endl;
	cout << "			<input type='hidden' name=\"navegacion\" value='"<< direccion << "'>" << endl;
	cout << "			<input type='submit' value='"<< direccion << "'>" << endl;
	cout << "		</form>"<< endl;
}
