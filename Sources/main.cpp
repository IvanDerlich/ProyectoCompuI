//#include "usuariocontroller.h"
#include <iostream>

#include "getpost.h"

#define INICIO 1
#define PRUEBA 2

using namespace std;


void prueba(){
		cout << "Content-type: text/html" << endl << endl;
		cout << "<html>" << endl;
			cout << "	<head>" << endl;
		cout << "		<link href='http://localhost/css/bootstrap.min.css' rel='stylesheet'>" << endl;
		cout << "		<link href='http://localhost/css/signin.css' rel='stylesheet'>" << endl;
		cout << "		<link href='http://localhost/css/ejemplo.css' rel='stylesheet'>" << endl;
		cout << "	</head>" << endl;	
		cout << "	<body>" <<endl;
		cout << "		<form method='POST'>" << endl;
		cout << "			<input type='hidden' name=\"navegacion\" value='inicio'>" << endl;
		cout << "			<input type='submit' value='Inicio'>" << endl;
		cout << "		</form>"<< endl;
		cout << "	</body>" << endl;
		cout << "</html>" << endl;

}


int main (int argc, char* const argv[]) {

	map <string, string> Post;
	initializePost(Post);

	//(new UsuarioController())->abm();
	

	if( Post.find("navegacion") == Post.end() || Post["navegacion"] ==  "inicio" ){//pagina de inicio
		inicio();
	}else if(Post["navegacion"] ==  "prueba" ){//pagina de prueba
		prueba();
	}else{
		//explicar el error
	}
	return 0;
}
