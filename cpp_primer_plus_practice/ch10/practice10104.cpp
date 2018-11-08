#include "sales.h"

using namespace SALES;

int main() {
	const double sales[QUARTERS] = {21.2,123.2,223.2,41.21};
	Sales s2017( sales, QUARTERS);
	s2017.show();

	Sales s2018 ;
	s2018.show();
	s2018.init();
	s2018.show();

	s2018.setSales(sales, QUARTERS);
	s2018.show();

	return 0;
}
