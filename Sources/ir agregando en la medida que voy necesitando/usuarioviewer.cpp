#include "usuarioviewer.h"
#include <iostream>

using namespace std;

UsuarioViewer::UsuarioViewer()
{
    //ctor
}

UsuarioViewer::~UsuarioViewer()
{
    //dtor
}


void UsuarioViewer::listar(Queue* queue)
{
	cout<<"Content-type: text/html"<<endl<<endl;
	cout<<"<html><head>"<<endl;
	cout<<"<link href='http://localhost/css/bootstrap.min.css' rel='stylesheet'>"<<endl;
	cout<<"<link href='http://localhost/css/signin.css' rel='stylesheet'>"<<endl;
	cout<<"<link href='http://localhost/css/ejemplo.css' rel='stylesheet'>"<<endl;
	cout << "</head>" <<endl;
	cout << "<body>   <div class='container'>"<<endl;
	cout<<"<div class='centrar'></div>"<<endl;
	cout<<"<div>"<<endl;
	cout<<"</div>"<<endl;
	queue->show();
	cout<<"</div></body></html>"<<endl;


}

/*int UsuarioViewer::buscar()
{
    int cliID;

    cout << endl << endl << "Buscar Usuario" << endl;
    cout << "Ingrese ID Usuario: ";
    cin >> cliID;

    return cliID;
}
*/
/*
void UsuarioViewer::mostrar(Usuario* id)
{

}

void UsuarioViewer::cargar(Usuario* cl, string msg)
{
}*/

