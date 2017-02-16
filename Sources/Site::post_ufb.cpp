#include <iostream>
#include "Site.h"

using namespace std;

void Site::post_ufb(string variable, string valor, MAP &Post){//ufb: Update Form Button
	cout << "<form method='POST'>" << endl;
	this->post_reenvio(Post);
	cout << "<input type='hidden' name='"<< variable <<"' value='"<< valor << "'>" << endl;
	cout << "<input type='submit' value='"<< valor << "'>" << endl;
	cout << "</form>"<< endl;

}
