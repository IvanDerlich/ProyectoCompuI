#ifndef USUARIODAO_H
#define USUARIODAO_H

#include "usuario.h"
#include "queue.h"

class UsuarioDAO
{
    public:
        UsuarioDAO();
        virtual ~UsuarioDAO();
        void add(Usuario*);
        void update(Usuario*);
        bool exist(Usuario*);
        void save(Usuario*);
        void del(Usuario*);
        Usuario* find(int);
        Queue* collection();

    protected:
    private:
};

#endif // UsuarioDAO_H
