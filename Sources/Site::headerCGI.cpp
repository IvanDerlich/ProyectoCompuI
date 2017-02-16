#include <iostream>
#include "Site.h"

using namespace std;

void Site::headerCGI(MAP &Post){
		cout << "Content-type: text/html" << endl << endl;
		cout << "<html>" << endl;
		cout << "	<head>" << endl;
		cout << "		<link href='http://localhost/css/bootstrap.min.css' rel='stylesheet'>" << endl;
		cout << "		<link href='http://localhost/css/signin.css' rel='stylesheet'>" << endl;
		cout << "		<link href='http://localhost/css/ejemplo.css' rel='stylesheet'>" << endl;
		cout << "	</head>" << endl;	
		cout << "	<body>" <<endl;
		this->menu_principal(Post);
}
