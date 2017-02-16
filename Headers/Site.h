#ifndef __SITE_H__
#define __SITE_H__

#define MAP std::map <std::string, std::string>
#include <string>
#include <map>
#include <myconnection.h>

using namespace std;

class Site{
	private:
	protected:
	public:
		Site();//Constructor

		void footerCGI(MAP &Post);
		void headerCGI(MAP &Post);
		void menu_flujo(MAP &Post);
		void menu_parametrizacion(MAP &Post);
		void menu_principal(MAP &Post);
		void page_error(string error);

		void page_flujo();
		void page_flujo_gastos();
		void page_flujo_ingresos();
		void page_inicio();
		void page_listas();
		void page_parametrizacion();
		void page_parametrizacion_ingresos(MAP &Post, MyConnection conn);
		void page_parametrizacion_gastos(MAP &Post, MyConnection conn);
		void page_recordatorios();

		void post_ufb(string variable,string valor,MAP &Post);
		void post_reenvio(MAP &Post);
		void show_post(MAP &Post);
};

#endif /*__SITE_H__*/
