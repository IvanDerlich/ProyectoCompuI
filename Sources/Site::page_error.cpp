#include <iostream>
#include "Site.h"

using namespace std;

void Site::page_error(string error){
	cout << "<p>Error: "<< error <<"</p>"<<endl;
}
