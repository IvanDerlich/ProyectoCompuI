#include <iostream>
#include <map> 
#include "Site.h"

using namespace std;
/*
NPG:Navegacion 	Parametrizacion Gastos
APG:Accion	Parametrizacion Gastos
*/

void Site::page_parametrizacion_gastos(MAP &Post, MyConnection conn){

	cout << "<p>Parametrizacion de Gastos:</p>"<<endl;
	//sustitucion
	/*
	//debugging
	  cout << "<p> APG: "<<Post["APG"] <<" </p>" <<endl;
	  cout << "<p> NPG: "<<Post["NPG"] <<" </p>" <<endl;
	  cout << "<p> itemCategoriaGasto.id: "<<Post["itemCategoriaGasto.id"] <<" </p>" <<endl;
	  cout << "<p> itemCategoriaGasto.nombre: "<<Post["itemCategoriaGasto.nombre"] <<" </p>" <<endl;
	  cout << "<p> itemCategoriaGasto.descripcion: "<<Post["itemCategoriaGasto.descripcion"] <<" </p>" <<endl;
	  cout << "<p> itemCategoriaGasto.porcentaje: "<<Post["itemCategoriaGasto.porcentaje"] <<" </p>" <<endl;
	//cout << "<p> variable: "<<Post["variable"] <<" </p>" <<endl;
	cout << "<hr>" << endl;
	*/
	//se puede hacer una funcion que permita el debugging segun el tipo de elemento
	
	cout << "<form method='POST'>"<<endl;
	string query;
	string id,nombre,descripcion,porcentaje;
	try{
		if(Post["NPG"] == ""){
			//sustitucion
			id = Post["itemCategoriaGasto.id"];
			nombre = Post["itemCategoriaGasto.nombre"];
			descripcion = Post["itemCategoriaGasto.descripcion"];
			porcentaje = Post["itemCategoriaGasto.porcentaje"];
			//algun metodo que reciba Post y devuelva el elemento creado. El metodo puede ser de la clase elementoCategoriaIngreso

			//sustitucion
			if(Post["APG"]=="update"){
				query = "UPDATE CategoriasGasto SET nombre = '" + nombre + "', descripcion = '" + descripcion + "', porcentaje='"+  porcentaje +"'  WHERE IdCategoriaGasto=" + id + ";";
			}if(Post["APG"]=="delete"){
				query = "DELETE FROM CategoriasGasto WHERE idCategoriaGasto='" + id + "';";
			}else if(Post["APG"]=="insert"){
				query = "INSERT INTO `CategoriasGasto` (`nombre`, `descripcion`, porcentaje) VALUES ('" + nombre + "', '" + descripcion +"', '" + porcentaje + "');";
			}if(Post["APG"]!=""){
				//cout << "<p>DEBUGING: query a ejecutar: ["<<query<<"]</p>" << endl;
				conn.execute(query);
			}
			//por algun metodo que reciba la conexion, la variable APG y el elemento y que toma la accion correspondiente. ¿Que devolveria el metodo?¿La query?¿Un estado del resultado de la ejecucion? El metodo seria de la clase ¿CategoriaIngresoDAO? 

			query = "SELECT * FROM CategoriasGasto ORDER BY nombre asc";
			sql::ResultSet *res = conn.query(query);
			//sustitucion
			cout << "<hr><p>(Nombre,\t Descripcion, Porcentaje,id)</p><hr>" << endl;//cuando haga bien la capa de abstraccion, esta instruccion tiene que ir despues del while
			while (res->next()){
				id=		res->getString("idCategoriaGasto");
				nombre=		res->getString("nombre");
				descripcion=	res->getString("descripcion");
				porcentaje=	res->getString("porcentaje");
				//new element_itemCategoriaGasto(res); se podria hacer asi
				cout << "<input type='radio' name='itemCategoriaGasto.id' value='"<< id <<"' checked='checked' >\t\t(" << nombre << "\t,"<< descripcion << ",\t"<< porcentaje <<" %,\t"<< id << " )<hr>";
			}
			//ver si \t sirve de algo, ver tambien si existe un tab para html
			//el loop de arriba se podria usar para rellenar una queue de elementos de tipo generico que se alimenta de un resultset y devuelve un ¿?. Una vez llenado, se mostraria a traves de un metodo de la clase queue que los muestre segun el tipo de elemento ¿funcion sobrecargada?
			delete res;
			//sustitucion
			cout << "<input type='radio' name='NPG' value='update'checked='checked'>UPDATE" << endl;//NPG = Navegacion Parametrizacion Gastos
			cout << "<input type='radio' name='NPG' value='delete'>DELETE" << endl;
			cout << "<input type='radio' name='NPG' value='insert'>INSERT" << endl;
			//--navegacion: metodo de objeto de clase Site denominacion: UDIradio (UPDATE, DELETE, INSERT)
		}else if(Post["NPG"]=="delete"){
			//sustitucion
			query = "select * from CategoriasGasto where idCategoriaGasto = "+Post["itemCategoriaGasto.id"]+";";
			//DEBUGGING//cout << "<p>query: "<< query <<"</p>" << endl;
			sql::ResultSet *res = conn.query(query);
			res->next();
			id		=res->getString("idCategoriaGasto");
			nombre		=res->getString("nombre");
			descripcion	=res->getString("descripcion");
			porcentaje	=res->getString("porcentaje");
			//un metodo que se alimente de in ID traigo a traves de post y que devuelva un elemento. El metodo seria de una clase que se llame ElementItemCategoriaGasto. Su nombre seria 

			cout << "<p>¿Desea eliminar el siguiente elemento?</p><br>" <<endl;
			//sustitucion
			cout << "<p>(ID,\t\t\t Nombre,\t Descripcion)</p>" << endl;
			cout << "<p>("<< id <<","<< nombre <<","<< descripcion  <<","<< porcentaje  <<")</p>";
			cout << "<input type='hidden' name='itemCategoriaGasto.id' value='"<< id <<"'>" <<endl;
			//las lineas de arriba se podrian sustituir por un metodo "show" o algo asi del elemento que trae la sustitucion de mas arriba
			delete res;
			//navegacion
			cout << "<input type='hidden' name='APG' value='delete'>" <<endl;
		}else if(Post["NPG"] == "insert" || Post["NPG"]=="update"){
			if(Post["NPG"]=="update"){
				//sustitucion
				query = "select * from CategoriasGasto where idCategoriaGasto = "+Post["itemCategoriaGasto.id"]+";";
				//cout << "<p>query: "<< query <<"</p>" << endl;
				sql::ResultSet *res = conn.query(query);
				res->next();
				id=		res->getString("idCategoriaGasto");
				nombre=		res->getString("nombre");
				descripcion=	res->getString("descripcion");
				porcentaje=	res->getString("porcentaje");
				//new element_itemCategoriaGasto(res); se podria hacer asi
				cout << "<input type='hidden' name='itemCategoriaGasto.id' value='"<< id <<"'>" << endl;
				//navegacion
				cout << "<input type='hidden' name='APG' value='update'>" <<endl;
			}if(Post["NPG"]=="insert"){
				//navegacion
				cout << "<input type='hidden' name='APG' value='insert'>" <<endl;
			}
			cout << "<br><label>Nombre</label>" << endl;
			cout << "<input type='text' name='itemCategoriaGasto.nombre' value='"<< nombre <<"'>"<<endl;
			cout << "<br><label>Descripcion</label>" << endl;
			cout << "<input type='text' name='itemCategoriaGasto.descripcion' value='"<< descripcion <<"'>"<<endl;
			cout << "<br><label>Porcentaje</label>" << endl;
			cout << "<input type='text' name='itemCategoriaGasto.porcentaje' value='"<< porcentaje <<"'>"<<endl;

		}else{page_error("error en parametrizacion gastos");}
		//navegacion
		cout << "<input type='hidden' name='navegacion' value='Parametrizacion'> "<<endl;
		cout << "<input type='hidden' name='parametrizacion' value='Categoria Gastos'> "<<endl;
		cout << "<hr>" << endl;
		cout << "<input type='submit' value='Proceder'>" << endl;
		//navegacion: Sustitur por una funcion de una clase categoriaGastosViewer . El metodo se puede llamar navegacion_proceder o algo asi
		cout << "</form>"<< endl;
	} catch (sql::SQLException &e) {
		cout << "<p># ERR: SQLException in " << __FILE__<< "</p>";
		cout << "<p>(" << __FUNCTION__ << ") on line "<< __LINE__ << "</p>"<< endl;
		cout << "<p># ERR: " << e.what()<< "</p>";
		cout << "<p> (MySQL error code: " << e.getErrorCode()<< "</p>";
		cout << "<p>, SQLState: " << e.getSQLState() << " )"<< "</p>" << endl;
	}
}
