#include "Site.h"

using namespace std;

void Site::menu_principal(){
	ir("Inicio");

	ir("Listas");//Lista de listas, despues uno accede a cada lista a traves de la pagina Items

	ir("Recordatorios");//Veo todos los recordatorios y cada recordatorio individualmente

	ir("Flujo");//Flujo de dinero donde puedo ir a Ingresos y Gastos

	ir("Parametrizacion");
}
