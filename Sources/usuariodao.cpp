#include "usuariodao.h"
#include "myconnection.h"
#include <sstream>

UsuarioDAO::UsuarioDAO()
{
    //ctor
}

UsuarioDAO::~UsuarioDAO()
{
    //dtor
}

Queue* UsuarioDAO::collection()
{
    Queue* queue = new Queue();
    sql::ResultSet* res = MyConnection::instance()->query("SELECT * FROM usuarios ORDER BY usuario ASC");
    while (res->next())
        queue->qstore(new Usuario(res));

    delete res;

    return queue;
}

void UsuarioDAO::del(Usuario* usuario)
{
    string stringSQL;
    stringstream ss;
    ss << usuario->getId();

    stringSQL = "DELETE FROM usuarios WHERE id = " + ss.str();
    MyConnection::instance()->execute(stringSQL);
}

void UsuarioDAO::save(Usuario* Usuario)
{
    if (exist(Usuario))
        update(Usuario);
    else
        add(Usuario);
}

bool UsuarioDAO::exist(Usuario* Usuario)
{
    string stringSQL;

    stringstream ss;
    ss << Usuario->getId();

    stringSQL = "SELECT * FROM usuarios WHERE id = " + ss.str();
    sql::ResultSet* res = MyConnection::instance()->query(stringSQL);

    return res->next();
}

void UsuarioDAO::update(Usuario* Usuario)
{
    string stringSQL;

    stringstream ss;
    ss << Usuario->getId();

    stringSQL = "UPDATE usuarios SET usuario = '" + Usuario->getUsuario() + "' WHERE id = " + ss.str();
    MyConnection::instance()->execute(stringSQL);
}

void UsuarioDAO::add(Usuario* Usuario)
{
    stringstream ss;

    string stringSQL;

    ss << Usuario->getId();

    stringSQL = "INSERT INTO usuarios (id, usuario) VALUES (" + ss.str() + ", '" + Usuario->getUsuario() + "')";
    MyConnection::instance()->execute(stringSQL);
}

Usuario* UsuarioDAO::find(int id)
{
    string stringSQL;

    stringstream ss;
    ss << id;

    stringSQL = "SELECT * FROM usuarios WHERE id = " + ss.str();

    sql::ResultSet* res = MyConnection::instance()->query(stringSQL);

    if (res->next())
    {
        Usuario* usuario = new Usuario(res);
        delete res;
        return usuario;
    }

    delete res;
    return new Usuario();
}

