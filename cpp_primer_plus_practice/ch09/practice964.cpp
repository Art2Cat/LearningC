#include "sales.h"

using namespace SALES;

int main() {
	Sales s2017;
	Sales s2018 ;

	double sales[QUARTERS] = {21.2,123.2,223.2,41.21};
	setSales(s2017, sales, QUARTERS);
	showSales(s2017);
	setSales(s2018);
	showSales(s2018);
	return 0;
}
