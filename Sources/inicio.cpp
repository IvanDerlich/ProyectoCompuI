#include <iostream>

using namespace std;

void inicio(){
		cout << "Content-type: text/html" << endl << endl;
		cout << "<html>" << endl;
		cout << "	<head>" << endl;
		cout << "		<link href='http://localhost/css/bootstrap.min.css' rel='stylesheet'>" << endl;
		cout << "		<link href='http://localhost/css/signin.css' rel='stylesheet'>" << endl;
		cout << "		<link href='http://localhost/css/ejemplo.css' rel='stylesheet'>" << endl;
		cout << "	</head>" << endl;
		cout << "	<body>" <<endl;
		cout << "		<form method='POST'>" << endl;
		cout << "			<input type='hidden' name=\"navegacion\" value='prueba'>" << endl;
		cout << "			<input type='submit' value='Prueba'>" << endl;
		cout << "		</form>"<< endl;
		cout << "	</body>" << endl;
		cout << "</html>" << endl;
}