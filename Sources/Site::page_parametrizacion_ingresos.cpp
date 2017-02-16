#include <iostream>
#include <map> 
#include "Site.h"

using namespace std;
/*
NPI:Navegacion 	Parametrizacion Ingresos
API:Accion	Parametrizacion Ingresos
*/

void Site::page_parametrizacion_ingresos(MAP &Post, MyConnection conn){

	cout << "<p>Parametrizacion de Ingresos:</p>"<<endl;
	/*//debugging
	cout << "<p> API: "<<Post["API"] <<" </p>" <<endl;
	cout << "<p> NPI: "<<Post["NPI"] <<" </p>" <<endl;
	cout << "<p> itemCategoriaIngreso.id: "<<Post["itemCategoriaIngreso.id"] <<" </p>" <<endl;
	cout << "<p> itemCategoriaIngreso.nombre: "<<Post["itemCategoriaIngreso.nombre"] <<" </p>" <<endl;
	cout << "<p> itemCategoriaIngreso.descripcion: "<<Post["itemCategoriaIngreso.descripcion"] <<" </p>" <<endl;
	//cout << "<p> variable: "<<Post["variable"] <<" </p>" <<endl;
	cout << "<hr>" << endl;
	*/
	cout << "<form method='POST'>"<<endl;
	string query;
	try{
		if(Post["NPI"] == ""){
			if(Post["API"]=="update"){
				query = "UPDATE CategoriasIngreso SET nombre = '"+Post["itemCategoriaIngreso.nombre"]+"', descripcion = '"+Post["itemCategoriaIngreso.descripcion"]+"' WHERE IdCategoriaIngreso="+ Post["itemCategoriaIngreso.id"]+";";
			}if(Post["API"]=="delete"){
				query = "DELETE FROM CategoriasIngreso WHERE idCategoriaIngreso='" + Post["itemCategoriaIngreso.id"] + "';";
			}else if(Post["API"]=="insert"){
				query = "INSERT INTO `CategoriasIngreso` (`nombre`, `descripcion`) VALUES ('" + Post["itemCategoriaIngreso.nombre"] + "', '" + Post["itemCategoriaIngreso.descripcion"] + "');";
			}if(Post["API"]!=""){
				//cout << "<p>DEBUGING: query a ejecutar: ["<<query<<"]</p>" << endl;
				conn.execute(query);
			}
			query = "SELECT * FROM CategoriasIngreso ORDER BY nombre asc";
			sql::ResultSet *res = conn.query(query);
			cout << "<hr><p>(Nombre,\t Descripcion)</p><hr>" << endl;
			while (res->next())
				cout << "<input type='radio' name='itemCategoriaIngreso.id' value='"<< res->getInt("idCategoriaIngreso") <<"' checked='checked' >\t\t(" << res->getString("nombre") << ",\t"<< res->getString("descripcion") << ")<hr>";
			delete res;
			//navegacion
			cout << "<input type='radio' name='NPI' value='update'checked='checked'>UPDATE" << endl;//NPI = Navegacion Parametrizacion Ingresos
			cout << "<input type='radio' name='NPI' value='delete'>DELETE" << endl;
			cout << "<input type='radio' name='NPI' value='insert'>INSERT" << endl;
		}else if(Post["NPI"]=="delete"){
			query = "select * from CategoriasIngreso where idCategoriaIngreso = "+Post["itemCategoriaIngreso.id"]+";";
			cout << "<p>¿Desea eliminar el siguiente elemento?</p><br>" <<endl;
			//cout << "<p>query: "<< query <<"</p>" << endl;
			cout << "<p>(ID,\t\t\t Nombre,\t Descripcion)</p>" << endl;
			sql::ResultSet *res = conn.query(query);
			res->next();
			cout << "<p>("<< res->getInt("idCategoriaIngreso") <<","<< res->getString("nombre") <<","<< res->getString("descripcion")  <<")</p>";
			cout << "<input type='hidden' name='itemCategoriaIngreso.id' value='"<< Post["itemCategoriaIngreso.id"] <<"'>" <<endl;
			delete res;
			//navegacion
			cout << "<input type='hidden' name='API' value='delete'>" <<endl;
		}else if(Post["NPI"] == "insert" || Post["NPI"]=="update"){
			string nombre,descripcion;
			if(Post["NPI"]=="update"){
				query = "select * from CategoriasIngreso where idCategoriaIngreso = "+Post["itemCategoriaIngreso.id"]+";";
				//cout << "<p>query: "<< query <<"</p>" << endl;
				sql::ResultSet *res = conn.query(query);
				res->next();
				nombre=res->getString("nombre");
				descripcion=res->getString("descripcion");
				cout << "<input type='hidden' name='itemCategoriaIngreso.id' value='"<< Post["itemCategoriaIngreso.id"] <<"'>" << endl;
				//navegacion
				cout << "<input type='hidden' name='API' value='update'>" <<endl;
			}if(Post["NPI"]=="insert"){
				//navegacion
				cout << "<input type='hidden' name='API' value='insert'>" <<endl;
			}
			cout << "<br><label>Nombre</label>" << endl;
			cout << "<input type='text' name='itemCategoriaIngreso.nombre' value='"<< nombre <<"'>"<<endl;
			cout << "<br><label>Descripcion</label>" << endl;
			cout << "<input type='text' name='itemCategoriaIngreso.descripcion' value='"<< descripcion <<"'>"<<endl;
		}else{/*Error de navegacion*/}
		//navegacion
		cout << "<input type='hidden' name='navegacion' value='Parametrizacion'> "<<endl;
		cout << "<input type='hidden' name='parametrizacion' value='Categoria Ingresos'> "<<endl;
		//navegacion
		cout << "<hr>" << endl;
		cout << "<input type='submit' value='Proceder'>" << endl;
		cout << "</form>"<< endl;
	} catch (sql::SQLException &e) {
		cout << "<p># ERR: SQLException in " << __FILE__<< "</p>";
		cout << "<p>(" << __FUNCTION__ << ") on line "<< __LINE__ << "</p>"<< endl;
		cout << "<p># ERR: " << e.what()<< "</p>";
		cout << "<p> (MySQL error code: " << e.getErrorCode()<< "</p>";
		cout << "<p>, SQLState: " << e.getSQLState() << " )"<< "</p>" << endl;
	}
}
