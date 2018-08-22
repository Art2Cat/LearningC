#ifndef __SALES_H__
#define __SALES_H__

namespace SALES {
	const int QUARTERS = 4;
	struct Sales {
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};

	void setSales(Sales &s, const double arr[], int n);

	void setSales(Sales &s);

	void showSales(const Sales &s);
} // namespace SALES
#endif
