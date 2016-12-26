#include "usuariocontroller.h"
#include "usuarioviewer.h"
#include "usuariodao.h"
#include "myconnection.h"

UsuarioController::UsuarioController()
{
    //ctor
}

UsuarioController::~UsuarioController()
{
    //dtor
}

void UsuarioController::abm()
{
//	eliminar();
	 listar();

}

void UsuarioController::listar()
{

    (new UsuarioViewer())->listar((new UsuarioDAO())->collection());
}

void UsuarioController::eliminar()
{
	Usuario* usuario = new Usuario();
	usuario->setId(11);
	(new UsuarioDAO())->del(usuario);
}

