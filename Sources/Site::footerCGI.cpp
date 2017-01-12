#include <iostream>
#include "Site.h"

using namespace std;

void Site::footerCGI(){
	cout << "	</body>" << endl;
	cout << "</html>" << endl;
}
