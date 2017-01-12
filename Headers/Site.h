#ifndef __SITE_H__
#define __SITE_H__
#include <string>

using namespace std;

class Site{
	private:
		string navegacion;
		string flujo;
	protected:
	public:
		//flujo
		void set_flujo(string value);
		string get_flujo();
		//navegacion
		void set_navegacion(string value);
		string get_navegacion();

		Site();//Constructor

		void footerCGI();
		void headerCGI();
		void ir(string direccion);
		void menu_principal();
		void page_error_navegacion();

		void page_flujo();
		void page_inicio();
		void page_listas();
		void page_parametrizacion();
		void page_prueba();
		void page_recordatorios();
};

#endif /*__SITE_H__*/
