#include "Site.h"

using namespace std;

void Site::menu_principal(MAP &Post){
	post_ufb("navegacion","Inicio",Post);

	post_ufb("navegacion","Listas",Post);//Lista de listas, despues uno accede a cada lista a traves de la pagina Items

	post_ufb("navegacion","Recordatorios",Post);//Veo todos los recordatorios y cada recordatorio individualmente

	post_ufb("navegacion","Flujo",Post);//Flujo de dinero donde puedo post_ufb a Ingresos y Gastos

	post_ufb("navegacion","Parametrizacion",Post);

	cout << "<hr>"<<endl;
	//DEBUGGING
	//this->show_post(Post);
}
